# **************************************************************************** #

#                                                                              #
#                                                         :::      ::::::::    #
#    cert.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 18:49:55 by ingonzal          #+#    #+#              #
#    Updated: 2023/09/16 18:57:37 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

echo "Linux release ==>"
cat /etc/*-release
echo -e "<== Linux release END\n"

# Directory where certificates will be stored
cert_dir="/tmp"
# mkdir $cert_dir

# Check if certificates already exist
if [ ! -f "$cert_dir/ingonzal.42.fr.crt" ] && [ ! -f "$cert_dir/ingonzal.42.fr.key" ]; then
    echo "Creating self-signed SSL certificates..."

    # Generate self-signed SSL certificates
    openssl req -new -newkey rsa:2048 -days 365 -nodes -x509 \
        -subj "/C=US/ST=California/L=San Francisco/O=Example/CN=localhost" \
        -keyout "$cert_dir/ingonzal.42.fr.key" -out "$cert_dir/ingonzal.42.fr.crt" &&

    echo "Certificates created."

    # Move certificates to their final location
    mv "$cert_dir/ingonzal.42.fr.crt" /etc/ssl/
    mv "$cert_dir/ingonzal.42.fr.key" /etc/ssl/

    echo "Certificates moved to their final location."

	# Change permissions of the certificate files
    chmod 644 /etc/ssl/ingonzal.42.fr.crt
    chmod 600 /etc/ssl/ingonzal.42.fr.key

    echo "Permissions changed for the certificate files."
else
    echo "Certificates already exist in $cert_dir."
    # rm "$cert_dir/ingonzal.42.fr.key" && "$cert_dir/ingonzal.42.fr.crt"
fi

# Configure NGINX to use the certificates
echo "Creating nginx configuration"
# cat <<EOF > /etc/nginx/sites-available/default
# server {
#     listen 443 ssl;
#     listen [::]:443 ssl;
#     server_name ingonzal.42.fr www.ingonzal.42.fr;

# 	root /var/www/inception/wordpress;
# 	index index.php;

#     # ssl_protocols TLSv1 TLSv1.1 TLSv1.2 TLSv1.3;
#     ssl_protocols TLSv1.3;
#     # ssl_ciphers ALL:!aNULL:!ADH:!eNULL:!LOW:!EXP:RC4+RSA:+HIGH:+MEDIUM;

#     keepalive_timeout 75;

#     ssl_certificate /etc/ssl/ingonzal.42.fr.crt;
#     ssl_certificate_key /etc/ssl/ingonzal.42.fr.key;
#     ssl_session_timeout 5m;

#     # add_header Strict-Transport-Security "max-age=7200";

#     location / {
# 		try_files $uri $uri/ /index.php?$args;
# 	}

#     # error_page 500 502 503 504 /50x.html;
#     # location = /50x.html {
#     #     root /usr/share/nginx/html;
#     # }

#     location ~ \.php$ {
# 		include snippets/fastcgi-php.conf;
#         fastcgi_pass wordpress:9000;
#         # fastcgi_index index.php;
# 		include fastcgi_params;
#         fastcgi_param SCRIPT_FILENAME /var/www/inception/wordpress$fastcgi_script_name;
#     }
# }
# # }
# EOF

# echo "Reloading NGINX..."
# service nginx reload

chmod 755 /var/www/inception/wordpress
chown -R www-data:www-data /var/www/inception/wordpress

# Start the NGINX server
echo "Starting NGINX server..."
nginx -g 'daemon off;'

#!/bin/bash
#
# This sets up Let's Encrypt SSL certificates and automatic renewal 
# using certbot: https://certbot.eff.org
#
# - Run this script as root.
# - A webserver must be up and running.
#
# Certificate files are placed into subdirectories under
# /etc/letsencrypt/live/*.
# 
# Configuration must then be updated for the systems using the 
# certificates.
#
# The certbot-auto program logs to /var/log/letsencrypt.
#

# set -o nounset
# set -o errexit

# May or may not have HOME set, and this drops stuff into ~/.local.
# export HOME="/root"
# export PATH="${PATH}:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

# No package install yet.
# wget https://dl.eff.org/certbot-auto
# chmod a+x certbot-auto
# mv certbot-auto /usr/local/bin

# Install the dependencies.
# certbot-auto --noninteractive --os-packages-only

# Set up config file.
# mkdir -p /etc/letsencrypt
# cat > /etc/letsencrypt/cli.ini <<EOF
# # Uncomment to use the staging/testing server - avoids rate limiting.
# # server = https://acme-staging.api.letsencrypt.org/directory

# # Use a 4096 bit RSA key instead of 2048.
# rsa-key-size = 4096

# # Set email and domains.
# email = admin@example.com
# domains = example.com, www.example.com

# # Text interface.
# text = True
# # No prompts.
# non-interactive = True
# # Suppress the Terms of Service agreement interaction.
# agree-tos = True

# # Use the webroot authenticator.
# authenticator = webroot
# webroot-path = /var/www/html
# EOF

# Obtain cert.
# certbot --nginx -d example.com -d www.example.com

# Set up daily cron job.
#CRON_SCRIPT="/etc/cron.daily/certbot-renew"

#cat > "${CRON_SCRIPT}" <<EOF
##!/bin/bash
##
## Renew the Let's Encrypt certificate if it is time. It won't do anything if
## not.
##
## This reads the standard /etc/letsencrypt/cli.ini.
##

## May or may not have HOME set, and this drops stuff into ~/.local.
#export HOME="/root"
## PATH is never what you want it it to be in cron.
#export PATH="\${PATH}:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

#certbot-auto --no-self-upgrade certonly

## If the cert updated, we need to update the services using it. E.g.:
#if service --status-all | grep -Fq 'apache2'; then
#  service apache2 reload
#fi
#if service --status-all | grep -Fq 'httpd'; then
#  service httpd reload
#fi
#if service --status-all | grep -Fq 'nginx'; then
#  service nginx reload
#fi
#EOF
#chmod a+x "${CRON_SCRIPT}"
