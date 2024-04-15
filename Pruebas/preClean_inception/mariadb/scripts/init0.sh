#!/bin/bash

# Habilitar la opción de shell para salir inmediatamente si una tubería devuelve un estado distinto de cero
set -e
set -o pipefail

# Crear los directorios necesarios para MariaDB
mkdir -p /var/run/mysqld /run/mysqld

# Inicializar la base de datos si no está presente
if [ ! -d /var/lib/mysql/mysql ]; then
  echo "Inicializando la base de datos..."
  mysql_install_db --user=root
fi

# Iniciar el servicio MariaDB en segundo plano
echo "Iniciando el servicio MariaDB..."
service mariadb start

# Esperar hasta que el servidor MariaDB esté en línea
echo "Esperando a que el servidor MariaDB esté en línea..."
while ! mysqladmin ping -hlocalhost --silent 2>/dev/null; do
 sleep 1
done

# Ejecutar las consultas SQL iniciales
if [[ -f /mariadb-conf.d/init.sql ]]; then
  echo "Ejecutando las consultas SQL iniciales..."
  # Crear un archivo SQL temporal con las variables de entorno sustituidas
  envsubst < /mariadb-conf.d/init.sql > /tmp/init.sql
  # Ejecutar las consultas SQL en el archivo temporal
  mysql -u root -p${MYSQL_ROOT_PASSWORD} < /tmp/init.sql
  # Eliminar el archivo temporal
  rm /tmp/init.sql
fi

# Atrapar las señales SIGTERM y SIGINT y detener el servicio MariaDB con gracia
trap 'echo "Señal capturada, deteniendo el servicio MariaDB..."; service mariadb stop; exit 0' SIGTERM SIGINT

# Iniciar el servidor MariaDB en primer plano
echo "Iniciando el servidor MariaDB en primer plano..."
exec mysqld

