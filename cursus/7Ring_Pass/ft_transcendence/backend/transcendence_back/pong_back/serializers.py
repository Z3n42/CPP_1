from django.utils.translation import gettext as _
from django.contrib.auth.password_validation import validate_password
from rest_framework.exceptions import ValidationError
from rest_framework import serializers
from .models import Player, Game
from rest_framework_simplejwt.serializers import TokenObtainPairSerializer
from .helper import get_otp

class MyTokenObtainPairSerializer(TokenObtainPairSerializer):
    @classmethod
    def get_token(cls, Player):
        token = super().get_token(Player)

        # Custom claims
        token['email'] = Player.email
        token['user_id'] = Player.id

        return token

class OTPVerificationSerializer(serializers.Serializer):
    email = serializers.EmailField(required=True)
    otp = serializers.IntegerField(required=True)

    def validate(self, data):
        email = data.get('email')
        otp_provided = data.get('otp')

        try:
            user = Player.objects.get(email=email)
            otp_stored = get_otp(user.id)
            if otp_stored and int(otp_stored) == otp_provided:
                data['user'] = user
            else:
                raise serializers.ValidationError(_('Invalid or expired OTP'))
        except Player.DoesNotExist:
            raise serializers.ValidationError(_('User not found'))

        return data

class UserSerializer(serializers.ModelSerializer):
    password = serializers.CharField(write_only=True)
    password2 = serializers.CharField(write_only=True, label=_("confirm_password"))
    customAvatar = serializers.ImageField(required=False)
    chatRooms = serializers.ListField(child=serializers.CharField(max_length=100), required=False, allow_empty=True)

    class Meta:
        model = Player
        fields = ('id', 'email', 'username', 'password', 'password2', 'wins', 'games', 'add_date',
                  'modified_date', 'is_active', 'is_online', 'is_staff', 'is_superuser', 'is_ft',
                  'avatar', 'putAvatar', 'customAvatar', 'friends', 'blocked', 'is_2fa', 'last_activity', 'chatRooms')

        extra_kwargs = {
            'password': {'write_only': True},
            'password2': {'write_only': True},
            'add_date': {'read_only': True},
            'modified_date': {'read_only': True},
            'customAvatar': {'required': False}
            }

    def validate(self, value):
        if 'password' in value:
            if 'password2' not in value:
                raise serializers.ValidationError({'confirm_password': _('Confirm password is required')})
            else:
                if value['password'] != value['password2']:
                    raise serializers.ValidationError({'confirm_password': _('Passwords not match')})
        return value

    def validate_password(self, value):
        try:
            validate_password(value)
        except ValidationError as exc:
            raise serializers.ValidationError(str(exc))
        return value

    def create(self, validated_data):
        user = Player(
            email=validated_data.get('email'),
            username=validated_data.get('username'),
            avatar=validated_data.get('avatar', 0),
        )
        password = validated_data.get('password')
        if password:
            user.set_password(password)
        user.save()
        return user

    def update(self, instance, validated_data):
        for attr, value in validated_data.items():
            if attr in ['email', 'username', 'wins', 'games', 'avatar', 'customAvatar',
                        'is_active', 'is_online', 'friends', 'blocked', 'is_2fa', 'last_activity', 'chatRooms']:
                setattr(instance, attr, value)

        password = validated_data.get('password')
        if password:
            instance.set_password(password)

        instance.save()
        return instance

class GameSerializer(serializers.ModelSerializer):
    player_x = UserSerializer()
    player_o = UserSerializer()
    winner = UserSerializer()

    class Meta:
        model = Game
        fields = '__all__'