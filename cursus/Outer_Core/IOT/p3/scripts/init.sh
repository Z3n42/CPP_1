#!/bin/bash

set -e

echo ""
echo "=== ENVIRONMENT SETUP ==="

if [ -f .env ]; then
  echo "Loading environment variables from .env file..."
  set -o allexport
  source .env
  export ADMIN_MTIME="$(date -u +"%Y-%m-%dT%H:%M:%SZ")"
  set +o allexport
  echo ".env file loaded."
else
  echo "INFO: .env file not found. Using default script variables or expecting environment variables."
  exit 1
fi

echo ""
echo "=== ENVIRONMENT VALIDATION ==="

# Required secret envars
: "${USER_LOGIN:?Error: USER_LOGIN is required}"
: "${USER_PASS:?Error: USER_PASS is required}"
: "${GITHUB_USERNAME:?Error: GITHUB_USERNAME is required}"
: "${REPO_NAME:?Error: REPO_NAME is required}"
: "${WEBHOOK_SECRET:?Error: WEBHOOK_SECRET is required}"
: "${NGROK_AUTHTOKEN:?Error: NGROK_AUTHTOKEN is required}"
: "${NGROK_STATIC_DOMAIN:?Error: NGROK_STATIC_DOMAIN is required}"

# envars with default
IP=${IP:-192.168.57.10}
ARGOCD_PORT=${ARGOCD_PORT:-8080}
ARGOCD_HTTPS=${ARGOCD_HTTPS:-8443}
APP_PORT=${APP_PORT:-8888}
NODEPORT_HTTP=${NODEPORT_HTTP:-30080}
NODEPORT_HTTPS=${NODEPORT_HTTPS:-30443}
REPO_PATH=${REPO_PATH:-manifests}
MANIFEST_PATH=${MANIFEST_PATH:-/tmp/argocd-app.yaml}
ARGOCD_APP_NAME=${ARGOCD_APP_NAME:-iot-p3}
ARGOCD_NAMESPACE=${ARGOCD_NAMESPACE:-argocd}
SINC_TIME=${SINC_TIME:-180s}

# Validate IP format
if [[ ! "$IP" =~ ^([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])(\.([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])){3}$ ]]; then
    echo "Error: IP '$IP' is not in valid IPv4 format." >&2
    exit 1
fi

# Validate ports are numeric
for port_var in ARGOCD_PORT ARGOCD_HTTPS APP_PORT NODEPORT_HTTP NODEPORT_HTTPS; do
    port_value="${!port_var}"
    if [[ ! "$port_value" =~ ^[0-9]+$ ]] || [[ "$port_value" -lt 1025 ]] || [[ "$port_value" -gt 65535 ]]; then
        echo "Error: $port_var '$port_value' is not a valid port number (1025-65535)." >&2
        exit 1
    fi
done

echo "Starting automated K3d and Argo CD setup on Ubuntu..."

echo ""
echo "=== TLS CERTIFICATE GENERATION ==="

# 0. Generate TLS certificate for Argo CD
CERT_DIR="/tmp/argocd-tls"
CERT_KEY="$CERT_DIR/tls.key"
CERT_CRT="$CERT_DIR/tls.crt"
mkdir -p "$CERT_DIR"

if [ ! -f "$CERT_KEY" ] || [ ! -f "$CERT_CRT" ]; then
  echo "Generating self-signed TLS certificate for Argo CD..."
  openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout "$CERT_KEY" \
    -out "$CERT_CRT" \
    -subj "/CN=$IP"
else
  echo "TLS key and cert already exist, skipping generation."
fi

echo ""
echo "=== SYSTEM PREREQUISITES ==="

# 1. Update package lists and install prerequisites
echo "Updating package lists and installing prerequisites (curl, wget, gnupg, apt-transport-https)..."
sudo apt-get update
sudo apt-get install -y curl wget gnupg apt-transport-https ca-certificates lsb-release apache2-utils gettext

echo ""
echo "=== USER CREDENTIALS PROCESSING ==="

# 2. Generate and encode the Bcrypt Hash to Base64
if [ -z "$USER_LOGIN" ] || [ -z "$USER_PASS" ]; then
  echo "Error: Username and password cannot be empty."
  exit 1
fi
if [ -z "$WEBHOOK_SECRET" ]; then
  echo "Error: WebhookSecret cannot be empty."
  exit 1
fi
WEBHOOK_SECRET_B64=$(echo -n "$WEBHOOK_SECRET" | base64 -w0)
ADMIN_HASH=$(htpasswd -nbBC 10 placeholder_user "$USER_PASS" 2>/dev/null)
export ADMIN_HASH
if [ -z "$ADMIN_HASH" ]; then
  echo "Error: htpasswd did not generate output. Ensure apache2-utils is installed."
  exit 1
