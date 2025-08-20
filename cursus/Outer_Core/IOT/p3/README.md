# P3: K3d + Argo CD

## 📖 Description

This part of the Inception-of-Things (IoT) project focuses on setting up a Kubernetes cluster using **K3d** (K3s in Docker) and implementing a GitOps workflow with **Argo CD**. The goal is to automatically deploy and manage an application hosted in a public GitHub repository.

### 📂 Project Location

The directory structure for this part (`p3/`) is:

```
. (p3 directory)
├── help # (Optional) Helper scripts or notes
├── update_version.sh # Script to toggle application versions in Git
├── vagrant/ # Contains Vagrant setup for the K3d environment
│ ├── manifests/
│ │ └── argocd-custom-values.template.yaml # Helm values template for Argo CD
│ ├── scripts/
│ │ └── init.sh # Main setup script for K3d, Argo CD, and app
│ └── Vagrantfile # Vagrant configuration for the VM
└── will_app/ # Git repository for the application to be deployed
└── manifests/
└── deployment.yaml # Kubernetes deployment manifest for the application
```

### ✨ Key Features & Configuration

- **K3d Cluster:** A lightweight K3s cluster running within Docker, managed by K3d.
- **Argo CD:** Deployed via Helm for GitOps-based continuous delivery.
  - Custom admin user (`migarcia`) configured.
  - Default `admin` user disabled.
- **Namespaces:**
  - `argocd`: Dedicated namespace for Argo CD components.
  - `dev`: Namespace for deploying the sample application.
- **Sample Application (`will_app`):**
  - Deployed from a public GitHub repository (`https://github.com/Z3n42/Migarcia-Ingonzal.git`).
  - Uses the `wil42/playground` Docker image from Docker Hub.
  - Supports two versions (`v1` and `v2`) toggleable via Git commits.
- **Automated Setup:** An `init.sh` script within the `vagrant/scripts/` directory automates:
  - Installation of Docker, K3d, kubectl, Helm, and Argo CD CLI.
  - Creation of the K3d cluster.
  - Deployment of Argo CD using Helm with custom values.
  - Configuration of the custom Argo CD admin user (`migarcia`).
  - Creation of Argo CD `AppProject` and `Application` resources to deploy `will_app`.

## 📦 `will_app` Submodule Management

The `will_app` directory is a Git submodule. This means it's a separate Git repository embedded within this `p3` project. The `p3` project doesn't directly store `will_app`'s files but rather a reference to a specific commit of the `will_app` repository.

### Cloning the Repository with the Submodule

If you're cloning the `p3` repository (or the main `iot` repository) for the first time, the easiest way to ensure the `will_app` submodule is downloaded is to use the `--recurse-submodules` flag:

```
git clone --recurse-submodules <URL_of_iot_repository>
```

or:
If you've already cloned `p3` without the submodule, or if someone has added/updated the submodule and you've `git pull`ed in `p3`, you'll need to initialize and update the submodule:

## 🚀 Automated Submodule Management with `update_version.sh`

This project includes an automated script that **significantly simplifies** submodule management and version updates, eliminating the typical complexity of manual Git submodule operations.

#### ✨ What the Script Does

The `update_version.sh` script (located in the `p3/` root directory) provides intelligent automation:

- **Smart Initialization**: Automatically detects if the submodule is initialized and configures it if necessary using `git submodule update --init --recursive`
- **Automatic Updates**: Verifies and downloads the latest version from the remote repository using `git submodule update --remote --recursive`
- **Parent Repository Sync**: Automatically updates submodule references in the main project and commits the changes
- **Version Toggle**: Alternates between `wil42/playground:v1` ↔ `wil42/playground:v2` in `manifests/deployment.yaml`
- **Auto Commit & Push**: Commits and pushes all changes to both submodule and parent repository with timestamped messages

#### 🎯 Usage

**Simple execution:**
Navigate to the p3/ directory and execute:

```
./update_version.sh
```

## 📥 Manual Submodule Operations

From the root of the p3/will_app repository (or the main iot repository)

```
git submodule update --init --recursive
```

### Making Changes to the `will_app` Submodule

If you need to modify the `will_app` application (e.g., its `deployment.yaml`):

1. Navigate to the submodule directory:
   
   ```
   cd p3/will_app
   ```
2. Make your changes, commit, and push **within the submodule** to its own remote repository:
   
   ```
   git add .
   git commit -m "Descriptive message of changes in will_app"
   git push origin main # Or the submodule's corresponding branch
   ```
3. Return to the `p3` root directory:
   
   ```
   cd ../..
   ```
4. The `p3` repository will have detected that `will_app` now points to a new commit. Add this change and commit in `p3` to update the submodule reference:
   
   ```
   git add p3/will_app
   git commit -m "Updated will_app submodule reference"
   git push origin task/p3_propossal # Or p3's corresponding branch
   ```

### Getting Submodule Updates

If the `will_app` submodule reference has been updated in `p3`'s remote repository (e.g., by another collaborator):

