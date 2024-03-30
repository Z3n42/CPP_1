FROM debian:oldstable

# Install necessary packages and clean apt cache
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    php7.4 \
    php-fpm \
    php-mysql \
    mariadb-client \
    curl \
    tini \
    vim && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# EXPOSE 9000

# RUN mkdir -p /var/www/inception/wordpress

# Copy script files and configuration
COPY wordpress/scripts/cnf /etc/php/7.4/fpm/pool.d/www.conf
COPY wordpress/scripts/init.sh /scripts/init.sh

# Set permissions for the entry script
RUN chmod +x /scripts/init.sh	
# RUN chown -R root:root /var/www/inception/wordpress

# Define entry point
# ENTRYPOINT ["/usr/bin/tini", "--"]

## Define default command
CMD ["bash", "/scripts/init.sh"]

