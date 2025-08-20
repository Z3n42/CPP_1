# K3s + Simple Applications & Traefik Ingress

## Description

This part builds upon the K3s cluster established in Part 1 (`p1/`) by deploying three simple web applications (`hello-kubernetes`) and configuring external access using K3s's built-in **Traefik Ingress Controller**. It demonstrates host-based routing and setting up a default backend.

### 📂 Project Location

The repository structure for this part (`p2/`) is organized as follows:

```
└── vagrant
├── discarded_manifests # Manifests tried during development (e.g., IngressRoute, failed attempts)
│ ├── help # Text file with useful kubectl commands used during development
│ ├── ingressroute.yaml
│ └── traefik-crb.yaml
├── manifests # Active Kubernetes manifests automatically deployed by K3s
│ ├── app1-helmchart.yaml
│ ├── app2-helmchart.yaml
│ ├── app3-helmchart.yaml
│ ├── default-backend-ingress.yaml # Ingress resource for the default backend
│ ├── host-based-ingress.yaml # Ingress resource for host-based rules (app1, app2)
│ ├── namespace-hello-kubernetes.yaml
│ ├── traefik-accesslog-config.yaml # HelmChartConfig to enable Traefik access logs/dashboard
│ ├── traefik-dashboard-ingress.yaml
│ └── traefik-dashboard-service.yaml
└── Vagrantfile # Vagrant configuration for this part
```

*Note: The `manifests` directory contains the final, working Kubernetes YAML files. K3s automatically applies any `.yaml` file placed in `/var/lib/rancher/k3s/server/manifests/` on the server node (`migarciS`), which is synced from this host directory via Vagrant. The `discarded_manifests` directory holds configurations tested during the debugging process (like `IngressRoute` or failed `Ingress` variations) and a `help` file with command references, kept for documentation and evaluation purposes.*

### ✨ Key Features & Configuration

- **Three Web Applications**:
  - Deployed using `Deployment` and `Service` resources (defined via `HelmChart` manifests for Helm-based deployment).
  - Based on the `paulbouwer/hello-kubernetes:1.10` image.
  - Organized within the dedicated `hello-kubernetes` namespace.
  - `app2` is configured with **3 replicas** for demonstration.
- **Traefik Ingress Controller**:
  - Leverages the built-in Traefik instance provided by K3s.
  - Manages external access to the applications.
- **Routing Rules**:
  - **Host-Based Routing**: Accessing `http://app1.com` routes to `app1`, and `http://app2.com` routes to `app2`.
  - **Default Backend**: Accessing the server's IP directly (e.g., `http://192.168.56.110`) without a matching host routes to `app3`.