1. Run `git pull` in `p3` to get the latest changes, including the new submodule reference.
2. Update your local copy of the submodule:
   
   ```
   git submodule update --recursive
   ```
   
   To ensure you get the latest version of the submodule as specified by the parent project, and also to update to the latest version from the submodule's remote if desired, you can use:
   
   ```
   git submodule update --remote --merge p3/will_app # Updates to the latest from the submodule's remote and merges
   # Then, in the parent (p3):
   # git add p3/will_app
   # git commit -m "Updated will_app to its latest remote version"
   # git push
   ```

It's crucial to remember that the `will_app` submodule and the `p3` parent project are distinct repositories. Changes in one must be committed and pushed to their respective repository, and then the parent must update its reference to the desired state of the submodule.

## 🛠️ Prerequisites

Ensure you have the following installed on your host machine:

- **Vagrant**
- **VirtualBox** (or another compatible Vagrant provider)
- **Git**

The `init.sh` script within the Vagrant VM will handle the installation of Docker, K3d, kubectl, Helm, and the Argo CD CLI.

## ⚙️ Environment Variables

The setup script (`vagrant/scripts/init.sh`) utilizes an `.env` file (which should be created in the `vagrant/scripts/` directory) for sensitive or configurable parameters.
This file is **not** to be committed to Git.

**Example `.env` content:**

Argo CD User Credentials

```
USER_LOGIN=''
USER_PASS='' # Choose a strong password
Network Configuration for VM and Services

IP='' # IP for the Vagrant VM
ARGOCD_PORT='' # Host port to access Argo CD UI
APP_PORT='' # Host port to access the deployed application
NODEPORT_HTTP="" # Kubernetes NodePort for Argo CD HTTP service
Git Repository for the Application

GITHUB_USERNAME=''
REPO_NAME=''
REPO_PATH='' # Path within the repo to the K8s manifests
Argo CD Application Details

ARGOCD_APP_NAME=''
ARGOCD_NAMESPACE='' # Namespace where Argo CD is installed
MANIFEST_PATH='' # Temporary path for generated manifests
```

## 🚀 Setup and Usage

### 1. Prepare the Environment

1. **Clone the main `iot` repository** (if you haven't already) and navigate to the `p3` directory.
2. Navigate to the `vagrant/scripts/` directory within `p3`.
3. **Create an `.env` file** with the necessary environment variables as shown above.

### 2. Start the Vagrant VM and Run Setup

1. Navigate to the `p3/vagrant/` directory.
2. Start the Vagrant VM.
   
   ```
   vagrant up
   ```
3. Connect via ssh
   
   ```
   vagrant ssh
   ```
4. Navigate to the `scripts` directory and excute init script.
   
   ```
   ./init.sh
   ```
   
   The `init.sh` script will:- Install all required tools (Docker, K3d, kubectl, Helm, Argo CD CLI).
   
   - Create the K3d cluster.
   - Deploy Argo CD using Helm with your custom values (including setting up the `migarcia` user and disabling `admin`).
   - Create the `AppProject` and `Application` in Argo CD to deploy `will_app` from your GitHub repository.

### 3. Access Argo CD UI

Once the `init.sh` script completes successfully:

1. Open your web browser.
2. Navigate to `http://<VM_IP>:<ARGOCD_PORT>` (e.g., `http://192.168.57.10:8080` using the example `.env`).
3. Log in with the credentials:
   - **Username:** `migarcia` (or your `$USER_LOGIN`)
   - **Password:** The password you set for `$USER_PASS`.

You should see the `iot-p3` application listed and its status.

### 4. Access the Deployed Application

The `will_app` (playground application) will be accessible on:
`http://<VM_IP>:<APP_PORT>` (e.g., `http://192.168.57.10:8888`).
Initially, it should display `{"status":"ok", "message": "v1"}` or `v2` depending on the version in your `will_app/manifests/deployment.yaml` on the `HEAD` of your repository.

### 5. Update Application Version (GitOps Workflow)

1. **Use the `update_version.sh` script** (located in the `p3/` root directory) to toggle the image tag in `will_app/manifests/deployment.yaml`, commit, and push the change to your GitHub repository.
   
   ```
   # Navigate to the p3/ directory on your host
   cd /path/to/iot/p3
   ./update_version.sh
   ```
   
   This script will:
   
   - Detect the current version (`v1` or `v2`) in `will_app/manifests/deployment.yaml`.
   - Change it to the other version.
   - Commit the change with a message like "version update to vX on YYYY-MM-DD HH:MM:SS".
   - Push the commit to your GitHub repository.
2. **Observe Argo CD:**
   
   - Go back to the Argo CD UI.
   - Argo CD should automatically detect the change in the Git repository (within a few minutes, or you can trigger a manual refresh/sync).
   - It will then update the deployed application to the new version.
3. **Verify Application Update:**
   
   - Refresh the application URL (`http://<VM_IP>:<APP_PORT>`).
   - You should see the message corresponding to the new version (e.g., `{"status":"ok", "message": "v2"}`).

## 🧹 Cleanup

### Stop the Vagrant VM

From the p3/vagrant/ directory

```
vagrant halt
```

### Destroy the Vagrant VM and K3d Cluster

This will remove the VM and any associated K3d cluster data.

From the p3/vagrant/ directory

```
DESTROY_ALL=true vagrant destroy -f
```

---

📌 **Next Steps:** Proceed to BONUS Part (`Bonus/`).

