# Vagrant + K3s

## Description

This project sets up a **K3s** cluster using **Vagrant** with two virtual machines. The first machine acts as the **server (controller)**, while the second machine functions as a **worker (agent)**.

### 📂 Project Location

The repository structure follows this organization:

```
📂 iot/
 ├── 📂 p1/
 │   ├── 📂 vagrant/   # Vagrant configuration files
 │   ├── Vagrantfile  # Main configuration file
 │   ├── README.md    # This file with instructions
```

### 🛠️ Virtual Machine Configuration

- **Two virtual machines**:
  - `migarciS` (K3s Server)
  - `ingonzalSW` (K3s Worker Node)
- **Minimum Resources**: 1 CPU, 512 MB RAM
- **Private Network**:
  - `migarciS`: `192.168.56.110`
  - `ingonzalSW`: `192.168.56.111`
- **Passwordless SSH** configured
- **Automatic Provisioning**:
  - The server installs **K3s in controller mode**.
  - The worker node installs **K3s in agent mode**, connecting to the server using a **token authentication**.


## 🚀 Using Vagrant

### Start Virtual Machines

Run one of the following commands depending on the provider:

```bash
vagrant up --provider=vmware_desktop
vagrant up --provider=virtualbox
```

### Connect to Machines

To access each machine via SSH:

```bash
vagrant ssh migarciS  # Connect to the server
vagrant ssh ingonzalSW  # Connect to the worker
```

### Verify K3s is Running

Inside `migarciS` (the server), run:

```bash
kubectl get nodes
```

You should see both the server and the worker listed as active nodes.

### Stop and Destroy Machines

To stop the machines without deleting them:

```bash
vagrant halt
```

To completely remove the virtual machines:

```bash
vagrant destroy -f
```


## 📝 Additional Notes

- The `Vagrantfile` automatically detects the provider (`vmware_desktop` or `virtualbox`).
- **Ubuntu 20.04** is used as the base system.
- Shared folders between the host and virtual machines are configured.
- The worker node waits until the server provides the authentication token to join the cluster.

📌 **Next Steps:** Configure Kubernetes deployments using `kubectl` 🎯.