fi
PATCH_PASS=$(echo "$ADMIN_HASH" | cut -d: -f2 | sed 's/^\$2[yb]\$/\$2a\$/' | base64 -w0)
PATCH_MTIME=$(echo -n "$ADMIN_MTIME" | base64 -w0)
if [ -z "$PATCH_PASS" ]; then
  echo "Error: The hash for Argo CD is empty after processing."
  exit 1
fi
echo "User Credentials configured."

echo ""
echo "=== DOCKER INSTALLATION ==="

# 3. Install Docker
if ! command -v docker &> /dev/null
then
    echo "Installing Docker..."
    sudo install -m 0755 -d /etc/apt/keyrings
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
    sudo chmod a+r /etc/apt/keyrings/docker.gpg

    echo \
      "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
      $(. /etc/os-release && echo "$VERSION_CODENAME") stable" | \
      sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
    sudo apt-get update
    sudo apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
    sudo systemctl enable --now docker
    sudo usermod -aG docker $USER 
    echo "Docker installed. You may need to log out and log back in for group changes to take effect."
else
    echo "Docker is already installed."
fi

echo ""
echo "=== KUBECTL INSTALLATION ==="

# 4. Install kubectl
if ! command -v kubectl &> /dev/null
then
    echo "Installing kubectl..."
    VERSION=$(curl -L -s https://dl.k8s.io/release/stable.txt)
    curl -Lo /tmp/kubectl "https://dl.k8s.io/release/${VERSION}/bin/linux/amd64/kubectl"
    sudo install -o root -g root -m 0755 /tmp/kubectl /usr/local/bin/kubectl
    rm /tmp/kubectl
    echo "kubectl installed."
else
    echo "kubectl is already installed."
fi

echo ""
echo "=== K3D INSTALLATION ==="

# 5. Install K3d
if ! command -v k3d &> /dev/null
then
    echo "Installing K3d..."
    wget -q -O - https://raw.githubusercontent.com/k3d-io/k3d/main/install.sh | bash
    echo "K3d installed."
else
    echo "K3d is already installed."
fi

echo ""
echo "=== HELM INSTALLATION ==="

# 6. Install helm
if ! command -v helm &> /dev/null; then
    echo "Installing Helm..."
    curl https://baltocdn.com/helm/signing.asc | gpg --dearmor | sudo tee /usr/share/keyrings/helm.gpg > /dev/null
    sudo apt-get install apt-transport-https --yes
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/helm.gpg] https://baltocdn.com/helm/stable/debian/ all main" | sudo tee /etc/apt/sources.list.d/helm-stable-debian.list
    sudo apt-get update
    sudo apt-get install helm -y
    echo "Helm installed."
else
    echo "Helm is already installed."
fi

echo ""
echo "=== ARGOCD CLI INSTALLATION ==="

# 7. Install argocd-cli
ARGOCLI_PATH="/usr/local/bin/argocd"
if ! command -v argocd &> /dev/null; then
    echo "Argo CD CLI not found. Installing..."
    sudo curl -sSL -o "$ARGOCLI_PATH" "https://github.com/argoproj/argo-cd/releases/latest/download/argocd-linux-amd64"
    sudo chmod +x "$ARGOCLI_PATH"
    echo "Argo CD CLI installed successfully to $ARGOCLI_PATH"
else
    echo "Argo CD CLI is already installed."
fi

echo ""
echo "=== NGROK INSTALLATION ==="

# 8. Install ngrok
NGROK_INSTALL_PATH="/usr/local/bin/ngrok"
if ! command -v ngrok &> /dev/null; then
    echo "Ngrok not found. Installing..."
    NGROK_DOWNLOAD_URL="https://bin.equinox.io/c/bNyj1mQVY4c/ngrok-v3-stable-linux-amd64.tgz"
    TEMP_NGROK_FILE="/tmp/ngrok.tgz"
    
    echo "Downloading Ngrok from: $NGROK_DOWNLOAD_URL"
    if sudo curl -fsSL -o "$TEMP_NGROK_FILE" "$NGROK_DOWNLOAD_URL"; then
        echo "Ngrok downloaded. Attempting to extract..."
        if sudo tar -xvzf "$TEMP_NGROK_FILE" -C /usr/local/bin ngrok; then
            sudo chmod +x "$NGROK_INSTALL_PATH"
            echo "Ngrok installed successfully to $NGROK_INSTALL_PATH"
            ngrok version || echo "Ngrok version check failed after install."
        else
            echo "ERROR: Failed to extract Ngrok to $NGROK_INSTALL_PATH."
        fi
        sudo rm "$TEMP_NGROK_FILE"
    else
        echo "ERROR: Failed to download Ngrok."
    fi
