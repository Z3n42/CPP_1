#!/bin/bash

# Load environment variables
MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}
MYSQL_DATABASE=${MYSQL_DATABASE}
MYSQL_USER=${MYSQL_USER}
MYSQL_PASSWORD=${MYSQL_PASSWORD}

# Enable the shell option to exit immediately if a pipeline returns a non-zero status
set -e
set -o pipefail

# # Load environment variables from the .env file
# if [[ -f /.env ]]; then
#   echo "Loading environment variables from .env..."
#   # Enable the shell option to mark variables which are modified or created for export
#   set -o allexport
#   # Source the .env file
#   source /Users/ingonzal/42/cursus/6Ring/Inception/.env
#   # Disable the shell option to mark variables which are modified or created for export
#   set +o allexport
# else
#   echo "File .env not found, skipping..."
# fi

# Create necessary directories for MariaDB
for dir in /var/run/mysqld /run/mysqld; do
  if [ ! -d "$dir" ]; then
    echo "Creating directory $dir..."
    # Create the directory and any necessary parent directories
    mkdir -p "$dir"
  fi
done

# Initialize the database if not present
if [ ! -d /var/lib/mysql/mysql ]; then
  echo "Initializing database..."
  # Initialize the MariaDB database as the root user
  mysql_install_db --user=root
fi

# Start MariaDB service in the background
echo "Starting MariaDB service..."
service mariadb start

# Wait until MariaDB server is online
echo "Waiting for MariaDB server to be online..."
while ! mysqladmin ping -hlocalhost --silent 2>/dev/null; do
 sleep 1
done

# Execute initial SQL queries
if [[ -f /mariadb-conf.d/init.sql ]]; then
  echo "Executing initial SQL queries..."
  # Execute the SQL queries in the init.sql file as the root user
  mysql -u root < /mariadb-conf.d/init.sql
else
  echo "File /mariadb-conf.d/init.sql not found, skipping..."
fi

# Stop MariaDB service
echo "Stopping MariaDB service..."
service mariadb stop

# Wait until MariaDB server has stopped
echo "Waiting for MariaDB server to stop..."
while mysqladmin ping -hlocalhost --silent 2>/dev/null; do
 sleep 1
done

# Trap SIGTERM and SIGINT signals and gracefully exit the script
trap 'echo "Caught signal, stopping MariaDB service..."; service mariadb stop; exit 0' SIGTERM SIGINT

# Start MariaDB server in the foreground
echo "Starting MariaDB server in the foreground..."
exec mysqld

