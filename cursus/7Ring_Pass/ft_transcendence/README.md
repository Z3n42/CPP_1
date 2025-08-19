# ft_transcendence

**Surprise.**

---

## 🌐 Project Overview

`ft_transcendence` is a full-stack web platform developed as part of the 42 Urduliz curriculum. This project demonstrates advanced software engineering practices by integrating modern frontend, backend, and DevOps technologies in a modular, production-ready environment.

The platform includes:
- A user-friendly Angular landing page
- A robust Django API backend
- PostgreSQL for data persistence
- Observability and monitoring with Grafana and Kibana
- Administration tools like PGAdmin and RedisInsight

The system is designed for scalability, maintainability, and real-world deployment, leveraging Docker for containerization and automation.

---

## 🚀 Quick Guide for the Makefile

### Available Commands

- **make**: Starts services and builds necessary images.
- **make down**: Stops services.
- **make restart**: Stops services and restarts them.
- **make destroy**: Full cleanup of the Docker environment.
- **make all**: Alias for `make`.
- **make fclean**: Cleans the Docker environment.
- **make re**: Rebuilds everything from scratch.
- **make help**: Displays all available commands and their descriptions.
- **make prod**: Starts production environment services.
- **make prod-down**: Stops production services.
- **make prod-destroy**: Full cleanup of the Docker production services.

---

## 📡 Accessing Services

- **Angular Landing Page:** [host:42443](http://localhost:42443)
- **Django API:** [host:8443](http://localhost:8443)
- **Core API Documentation:** [host:8443/docs](http://localhost:8443/docs)
- **PGAdmin Interface:** [host:5050](http://localhost:5050)
- **Grafana Dashboard:** [host:3060](http://localhost:3060)
- **Kibana Interface:** [host:5601](http://localhost:5601)
- **RedisInsight:** [host:5540](http://localhost:5540)

---

## 🛡️ Environment Variables

This project requires certain environment variables to be set for proper configuration.  
A template is provided in the file `.env.example`. Copy this file to `.env` and fill in the required values before starting the project:

```bash
cp .env.example .env
# Then edit the .env file with your configuration
```

**Important:**  
Never commit your actual `.env` file or sensitive information to the repository.

---

## 🔒 SSL Certificates Required

In order to enable secure connections and integrate with services like Elasticsearch, you must provide your own SSL certificates.  
These files are **not included** in the repository and must be created or provided by each user.

**Expected files and location:**
- `ssl/server.crt` &nbsp;&nbsp;&nbsp;&nbsp;← Server certificate
- `ssl/server.key` &nbsp;&nbsp;&nbsp;&nbsp;← Private key for the certificate
- `ssl/elasticsearch.p12` &nbsp;&nbsp;&nbsp;&nbsp;← PKCS#12 bundle for Elasticsearch

### How to generate the required SSL certificates for development

1. **Create the ssl directory (if it doesn’t exist):**
   ```bash
   mkdir -p ssl
   ```

2. **Generate a new private key and self-signed certificate:**
   ```bash
   openssl req -x509 -newkey rsa:4096 -keyout ssl/server.key -out ssl/server.crt -days 365 -nodes -subj "/CN=localhost"
   ```
   This command will generate the following files:
   - `ssl/server.key` (private key)
   - `ssl/server.crt` (self-signed certificate)

3. **Create the PKCS#12 (.p12) bundle for Elasticsearch:**
   ```bash
   openssl pkcs12 -export \
     -in ssl/server.crt \
     -inkey ssl/server.key \
     -out ssl/elasticsearch.p12 \
     -name "elasticsearch" \
     -passout pass:changeit
   ```
   This command will generate:
   - `ssl/elasticsearch.p12` (bundle containing both the certificate and private key)

   > **Note:**  
   > The password for the `.p12` file here is set to `changeit` (common default for development).  
   > You can change it as needed, but ensure that the password matches your Elasticsearch configuration.

4. **Summary of what you should have in your `ssl/` directory:**
   ```
   ssl/
     ├── server.crt
     ├── server.key
     └── elasticsearch.p12
   ```

5. **Security note:**  
   These files are for local development and testing purposes only.  
   For production use, obtain certificates from a trusted Certificate Authority (CA).

---

## 👥 Contributors

This project was developed as an educational team effort by:

<p align="left">
  <a href="https://github.com/cdiaz-fl"><img src="https://avatars.githubusercontent.com/u/85074433?v=4" width="48" title="cdiaz-fl"/></a>
  <a href="https://github.com/Mirgc"><img src="https://avatars.githubusercontent.com/u/82157764?v=4" width="48" title="Mirgc"/></a>
  <a href="https://github.com/mikgarci42"><img src="https://avatars.githubusercontent.com/u/82385686?v=4" width="48" title="mikgarci42"/></a>
  <a href="https://github.com/pojea-lo"><img src="https://avatars.githubusercontent.com/u/92981551?v=4" width="48" title="pojea-lo"/></a>
  <a href="https://github.com/Z3n42"><img src="https://avatars.githubusercontent.com/u/81714096?v=4" width="48" title="Z3n42"/></a>
</p>

---

## 📖 Documentation

For more detailed information and guidance, visit our [Wiki](https://github.com/Z3n42/ft_transcendence/wiki).

---

_This summary provides a quick overview of the project, usage, and contributors. For full technical documentation, guidelines, and updates, check the Wiki or contact the maintainers._