else
    echo "Ngrok is already installed."
    ngrok version || echo "Existing ngrok installation might be corrupted or not in PATH correctly."
fi

echo ""
echo "=== NGROK CONFIGURATION ==="

# 9. Configure Ngrok Authtoken
if command -v ngrok &> /dev/null && [ -n "$NGROK_AUTHTOKEN" ]; then
    echo "Configuring Ngrok authtoken for user 'vagrant'..."
    if sudo -u vagrant HOME=/home/vagrant ngrok config add-authtoken "$NGROK_AUTHTOKEN"; then
        echo "Ngrok authtoken configured or updated for user 'vagrant'."
    else
        echo "ERROR: Failed to configure Ngrok authtoken for user 'vagrant'. Check permissions or token."
    fi
elif [ -z "$NGROK_AUTHTOKEN" ]; then
    echo "WARNING: NGROK_AUTHTOKEN not set in .env. Ngrok static domain and other features might not work."
fi

echo ""
echo "=== K3D CLUSTER CREATION ==="

# 10. Create K3d cluster
CLUSTER_NAME="p3"
if ! sudo k3d cluster get $CLUSTER_NAME &> /dev/null; then
    echo "Creating K3d cluster '$CLUSTER_NAME'..."
    sudo k3d cluster create $CLUSTER_NAME --api-port 6443 -p "8888:30088@agent:0" -p "8080:30080@loadbalancer" --agents 1
    echo "K3d cluster '$CLUSTER_NAME' created."
    echo "Waiting for cluster to be ready..."
    sleep 15
else
    echo "K3d cluster '$CLUSTER_NAME' already exists."
fi
sudo kubectl config use-context k3d-$CLUSTER_NAME

echo ""
echo "=== NAMESPACE CREATION ==="

# 11. Create namespaces for Argo CD and dev environment
echo "Creating 'argocd' and 'dev' namespaces..."
sudo kubectl create namespace argocd || echo "Namespace 'argocd' already exists."
sudo kubectl create namespace dev || echo "Namespace 'dev' already exists."

echo "Creating/updating argocd-server-tls secret..."
sudo kubectl delete secret argocd-server-tls -n "$ARGOCD_NAMESPACE" --ignore-not-found
sudo kubectl create secret tls argocd-server-tls \
  --cert="$CERT_CRT" --key="$CERT_KEY" \
  -n "$ARGOCD_NAMESPACE"

echo ""
echo "=== ARGOCD INSTALLATION ==="

# 12.B Install Argo CD
# echo "Installing Argo CD into 'argocd' namespace..."
# sudo kubectl apply -n argocd -f https://raw.githubusercontent.com/argoproj/argo-cd/stable/manifests/install.yaml
# echo "Waiting for Argo CD components to be ready (this may take a few minutes)..."
# sudo kubectl wait --for=condition=ready pod --all -n argocd --timeout=300s

# 12 Install Argo CD with helm
echo "Installing/Upgrading Argo CD Helm chart..."
sudo helm repo add argo https://argoproj.github.io/argo-helm
sudo helm repo update
TEMPLATE_VALUES="../manifests/argocd-custom-values.template.yaml" 
FINAL_VALUES="/tmp/argocd-final-values.yaml"

envsubst < "$TEMPLATE_VALUES" > "$FINAL_VALUES"

sudo helm upgrade --install argocd argo/argo-cd \
  --namespace "$ARGOCD_NAMESPACE" \
  --create-namespace \
  -f "$FINAL_VALUES" \
  --wait --timeout 10m0s #--debug > helm_argocd_install_debug.log 2>&1

echo "Argo CD installed/updated via Helm."
echo "Waiting for Argo CD server deployment to be fully ready..."
sudo kubectl wait --for=condition=available deployment/argocd-server -n "$ARGOCD_NAMESPACE" --timeout=300s

# 13.B1 Change Argo CD server service to NodePort for easier access without port-forwarding
# echo "Patching Argo CD server service to use NodePort 30080 for UI access..."
# sudo kubectl patch svc argocd-server -n argocd -p '{"spec": {"type": "NodePort", "ports": [{"port": 80, "targetPort": 8080, "nodePort": 30080, "name": "http"}, {"port": 443, "targetPort": 8080, "nodePort": 30443, "name": "https"}]}}'