- **Ingress Implementation (Notable Point)**:
  - Initial attempts using a single standard Kubernetes `Ingress` resource (`networking.k8s.io/v1`) with `spec.defaultBackend` failed to correctly route default traffic (resulting in 404 errors from Traefik). This behavior seems related to potential bugs or limitations in how some Ingress controllers interpret `spec.defaultBackend` when `spec.rules` are also present (similar issues noted in other controllers, e.g., [ingress-nginx#9030](https://github.com/kubernetes/ingress-nginx/issues/9030)).
  - **Working Solution**: The required routing behavior was successfully achieved using **two separate `Ingress` resources** located in the `manifests` directory:
    1. `host-based-ingress.yaml`: Defines the `spec.rules` for `app1.com` and `app2.com`.
    2. `default-backend-ingress.yaml`: Defines *only* the `spec.defaultBackend` for `app3` and includes the annotation `traefik.ingress.kubernetes.io/router.priority: "1"` to ensure it acts as a low-priority catch-all. This separation allowed Traefik to correctly generate the necessary internal routers.
- **Traefik Dashboard**:
  - Enabled via `HelmChartConfig` (`traefik-accesslog-config.yaml`) for Traefik (adding `--api.dashboard=true` and `--api.insecure=true` arguments).
  - Provides real-time visibility into Traefik's configuration (routers, services, entrypoints).
  - Useful for debugging routing issues.

## 🚀 Usage and Verification

### Deployment

1. Ensure the K3s cluster from Part 1 (`p1/`) is running (`vagrant up`).
2. Ensure all necessary Kubernetes manifest files (`.yaml`) are present in the `./vagrant/manifests/` directory on your host.
3. Apply the configuration. If the K3s server node (`migarciS`) is already running, Vagrant's file sync should trigger K3s's auto-deployment from `/var/lib/rancher/k3s/server/manifests/`. For explicit re-application or initial setup for this part:
   ```
   # From the p2 directory
   vagrant reload --provision migarciS # Reload the server node to ensure manifests are applied
   # Or simply ensure files are synced and wait for K3s to pick them up
   ```

### Verify Kubernetes Resources

Connect to the K3s server node:

```
vagrant ssh migarciS
```

Inside the VM, run:

Check nodes are Ready

```
kubectl get nodes -o wide
```

Check Traefik and system pods are Running

```
kubectl get pods -n kube-system -l app.kubernetes.io/name=traefik
kubectl get pods -n kube-system
```

Check application pods, services, deployments, and replica sets in the correct namespace

```
kubectl get all -n hello-kubernetes
```

Verify both Ingress resources were created

```
kubectl get ingress -n hello-kubernetes
```

Expected Output (Names may vary slightly):

```
NAME CLASS HOSTS ADDRESS PORTS AGE
default-backend-ingress <none> * 80 ...
host-based-routing-ingress <none> app1.com,app2.com ... 80 ...
```

### Test Routing with `curl`

Inside the `migarciS` VM:

Test App 1 via Host 'app1.com' - Expect HTTP 200 OK and App 1 HTML

```
curl -v --resolve app1.com:80:192.168.56.110 http://app1.com/
```

Test App 2 via Host 'app2.com' - Expect HTTP 200 OK and App 2 HTML

```
curl -v --resolve app2.com:80:192.168.56.110 http://app2.com/
```

Test Default Backend (App 3) via IP - Expect HTTP 200 OK and App 3 HTML

```
curl -v http://192.168.56.110/
```

### Accessing from Host Browser

To use `http://app1.com` and `http://app2.com` directly in your host machine's browser:

1. **Edit your host's `hosts` file** (requires administrator privileges):
   * Linux/macOS: `/etc/hosts`
   * Windows: `C:\Windows\System32\drivers\etc\hosts`
2. Add the following lines:
   ```
   192.168.56.110  app1.com
   192.168.56.110  app2.com
   ```
3. Save the file.
4. **Flush your DNS cache** (commands vary by OS).
5. You should now be able to access `http://app1.com`, `http://app2.com`, and `http://192.168.56.110` (for App 3) in your browser.

*(Alternative: Modify the `host-based-ingress.yaml` resource to use `nip.io` hostnames like `app1.192.168.56.110.nip.io` to avoid editing the `hosts` file).*

### Accessing the Traefik Dashboard

**Method 1: Port Forwarding (Temporary)**

1. Inside the `migarciS` VM, run:
   ```
   # Forward local port 9000 to Traefik's internal dashboard port
   nohup kubectl port-forward -n kube-system deployment/traefik 8080:8080 --address 0.0.0.0 > portforward.log 2>&1 &
   ```
2. On your **host machine**, open a browser and navigate to: `http://192.168.56.110:9000/dashboard/` (Note the trailing slash!).

**Method 2: Dedicated Ingress (More Permanent, using `nip.io` example)**

1. Ensure you have deployed the `Service` (`traefik-dashboard-service.yaml`) and `Ingress` (`traefik-dashboard-ingress.yaml`) specifically for the dashboard, **ensuring they target the correct internal port `9000`**.
2. If using `nip.io` and the correct port (9000), access via your host browser: `http://traefik.192.168.56.110.nip.io/dashboard/` (Remember the trailing slash!).

---

## 📝 Additional Notes

- The successful implementation of the `defaultBackend` using standard `Ingress` resources required separating it into its own `Ingress` resource with a low priority annotation, highlighting potential inconsistencies in how standard `Ingress` specifications are interpreted by different controller versions or setups.
- Using dedicated namespaces like `hello-kubernetes` is a best practice over deploying directly into the `default` namespace.
- The `discarded_manifests` directory contains alternative configurations (like `IngressRoute`) explored during development, which provide valuable insights into Traefik's different configuration methods.

📌 **Next Steps:** Proceed to Part 3 (`p3/`) exploring K3d and Argo CD. 🚀

