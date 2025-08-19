from django.db import models
from django.utils import timezone
from django.contrib.auth.models import AbstractBaseUser, PermissionsMixin, BaseUserManager
from django.utils.translation import gettext_lazy as _
from .helper import getPin
import os
from django.conf import settings
from PIL import Image
from io import BytesIO
from django.core.files.uploadedfile import InMemoryUploadedFile, SimpleUploadedFile
from django.core.files.storage import default_storage
import shutil

def user_directory_path(instance, filename):
    # file will be uploaded to MEDIA_ROOT/user_<id>/<filename>
    return 'user_{0}/{1}'.format(instance.id, filename)

# Custom Manager for the Player model
class PlayerManager(BaseUserManager):
    def create_user(self, email, username, avatar=0, password=None, games=0):
        if not email:
            raise ValueError(_('Users must have an email address'))
        if not username:
            raise ValueError(_('Users must have an username'))
        user = self.model(
            email=self.normalize_email(email),
            username=username,
            avatar=avatar,
            games=games
        )
        user.set_password(password)
        user.save(using=self._db)
        return user

    def create_superuser(self, email, password, username=None, games=0):
        username = 'dev_master' if username is None else username
        user = self.create_user(email=email, username=username, password=password, games=games)
        user.is_superuser = True
        user.is_staff = True
        user.is_active = True
        user.save(using=self._db)
        return user

# Custom Player model for authentication
class Player(AbstractBaseUser, PermissionsMixin):
    email = models.EmailField(_('email address'), unique=True, max_length=255)
    username = models.CharField(_('username'), unique=True, max_length=150)
    wins = models.IntegerField(_('wins'), default=0)
    games = models.IntegerField(_('games'), default=0)
    add_date = models.DateTimeField(_('date added'), default=timezone.now, editable=False)
    modified_date = models.DateTimeField(_('date modified'), default=timezone.now, editable=False)
    is_active = models.BooleanField(_('active'), default=False)
    is_online = models.BooleanField(_('online'), default=False)
    is_staff = models.BooleanField(_('staff status'), default=False)
    is_superuser = models.BooleanField(_('superuser status'), default=False)
    is_ft = models.BooleanField(_('ft status'), default=False)
    avatar = models.IntegerField(_('avatar'), default=0)
    putAvatar = models.BooleanField(_('Put avatar'), default=False)
    customAvatar = models.ImageField(_('customAvatar'), upload_to=user_directory_path, default=None, blank=True, null=True)
    friends = models.ManyToManyField('self', blank=True, symmetrical=False, related_name='friends_player')
    blocked = models.ManyToManyField('self', blank=True, symmetrical=False, related_name='blocked_player')
    is_2fa = models.BooleanField(_('2fa status'), default=False)
    last_activity = models.DateTimeField(default=timezone.now)
    chatRooms = models.JSONField(blank=True, null=True, verbose_name=_('Chat Rooms'))

    objects = PlayerManager()

    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = ['username']

    def save(self, *args, **kwargs):
        # If it's a new instance, set add_date.
        if not self.id:
            self.add_date = timezone.now()
        # Update modified_date on every save.
        self.modified_date = timezone.now()

        if self.putAvatar:
            # Only create or delete the user_folder_path when uploading an image
            if self.customAvatar and hasattr(self.customAvatar, 'file'):
                # Build the user's folder path
                user_folder_path = os.path.join(settings.MEDIA_ROOT, f'user_{self.id}')

                # If the folder exists, remove it
                if os.path.exists(user_folder_path):
                    shutil.rmtree(user_folder_path)

                # Create the folder again
                os.makedirs(user_folder_path, exist_ok=True)

                # Process the Put avatar image
                img = Image.open(self.customAvatar)
                img.thumbnail((512, 512), Image.LANCZOS)
                img_format = 'PNG'
                img_io = BytesIO()
                img.save(img_io, format=img_format)

                # Create a new InMemoryUploadedFile
                img_file = InMemoryUploadedFile(
                    img_io, None, f'{self.username}_customAvatar.png', 'image/png',
                    img_io.tell(), None
                )

                self.putAvatar = False
                self.customAvatar = img_file

        # Override the base class's save method to include our custom save logic,
        # while still preserving the original save functionality from Django's models.Model.
        super(Player, self).save(*args, **kwargs)

    def __str__(self):
        return self.email

class Game(models.Model):
    player_x = models.ForeignKey(Player, related_name='player_x', null=True, on_delete=models.SET_NULL)
    player_x_points = models.IntegerField(default=0)
    player_o = models.ForeignKey(Player, related_name='player_o', null=True, on_delete=models.SET_NULL)
    player_o_points = models.IntegerField(default=0)
    winner = models.ForeignKey(Player, related_name='winner', null=True, on_delete=models.SET_NULL)
    room_name = models.CharField(max_length=100)
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f"Game in room {self.room_name}"