from celery import shared_task
from django.utils import timezone
from .models import Player
from datetime import timedelta
from celery.utils.log import get_task_logger

logger = get_task_logger(__name__)

@shared_task
def update_online_status():
    logger.info('Online status review...')
    timeout = timedelta(minutes=11)
    now = timezone.now()

    offline_users = Player.objects.filter(is_online=True, last_activity__lt=now - timeout)
    offline_users.update(is_online=False)
