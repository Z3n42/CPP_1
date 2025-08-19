from celery import Celery
from celery.schedules import crontab
from django.conf import settings

app = Celery('transcendence_back')

app.config_from_object(settings, namespace='CELERY')

app.autodiscover_tasks()

app.conf.beat_schedule = {
    'update_online_status_every_minute': {
        'task': 'pong_back.tasks.update_online_status',
        'schedule': crontab(minute='*/3'),
    },
}

