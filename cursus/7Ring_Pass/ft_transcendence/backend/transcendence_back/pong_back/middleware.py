from django.utils import timezone
from .models import Player
import logging
from .helper import clear_user_cache

logger = logging.getLogger(__name__)

class UpdateLastActivityMiddleware:
    def __init__(self, get_response):
        self.get_response = get_response

    def __call__(self, request):
        response = self.get_response(request)
        if request.user.is_authenticated:
            Player.objects.filter(pk=request.user.pk).update(last_activity=timezone.now())
            clear_user_cache(request.user.id)
            logger.info(f'{request.user.username} user last_activity update: {timezone.now()}')
        return response