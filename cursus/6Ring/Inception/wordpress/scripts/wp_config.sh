#!/bin/bash
wp core download --path=${WP_DIR} --allow-root
echo "WordPress core download"
wp config create --path=${WP_DIR} --dbname=${MYSQL_DATABASE} --dbhost=${WORDPRESS_DB_HOST} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} --allow-root
echo "WordPress config create"
wp core install --path=${WP_DIR} --url=${WORDPRESS_URL} --title=${WORDPRESS_TITLE} --admin_user=${WORDPRESS_ADMIN_USER} --admin_password=${WORDPRESS_ADMIN_PASSWORD} --admin_email=${WORDPRESS_ADMIN_EMAIL} --allow-root
echo "WordPress core install"
wp user create ${WORDPRESS_USER} ${WORDPRESS_USER_EMAIL} --role=${WORDPRESS_USER_ROLE} --user_pass=${WORDPRESS_USER_PASSWORD} --path=${WP_DIR} --allow-root

