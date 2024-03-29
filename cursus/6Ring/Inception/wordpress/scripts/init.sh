#!/bin/bash

# Enable the shell option to exit immediately if a pipeline returns a non-zero status
# set -e
# set -o pipefail

# Install wp-cli
curl -OsS https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
echo "Download wp-cli"

# Create directory for PHP if it doesn't exist
if [ ! -d /run/php ]; then
	echo "Create run"
    mkdir -p /run/php
fi

echo "Check $WP_DIR"
# Create directory for WordPress if it doesn't exist
if [ ! -d "$WP_DIR" ]; then
   echo "Create && permissions $WP_DIR"
   mkdir -p "$WP_DIR"
   # Assign appropriate permissions
   chown -R www-data:www-data $WP_DIR
   find "$WP_DIR" -type d -exec chmod 755 {} \;
   find "$WP_DIR" -type f -exec chmod 644 {} \;
fi

# Check if WordPress core files are present
if [ ! -f "$WP_DIR/wp-config.php" ]; then
    # Install WordPress if not already installed
	echo "WordPress not already installed"
	wp core download --version=6.4 --path=${WP_DIR} --allow-root
	# Move manually to WP_DIR because --path flag is broken
	cd ${WP_DIR}
	echo "WordPress core download"
	wp config create --dbname=${MYSQL_DATABASE} --dbhost=${WORDPRESS_DB_HOST} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} --allow-root
	echo "WordPress config create"
	wp core install --url=${WORDPRESS_URL} --title=${WORDPRESS_TITLE} --admin_user=${WORDPRESS_ADMIN_USER} --admin_password=${WORDPRESS_ADMIN_PASSWORD} --admin_email=${WORDPRESS_ADMIN_EMAIL} --allow-root
	echo "WordPress core install"
	wp user create ${WORDPRESS_USER} ${WORDPRESS_USER_EMAIL} --role=${WORDPRESS_USER_ROLE} --user_pass=${WORDPRESS_USER_PASSWORD} --allow-root

else
    echo "WordPress core files are already present at $WP_DIR."
fi

# # Add debugging configuration to wp-config.php if not present
# echo "Check debugging configuration file => $WP_CONFIG"
# if [ -f "$WP_CONFIG" ]; then
#     # Ensure that the debugging lines do not exist before adding them
#     if ! grep -q "define( 'WP_DEBUG'" "$WP_CONFIG"; then
#         echo "Adding debugging configuration to $WP_CONFIG"
#         sed -i "/^\/\* That's all, stop editing! Happy publishing. \*\//i\
# define( 'WP_DEBUG', true );\
# define( 'WP_DEBUG_LOG', true );\
# define( 'WP_DEBUG_DISPLAY', false );\
# @ini_set( 'display_errors', 0 );\
# " "$WP_CONFIG"
#     fi
# fi

# Start php-fpm
echo "Starting php-fpm..."
exec php-fpm7.4 -F
