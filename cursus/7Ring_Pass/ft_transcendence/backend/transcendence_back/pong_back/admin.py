from django.contrib import admin
from django.contrib.auth.admin import UserAdmin
from django.contrib.auth.forms import UserChangeForm, UserCreationForm
from django.utils.translation import gettext_lazy as _

from .models import Player, Game

class PlayerChangeForm(UserChangeForm):
    class Meta(UserChangeForm.Meta):
        model = Player
        fields = '__all__'

class PlayerCreationForm(UserCreationForm):
    class Meta(UserCreationForm.Meta):
        model = Player
        fields = ('email',)

class PlayerAdmin(UserAdmin):
    form = PlayerChangeForm
    add_form = PlayerCreationForm
    model = Player
    list_display = ('email', 'username', 'games', 'wins', 'avatar', 'customAvatar', 'is_staff',
                    'is_active', 'is_online', 'is_superuser', 'is_ft', 'is_2fa')
    list_filter = ('is_staff', 'is_active', 'is_online', 'is_ft')
    fieldsets = (
        (None, {'fields': ('email', 'username', 'password', 'wins', 'games', 'avatar', 'customAvatar')}),
        (_('Permissions'), {'fields': ('is_staff', 'is_active', 'is_online', 'is_superuser', 'is_ft')}),
    )
    add_fieldsets = (
        (None, {
            'classes': ('wide',),
            'fields': ('email', 'username', 'password1', 'password2', 'wins', 'games', 'avatar', 'customAvatar'),
        }),
    )
    search_fields = ('email', 'username')
    ordering = ('email', 'username')

# Registramos el modelo Player con la clase PlayerAdmin personalizada
admin.site.register(Player, PlayerAdmin)

admin.site.register(Game)