# 13.B2 Retrieve Argo CD initial admin password and setup without sudo
# echo "Retrieving Argo CD initial admin password..."
# ARGOCD_PASS=$(sudo kubectl -n argocd get secret argocd-initial-admin-secret -o jsonpath="{.data.password}" | base64 -d)

echo ""
echo "=== KUBECTL USER CONFIGURATION ==="

# 13 kubectl for the 'vagrant' user (to run without sudo)
echo "Configuring kubectl for the 'vagrant' user..."
sudo mkdir -p /home/vagrant/.kube
sudo chown vagrant:vagrant /home/vagrant/.kube
if sudo k3d kubeconfig get p3 > /dev/null 2>&1; then
    sudo k3d kubeconfig get p3 > /home/vagrant/.kube/config
    sudo chown vagrant:vagrant /home/vagrant/.kube/config
    sudo chmod 600 /home/vagrant/.kube/config
    echo "kubectl for 'vagrant' user configured. You can now try 'kubectl get ns' as 'vagrant'."
else
    echo "WARNING: /root/.kube/config not found. Cannot configure kubectl for 'vagrant' user without sudo."
fi

echo ""
echo "=== ARGOCD PROJECT CREATION ==="

# 14. Prepare and apply Argo CD Project manifest dinamically
echo "Creating Argo CD Project..."
PROJECT_MANIFEST="/tmp/project-development.yaml"

cat <<EOF > "$PROJECT_MANIFEST"
apiVersion: argoproj.io/v1alpha1
kind: AppProject
metadata:
  name: development
  namespace: $ARGOCD_NAMESPACE
spec:
  description: "IOT Project"
  sourceRepos:
  - https://github.com/$GITHUB_USERNAME/$REPO_NAME.git
  destinations:
  - namespace: dev
    server: https://kubernetes.default.svc
  clusterResourceWhitelist:
  - group: "*"
    kind: "*"
EOF

sudo kubectl apply -f "$PROJECT_MANIFEST"

echo ""
echo "=== ARGOCD APPLICATION CREATION ==="

# 15. Prepare and apply Argo CD Application manifest dinamically
echo "Creating Argo CD Application..."
cat <<EOF > "$MANIFEST_PATH"
apiVersion: argoproj.io/v1alpha1
kind: Application
metadata:
  name: $ARGOCD_APP_NAME
  namespace: $ARGOCD_NAMESPACE
spec:
  project: development
  source:
    repoURL: https://github.com/$GITHUB_USERNAME/$REPO_NAME.git
    targetRevision: HEAD
    path: $REPO_PATH
  destination: 
    server: https://kubernetes.default.svc
    namespace: dev
  syncPolicy:
    automated:
      prune: true
      selfHeal: true
    syncOptions:
    - CreateNamespace=true
    - RespectIgnoreDifferences=false
EOF
echo "Argo CD Application manifest '$MANIFEST_PATH' created."

echo "Applying Argo CD Application manifest to the cluster..."
sudo kubectl apply -f "$MANIFEST_PATH" -n "$ARGOCD_NAMESPACE"
echo "Argo CD Application '$ARGOCD_APP_NAME' applied."

echo ""
echo "=== POD READINESS VERIFICATION ==="

# 16. Ensure necessary pods are available
echo "Waiting for Argo CD server deployment to be fully ready..."
sudo KUBECONFIG="$KUBECONFIG_ROOT" kubectl wait --for=condition=available deployment/argocd-server -n "$ARGOCD_NAMESPACE" --timeout=300s
echo "argocd-server deployment is available."

echo "Waiting for Argo CD redis deployment to be fully ready..."
sudo KUBECONFIG="$KUBECONFIG_ROOT" kubectl wait --for=condition=available deployment/argocd-redis -n "$ARGOCD_NAMESPACE" --timeout=180s
echo "argocd-redis deployment is available."

echo ""
echo "=== ARGOCD SECRET CONFIGURATION ==="

# 17. Patch argocd-secret to user configuration
JSON_PATCH_SECRET_DATA=$(cat <<EOF
{
  "data": {
    "accounts.${USER_LOGIN}.password": "$PATCH_PASS",
    "accounts.${USER_LOGIN}.passwordMtime": "$PATCH_MTIME",
    "webhook.github.secret": "$WEBHOOK_SECRET_B64" 
  }
}
EOF
)

sudo kubectl patch secret argocd-secret -n "$ARGOCD_NAMESPACE" \
  --type merge -p "$JSON_PATCH_SECRET_DATA"

echo ""
echo "=== POD RESTART ==="

