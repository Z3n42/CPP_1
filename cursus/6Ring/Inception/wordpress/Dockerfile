FROM debian:oldstable

# Install necessary packages and clean apt cache
RUN apt-get update && apt-get install -y \
    php \
    php-fpm \
    php-mysql \
    mariadb-client \
    curl \
    tini \
    vim && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Copy script files and configuration
COPY wordpress/scripts/cnf /etc/php/7.4/fpm/pool.d/www.conf
COPY wordpress/scripts/init.sh /init.sh

# Set permissions for the entry script
RUN chmod +x /init.sh

# Define entry point
ENTRYPOINT ["/usr/bin/tini", "--"]
#ENTRYPOINT ["/scripts/init.sh"]

# Define default command
CMD ["bash", "./init.sh"]

