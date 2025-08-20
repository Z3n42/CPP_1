# Inception-of-Things (IoT)

## 📌 General Description

This repository contains system administration exercises focused on setting up and deploying lightweight infrastructures using **Vagrant**, **K3s**, **K3d**, and **Argo CD**.

## 📂 Repository Structure

```
📂 iot/
 ├── 📂 p1/   # K3s and Vagrant
 ├── 📂 p2/   # K3s and simple applications
 ├── 📂 p3/   # K3d and Argo CD
 ├── 📂 bonus/ # Optional part
 ├── .gitignore
 ├── README.md  # This file
```

Each part follows a logical sequence, from the initial Vagrant setup to integrating a CI/CD pipeline with Argo CD.

## 🛠️ Prerequisites

Before getting started, make sure you have the following tools installed:

- **Vagrant**
- **VirtualBox** or **VMware Desktop**
- **kubectl**
- **Docker**
- **Git**

## 🚀 General Usage

### Cloning the Repository with the Submodule

If you're cloning the`repository (or the main`iot`repository) for the first time, the easiest way to ensure the`will_app`submodule is downloaded is to use the`--recurse-submodules` flag:

```bash
git clone --recurse-submodules <URL_of_iot_repository>
```

or:
If you've already cloned `p3` without the submodule, or if someone has added/updated the submodule and you've `git pull`ed in `p3`, you'll need to initialize and update the submodule:

## ✨ Automated Submodule Management with `update_version.sh`

This project includes an automated script that **significantly simplifies** submodule management and version updates, eliminating the typical complexity of manual Git submodule operations.

#### 🎯 Usage

**Simple execution:**
Navigate to the p3/ directory and execute:

```
./update_version.sh
```

## 📥 Manual Submodule Operations

From the root of the p3/will_app repository (or the main iot repository)

```bash
git submodule update --init --recursive
```

### Start the Environments

Each part has its own instructions within its respective directory. In general:

```bash
cd p1/
vagrant up --provider=virtualbox
```

### Shut Down and Destroy the Machines

```bash
vagrant halt   # Stop the machines
vagrant destroy -f   # Completely remove the machines
```

## 🔗 Additional Resources

- [Vagrant Documentation](https://developer.hashicorp.com/vagrant/docs)
- [K3s Official Site](https://k3s.io/)
- [K3d Documentation](https://k3d.io/)
- [Argo CD](https://argo-cd.readthedocs.io/en/stable/)

📌 **Next Steps:** Explore each part and progress step by step with Kubernetes. 🚀

