#!/bin/bash

# Navigate to the Django project directory
cd /usr/src/app

# Create migrations for changes in models
echo "Creating migrations..."
python transcendence_back/manage.py makemigrations --noinput

# Apply migrations to the database
echo "Applying migrations..."
python transcendence_back/manage.py migrate --noinput

# Apply migrations for django-celery-results
echo "Applying django-celery-results migrations..."
python transcendence_back/manage.py migrate django_celery_results --noinput

# Collect static files
echo "Collecting static files..."
python transcendence_back/manage.py collectstatic --noinput

# Optionally, create a superuser if none exists (for initial setup)
echo "Creating superuser if none exists..."
python transcendence_back/manage.py createsuperuser --noinput || true

# Start Celery worker in the background with a unique nodename
echo "Starting Celery worker..."
celery -A transcendence_back.celery.app worker -n worker1@%h --loglevel=info --detach

# Start Celery beat in the background (if you use scheduled tasks)
echo "Starting Celery beat..."
celery -A transcendence_back.celery.app beat --loglevel=info --detach

# Start the Django server
echo "Starting the Django server..."
python transcendence_back/manage.py runserver 0.0.0.0:8280
