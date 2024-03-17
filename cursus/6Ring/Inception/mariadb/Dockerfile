FROM debian:oldstable

# Install necessary packages and clean apt cache
RUN apt-get update && apt-get install -y \
    mariadb-server \
    tini \
    vim && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Create directory for scripts
RUN mkdir -p /scripts

# Create directory for mysqld and change ownership
RUN mkdir /run/mysqld && chown -R mysql:mysql /run/mysqld

# Copy script files and configuration
COPY mariadb/scripts/init.sh /scripts/init.sh
COPY mariadb/scripts/init.sql /scripts/init.sql
COPY mariadb/scripts/50-server.cnf /etc/mysql/mariadb.conf.d/

# Set permissions for the entry script
RUN chmod +x /scripts/init.sh

# Define entry point
ENTRYPOINT ["/usr/bin/tini", "--"]

# Define default command
CMD ["/scripts/init.sh"]