# 18. Restart Pods to ensure new config
sudo kubectl delete pod -n "$ARGOCD_NAMESPACE" -l app.kubernetes.io/name=argocd-server --wait=true
sudo kubectl wait pod -n "$ARGOCD_NAMESPACE" -l app.kubernetes.io/name=argocd-server --for=condition=Ready --timeout=180s
sudo kubectl delete pod -n "$ARGOCD_NAMESPACE" -l app.kubernetes.io/name=argocd-application-controller --wait=true
sudo kubectl wait pod -n "$ARGOCD_NAMESPACE" -l app.kubernetes.io/name=argocd-application-controller --for=condition=Ready --timeout=180s

echo ""
echo "=== APPLICATION STATUS VERIFICATION ==="

# 19. Wait untill Application is available
echo "Waiting for Argo CD Application '$ARGOCD_APP_NAME' to be Synced and Healthy..."
TIMEOUT="150s" 
INTERVAL="10s"

READY_CMD="sudo kubectl get application $ARGOCD_APP_NAME -n $ARGOCD_NAMESPACE -o jsonpath='{.status.sync.status}{\" \"}{.status.health.status}' 2>/dev/null | grep -q '^Synced Healthy$'"

if timeout "$TIMEOUT" bash -c "until $READY_CMD; do echo -n '.'; sleep $INTERVAL; done"; then
    echo ""
    echo "Argo CD Application '$ARGOCD_APP_NAME' is Synced and Healthy."
    STATUS="true"
else
    echo "" 
    echo "ERROR: Timeout reached while waiting for Argo CD Application '$ARGOCD_APP_NAME' to be Synced and Healthy after $TIMEOUT."
    echo "Current status:"
    sudo kubectl get application "$ARGOCD_APP_NAME" -n "$ARGOCD_NAMESPACE" -o yaml | grep -E '^\s*(status:|phase:|message:|health:|sync:)' || echo "Could not get application status."
    echo "Please check Argo CD UI or logs for more details."
    STATUS="false"
fi

echo ""
echo "=== NGROK TUNNEL SETUP ==="

# 20. Start Ngrok tunnel in background
if command -v ngrok &> /dev/null && [ -n "$NGROK_STATIC_DOMAIN" ] && [ -n "$NGROK_AUTHTOKEN" ] && [ -n "$ARGOCD_PORT" ]; then
    echo "Attempting to start Ngrok tunnel in background for Argo CD UI..."
    NGROK_LOG_FILE="/tmp/ngrok_argo_tunnel.log"
    
    NGROK_COMMAND="ngrok http --url=$NGROK_STATIC_DOMAIN https://$IP:$ARGOCD_PORT --log=$NGROK_LOG_FILE"
    
    echo "Ngrok command to run as user 'vagrant': $NGROK_COMMAND"
    sudo pkill -f "ngrok http" || true 
    sleep 2

    if sudo -u vagrant HOME=/home/vagrant nohup $NGROK_COMMAND > /dev/null 2>&1 & then
        echo "Ngrok tunnel initiation command sent to background for user 'vagrant'."
        echo "It might take a few seconds for the tunnel to establish."
        echo "  - Viewing the log: cat $NGROK_LOG_FILE"
        sleep 5
    else
        echo "ERROR: Failed to send Ngrok tunnel command to background. Check $NGROK_LOG_FILE."
    fi
else
    echo "Ngrok tunnel not started: Required variables (NGROK_STATIC_DOMAIN, NGROK_AUTHTOKEN, ARGOCD_PORT) not set or ngrok not installed."
fi

echo ""
echo "=== COMPLETION ==="

# 21. Print credentials to ease evaluation
echo "---------------------------------------------------------------------"
echo "Setup script finished."
echo "---------------------------------------------------------------------"

if [ "$STATUS" == "true" ]; then
    echo ""
    echo "Access Details (from host machine):"
    echo "------------------------------------------"
    echo "1. Argo CD UI:"
    echo "   URL: http://$IP:$ARGOCD_PORT"
    echo "   User: $USER_LOGIN"
    echo "   Password: $USER_PASS" 
    echo ""
    echo "2. Your Deployed Application:"
    echo "   URL: http://$IP:$APP_PORT"
    echo "   (Application '$ARGOCD_APP_NAME' is reported as Synced and Healthy by Argo CD)"
else
    echo ""
    echo "Application '$ARGOCD_APP_NAME' was NOT reported as Synced and Healthy within the timeout."
    echo "You might still be able to access Argo CD UI to check its status:"
    echo "  Argo CD UI URL: http://$IP:$ARGOCD_PORT"
    echo "  User: $USER_LOGIN, Password: $USER_PASS"
fi

echo ""
echo "---------------------------------------------------------------------"
