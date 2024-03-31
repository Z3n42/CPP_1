# Use the oldstable version of Debian as the base image
FROM debian:oldstable

# Update the package lists for upgrades and installations
RUN apt-get update && apt-get install -y \
	nginx \
	openssl \
	tini \
    vim && \
    # Clean up the local repository of retrieved package files to reduce the image size
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Copy the Nginx configuration file into the Docker image
COPY nginx/scripts/nginx.conf /etc/nginx/conf.d/nginx.conf
# Copy the entrypoint script into the Docker image
COPY nginx/scripts/cert.sh /usr/src/app/entrypoint.sh

# Make the entrypoint script executable
RUN ["chmod", "+x", "/usr/src/app/entrypoint.sh"]
# Make the Nginx configuration file executable
# RUN ["chmod", "+x", "/etc/nginx/conf.d/nginx.conf"]

# Use tini as the entrypoint, which allows it to catch signals and forward them to the application
ENTRYPOINT ["/usr/bin/tini", "--"]

# Run the entrypoint script when the Docker container starts
CMD /usr/src/app/entrypoint.sh