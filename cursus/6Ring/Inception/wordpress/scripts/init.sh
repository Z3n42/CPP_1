#!/bin/bash

# installing of wp-cli
curl -q -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /opt/wp-cli.phar
# php
if [ ! -d /run/php ]; then                                                                                                                                                                     
        mkdir /run/php                                                                                                                                                                         
fi                                                                                                                                                                                             
#wordpress
if [ ! -d /var/www/Inception-website ]; then
        mkdir /var/www/Inception-website
	chmod -R 777 /var/www/Inception-website
fi

if [ ! -f /var/www/Inception-website/wp-config.php ]; then
        /opt/wp-cli.phar core download --path=/var/www/Inception-website --allow-root
        /opt/wp-cli.phar config create --path=/var/www/Inception-website --dbname=$DB_NAME --dbhost=$DB_HOST --dbuser=$USER --dbpass=$USER_PASSWORD --allow-root
        /opt/wp-cli.phar core install --path=/var/www/Inception-website --url=https://yakhoudr.42.fr --title=Inception --admin_user=$WORD_ADMIN --admin_password=$WORD_ADMIN_PASSWORD --admin_email=$WORD_ADMIN_EMAIL --allow-root                                                                                                                                                                          
        /opt/wp-cli.phar user create $WORD_USER $WORD_USER_EMAIL --role=$WORD_USER_ROLE --user_pass=$WORD_USER_PASS --path=/var/www/Inception-website --allow-root                                           
else                                                                                                                                                                                           
        echo "Wordpress is already installed."                                                                                                                                                 
fi
#php-fpm                                                                                                                                                                                       
echo "php-fpm is now running."
exec php-fpm7.4 -F


# #!/bin/bash

# # Enable the shell option to exit immediately if a pipeline returns a non-zero status
# set -e
# set -o pipefail

# # Create necessary directories for MariaDB
# mkdir -p /var/run/mysqld /run/mysqld
# chown -R mysql:mysql /var/run/mysqld /run/mysqld

# # Initialize the database if not present
# if [ ! -d /var/lib/mysql/mysql ]; then
#   echo "Initializing the database..."
#   mysql_install_db --user=root
# fi

# # Start MariaDB service in the background
# echo "Starting MariaDB service..."
# service mariadb start

# # Wait until MariaDB server is online
# echo "Waiting for MariaDB server to be online..."
# while ! mysqladmin ping -hlocalhost --silent 2>/dev/null; do
# 	 sleep 1
# done

# # Execute initial SQL queries
# if [[ -f /scripts/init.sql ]]; then
#   echo "Executing initial SQL queries..."
#   # Create a temporary SQL file with environment variables substituted
#   envsubst < /scripts/init.sql > /tmp/init.sql
#   # Execute the SQL queries in the temporary file
#   mysql -u root -p${MYSQL_ROOT_PASSWORD} < /tmp/init.sql
#   # Remove the temporary file
#   rm /tmp/init.sql
# fi

# # Stop MariaDB service
# echo "Stopping MariaDB service..."
# service mariadb stop

# # Wait until MariaDB server has stopped
# echo "Waiting for MariaDB server to stop..."
# while mysqladmin ping -hlocalhost --silent 2>/dev/null; do
# 	echo "Waiting..."
# 	sleep 1
# done


# # Trap SIGTERM and SIGINT signals and gracefully exit the script
# trap 'echo "Caught signal, stopping MariaDB service..."; service mariadb stop; exit 0' SIGTERM SIGINT

# # Start MariaDB server in the foreground
# echo "Starting MariaDB server in the foreground..."
# # killall mysqld
# exec mysqld

