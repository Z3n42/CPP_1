from django.utils.translation import gettext as _
from pong_back.serializers import MyTokenObtainPairSerializer, UserSerializer, OTPVerificationSerializer, GameSerializer
from rest_framework_simplejwt.views import TokenObtainPairView
from .models import Player, Game
from rest_framework.permissions import AllowAny, IsAuthenticated
from rest_framework.decorators import api_view, permission_classes
from rest_framework.response import Response
from rest_framework.parsers import JSONParser, MultiPartParser, FormParser
from rest_framework import status
from rest_framework.views import APIView
from rest_framework_simplejwt.tokens import RefreshToken, AccessToken
from rest_framework_simplejwt.exceptions import TokenError, InvalidToken
from django.contrib.auth import get_user_model
import requests
from django.http import HttpResponseRedirect
from django.core.exceptions import ValidationError, ObjectDoesNotExist
from rest_framework_simplejwt.tokens import OutstandingToken, BlacklistedToken
from rest_framework.schemas import AutoSchema
from rest_framework.compat import coreapi, coreschema
from .customSchema import CustomAutoSchema
from django.core.cache import cache
import os
from .helper import getPin, send_otp_email, save_otp, clear_user_cache
from django.db.models import Q
import logging
from urllib.parse import urlsplit

logger = logging.getLogger(__name__)

class MyTokenObtainPairView(TokenObtainPairView):
    serializer_class = MyTokenObtainPairSerializer
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "password",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="User password required to obtain token."
            )
        ]
    )

    def post(self, request, *args, **kwargs):
        logger.info("Attempting to obtain token for user.")
        response = super().post(request, *args, **kwargs)
        if response.status_code == 200:
            access_token = response.data['access']
            refresh_token_str = response.data['refresh'] 
            token = AccessToken(access_token)
            user_id = token['user_id'] 

            User = get_user_model()
            try:
                user = User.objects.get(id=user_id)
                tokens = OutstandingToken.objects.filter(user_id=user_id)
                refresh_token = RefreshToken(refresh_token_str)
                refresh_jti = refresh_token['jti']
                for t in tokens:
                     if str(t.jti) != refresh_jti:
                        BlacklistedToken.objects.get_or_create(token=t)
                user.is_online = True
                user.chatRooms = []
                user.save()
                clear_user_cache(user.id)
                if user.is_2fa == True:
                    save_otp(user_id, int(getPin()))
                    try:
                        send_otp_email(user.email, user_id)
                    except ValidationError as e:
                        logger.error(f"Validation error while sending OTP email: {e}")
                        return Response({'error': str(e)}, status=status.HTTP_404_NOT_FOUND)
                    logger.info("OTP email sent successfully.")
                    return Response({'redirectUrl': 'http://localhost:4200/otp'}, status=status.HTTP_200_OK)
            except:
                logger.error("User not found.")
                error_details = {'error': _('User not found')}
                return Response(error_details, status=status.HTTP_404_NOT_FOUND)
        return response


class RegisterView(APIView):
    parser_classes = [JSONParser, MultiPartParser, FormParser]
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "email",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Email address for registration."
            ),
            coreapi.Field(
                "username",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Username for registration."
            ),
            coreapi.Field(
                "password",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Password for registration."
            ),
            coreapi.Field(
                "password2",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Password confirmation for registration."
            ),
            coreapi.Field(
                "avatar",
                required=False,
                location="form",
                schema=coreschema.Integer(),
                description="Avatar number for registration."
            )
        ]
    )

    def post(self, request):
        logger.info("Attempting to register a new user.")
        email = request.data.get('email')
        username = request.data.get('username')
        if Player.objects.filter(email=email).exists():
            logger.warning("Email already registered.")
            return Response({'error': _('Email already registered')}, status=status.HTTP_400_BAD_REQUEST)
        if Player.objects.filter(username=username).exists():
            logger.warning("Username already in use.")
            return Response({'error': _('Username already in use')}, status=status.HTTP_400_BAD_REQUEST)
        else:
            serializer = UserSerializer(data=request.data)

        if serializer.is_valid():
            user = serializer.save()
            clear_user_cache(user.id)
            save_otp(user.id, int(getPin())) 
            try:
                send_otp_email(email, user.id)
            except ValidationError as e:
                logger.error(f"Validation error while sending OTP email: {e}")
                return Response({'error': str(e)}, status=status.HTTP_404_NOT_FOUND)
            logger.info("User registered and OTP email sent successfully.")
            return Response({'redirectUrl': 'http://localhost:4200/otp'}, status=status.HTTP_201_CREATED)
        logger.error(f"Error in user registration: {serializer.errors}")
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


class VerifyOTPView(APIView):
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "email",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Email address for registration."
            ),
            coreapi.Field(
                "OTP",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Otp for registration."
            )
        ]
    )

    def post(self, request):
        logger.info("Attempting to verify OTP.")
        serializer = OTPVerificationSerializer(data=request.data)
        if serializer.is_valid():
            user = serializer.validated_data['user']
            user.is_active = True
            user.save()
            forgot = True if request.headers.get('forgot') == 'true' else False
            if user.is_2fa == True or user.is_ft == True or forgot == True:
                user.is_online = True
                user.save()
                refresh = RefreshToken.for_user(user)
                clear_user_cache(user.id)
                logger.info("OTP verified and user activated successfully.")
                return Response({
                    'refresh': str(refresh),
                    'access': str(refresh.access_token),
                    }, status=status.HTTP_200_OK)
            logger.info("User verified and activated successfully.")
            return Response({'message': 'User verified and activated successfully.'}, status=status.HTTP_200_OK)
        else:
            logger.error(f"Error in OTP verification: {serializer.errors}")
            return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)


class SendOTPView(APIView):
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "email",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Email address for registration."
            ),
        ]
    )
    def post(self, request):
        logger.info("Attempting to send OTP.")
        email = request.data.get('email')
        try:
            user = Player.objects.get(email=email)
        except Player.DoesNotExist:
            logger.error("User not found.")
            return Response({'error': 'User not found.'}, status=status.HTTP_404_NOT_FOUND)

        try:
            save_otp(user.id, int(getPin()))
            send_otp_email(email, user.id)
        except ValidationError as e:
            logger.error(f"Validation error while sending OTP email: {e}")
            return Response({'error': str(e)}, status=status.HTTP_404_NOT_FOUND)
        logger.info("OTP sent successfully.")
        return Response({'message': 'OTP sending.'}, status=status.HTTP_200_OK)

class UserView(APIView):
    permission_classes = (IsAuthenticated,)
    parser_classes = [JSONParser, MultiPartParser, FormParser]
    schema = CustomAutoSchema()

    def get(self, request):
        logger.info("Fetching user data.")
        cache_key = f"user_data_{request.user.id}"
        cached_user_data = cache.get(cache_key)
        if cached_user_data:
            logger.info("User data fetched from cache.")
            return Response(cached_user_data, status=status.HTTP_200_OK)
        serializer = UserSerializer(request.user, many=False)
        cache.set(cache_key, serializer.data, timeout=3600)
        logger.info("User data fetched from database and cached.")
        return Response(serializer.data, status=status.HTTP_200_OK)

    def put(self, request):
        logger.info("Attempting to update user profile.")
        user = request.user
        serializer = UserSerializer(user, data=request.data, partial=True)
        if serializer.is_valid():
            if 'username' in serializer.validated_data:
                new_username = serializer.validated_data['username']
                if Player.objects.filter(username=new_username).exists() and new_username != user.username:
                    logger.warning("Username already in use.")
                    return Response({'error': _('Username already in use')}, status=status.HTTP_400_BAD_REQUEST)
            if 'customAvatar' in request.FILES:
                user.putAvatar = True
            user = serializer.save()
            clear_user_cache(user.id)
            logger.info("User profile updated successfully.")
            return Response(serializer.data, status=status.HTTP_200_OK)
        logger.error("Failed to update user profile. Errors: %s", serializer.errors)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class AddFriendView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Username of the friend you want to add."
            )
        ]
    )

    def post(self, request):
        user = request.user
        friend_username = request.data.get('username')
        if not friend_username:
            logger.warning("Username required to add a friend.")
            return Response({'error': _('Username required.')}, status=status.HTTP_400_BAD_REQUEST)

        try:
            friend = Player.objects.get(username=friend_username)
        except Player.DoesNotExist:
            logger.warning("Friend not found: %s", friend_username)
            return Response({'error': _('Friend not found.')}, status=status.HTTP_404_NOT_FOUND)

        if friend == user:
            logger.warning("User attempted to add themselves as a friend.")
            return Response({'error': _('You cannot add yourself.')}, status=status.HTTP_400_BAD_REQUEST)

        if friend in user.friends.all():
            logger.warning("Friend already added: %s", friend_username)
            return Response({'error': _('Friend already added.')}, status=status.HTTP_400_BAD_REQUEST)

        user.friends.add(friend)
        user.save()
        clear_user_cache(user.id)
        logger.info("Friend added successfully: %s", friend_username)
        return Response({'message': _('Friend added successfully.')}, status=status.HTTP_200_OK)

class RemoveFriendView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Username of the friend you want to remove."
            )
        ]
    )

    def post(self, request):
        user = request.user
        friend_username = request.data.get('username')
        if not friend_username:
            logger.warning("Username required to remove a friend.")
            return Response({'error': _('Username required.')}, status=status.HTTP_400_BAD_REQUEST)

        try:
            friend = user.friends.get(username=friend_username)
        except Player.DoesNotExist:
            logger.warning("Friend not in user's friend list: %s", friend_username)
            return Response({'error': _('Friend not in your friend list.')}, status=status.HTTP_404_NOT_FOUND)

        user.friends.remove(friend)
        user.save()
        clear_user_cache(user.id)
        logger.info("Friend removed successfully: %s", friend_username)
        return Response({'message': _('Friend removed successfully.')}, status=status.HTTP_200_OK)

class UserFriendsView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="path",
                description="Username to check if they are friends."
            )
        ]
    )

    def get(self, request):
        user = request.user
        friends_usernames = user.friends.values_list('username', flat=True)
        logger.info("Retrieved friends list for user: %s", user.username)
        return Response({'friends': list(friends_usernames)})

class IsFriendView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="path",
                description="Username of the user to check."
            )
        ]
    )

    def get(self, request, username):
        if not Player.objects.filter(username=username).exists():
            logger.warning("User does not exist: %s", username)
            return Response({'message': 'The user does not exist.'}, status=status.HTTP_404_NOT_FOUND)

        user = request.user
        is_friend = user.friends.filter(username=username).exists()
        if is_friend:
            logger.info("User is a friend: %s", username)
            return Response({'message': _('The user is a friend.')}, status=status.HTTP_200_OK)
        else:
            logger.info("User is not a friend: %s", username)
            return Response({'message': _('The user is not a friend.')}, status=status.HTTP_404_NOT_FOUND)

class AddBlockedView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Username of user you want to Block."
            )
        ]
    )

    def post(self, request):
        user = request.user
        blocked_username = request.data.get('username')
        if not blocked_username:
            logger.warning("Username required to block a user.")
            return Response({'error': _('Username required.')}, status=status.HTTP_400_BAD_REQUEST)

        try:
            blocked = Player.objects.get(username=blocked_username)
        except Player.DoesNotExist:
            logger.warning("User not found to block: %s", blocked_username)
            return Response({'error': _('User not found.')}, status=status.HTTP_404_NOT_FOUND)

        if blocked == user:
            logger.warning("User attempted to block themselves.")
            return Response({'error': _('You cannot blocked yourself.')}, status=status.HTTP_400_BAD_REQUEST)

        if blocked in user.blocked.all():
            logger.warning("User already blocked: %s", blocked_username)
            return Response({'error': _('User already blocked.')}, status=status.HTTP_400_BAD_REQUEST)

        user.blocked.add(blocked)
        user.save()
        clear_user_cache(user.id)
        logger.info("User blocked successfully: %s", blocked_username)
        return Response({'message': _('User blocked successfully.')}, status=status.HTTP_200_OK)

class RemoveBlockedView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Username of user you want to Unblock."
            )
        ]
    )

    def post(self, request):
        user = request.user
        blocked_username = request.data.get('username')
        if not blocked_username:
            logger.warning("Username required to unblock a user.")
            return Response({'error': _('Username required.')}, status=status.HTTP_400_BAD_REQUEST)

        try:
            blocked = user.blocked.get(username=blocked_username)
        except Player.DoesNotExist:
            logger.warning("User not found to unblock: %s", blocked_username)
            return Response({'error': _('User not found.')}, status=status.HTTP_404_NOT_FOUND)

        user.blocked.remove(blocked)
        user.save()
        clear_user_cache(user.id)
        logger.info("User unblocked successfully: %s", blocked_username)
        return Response({'message': _('User unblocked successfully.')}, status=status.HTTP_200_OK)

class UserBlockedView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="path",
                description="Username to check if they are blocked."
            )
        ]
    )

    def get(self, request):
        user = request.user
        blocked_usernames = user.blocked.values_list('username', flat=True)
        logger.info("Retrieved blocked users list for user: %s", user.username)
        return Response({'blocked': list(blocked_usernames)})

class IsBlockedView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="path",
                description="Username of the user to check."
            )
        ]
    )

    def get(self, request, username):
        if not Player.objects.filter(username=username).exists():
            logger.warning("User does not exist: %s", username)
            return Response({'message': 'The user does not exist.'}, status=status.HTTP_404_NOT_FOUND)

        user = request.user
        is_blocked = user.blocked.filter(username=username).exists()
        if is_blocked:
            logger.info("User is blocked: %s", username)
            return Response({'message': _('The user is blocked.')}, status=status.HTTP_200_OK)
        else:
            logger.info("User is not blocked: %s", username)
            return Response({'message': _('The user is not blocked.')}, status=status.HTTP_404_NOT_FOUND)

class AmIBlockedView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="path",
                description="Username of the player to check if they have blocked you."
            )
        ]
    )

    def get(self, request, username):
        user = request.user

        if user.username == username:
            logger.warning("User %s attempted to check if they blocked themselves.", user.username)
            return Response({'error': _('You cannot check if you have blocked yourself.')}, status=status.HTTP_400_BAD_REQUEST)

        try:
            other_player = Player.objects.get(username=username)
        except Player.DoesNotExist:
            logger.warning("User does not exist: %s", username)
            return Response({'message': 'The user does not exist.'}, status=status.HTTP_404_NOT_FOUND)

        am_i_blocked = other_player.blocked.filter(username=user.username).exists()
        if am_i_blocked:
            logger.info("User %s is blocked by: %s", user.username, username)
            return Response({'message': _('You are blocked by this user.')}, status=status.HTTP_200_OK)
        else:
            logger.info("User %s is not blocked by: %s", user.username, username)
            return Response({'message': _('You are not blocked by this user.')}, status=status.HTTP_404_NOT_FOUND)

class AllUsersView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema()

    def get(self, request):
        users = Player.objects.all()
        serializer = UserSerializer(users, many=True)
        logger.info("Retrieved all users.")
        return Response(serializer.data, status=status.HTTP_200_OK)


class LogoutView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "refresh",
                required=True,
                location="form",
                schema=coreschema.String(),
                description="Refresh token required to logout."
            )
        ]
    )

    def post(self, request):
        try:
            refresh = request.data.get('refresh')
            if refresh is None:
                logger.warning("Refresh token missing.")
                raise ValueError(_('Refresh token missing.'))

            token = RefreshToken(refresh)

            user_id = token['user_id']
            User = get_user_model()
            user = User.objects.get(id=user_id)
            user.is_online = False
            user.chatRooms = []
            user.save(update_fields=['is_online', 'chatRooms'])

            clear_user_cache(user_id)
            token.blacklist()

            logger.info("User logged out successfully: %s", user.username)
            return Response({'message': _('Logout successfully.')}, status=status.HTTP_205_RESET_CONTENT)
        except ValueError as e:
            logger.error("ValueError during logout: %s", e)
            return Response({'error': str(e)}, status=status.HTTP_400_BAD_REQUEST)
        except TokenError as e:
            logger.error("TokenError during logout: %s", e)
            return Response({'error': _('Invalid or expired token.')}, status=status.HTTP_400_BAD_REQUEST)
        except InvalidToken as e:
            logger.error("InvalidToken during logout: %s", e)
            return Response({'error': _('Not valid Token.')}, status=status.HTTP_400_BAD_REQUEST)
        except Exception as e:
            logger.error("Unexpected error during logout: %s", e)
            return Response({'error': _('Unexpected error.')}, status=status.HTTP_400_BAD_REQUEST)


class RegisterFtUserView(APIView):
    def get(self, request, *args, **kwargs):
        code = request.query_params.get('code', None)
        ENVIRONMENT = os.environ.get("ENVIRONMENT")
        if code:
            token_url = "https://api.intra.42.fr/oauth/token"
            client_id = os.environ.get("CLIENT_ID")
            client_secret = os.environ.get("CLIENT_SECRET")
            scheme = request.scheme
            full_host = request.get_host()
            host = urlsplit(f"{scheme}://{full_host}").hostname
            redirect_uri = f"https://{full_host}/user/42/register/"
            payload = {
                'grant_type': 'authorization_code',
                'client_id': client_id,
                'client_secret': client_secret,
                'code': code,
                'redirect_uri': redirect_uri,
            }
            try:
                response = requests.post(token_url, data=payload)
                response_data = response.json()
                if response.status_code == 200:
                    access_token = response_data.get('access_token')
                    user_info_url = "https://api.intra.42.fr/v2/me"
                    headers = {
                        'Authorization': f'Bearer {access_token}'
                    }
                    user_info_response = requests.get(user_info_url, headers=headers)
                    if user_info_response.status_code == 200:
                        user_info = user_info_response.json()
                        email = user_info.get('email')
                        username = user_info.get('login')
                        passmik = os.environ.get("PASSMIK")
                        combined_data = {
                            'username': username,
                            'email': email,
                            'password': passmik,
                            'password2': passmik,
                        }
                        if Player.objects.filter(email=email).exists():
                            user = Player.objects.get(email=email)
                            serializer = UserSerializer(user, data=combined_data)
                        else:
                            serializer = UserSerializer(data=combined_data)
                        if serializer.is_valid():
                            instance = serializer.save()
                            instance.is_ft = True
                            instance.is_online = True
                            instance.is_active = True
                            instance.is_2fa = True
                            instance.save()
                            clear_user_cache(instance.id)
                            login_url = "http://localhost:8280/user/login/"
                            login_payload = {
                                'email': email,
                                'password': passmik
                            }
                            login_response = requests.post(login_url, data=login_payload)
                            if login_response.status_code == 200:
                                cache_key = f"user_data_{instance.id}"
                                cache.set(cache_key, UserSerializer(instance).data, timeout=3600)
                                logger.info("User registered and logged in successfully: %s", username)
                                if ENVIRONMENT == "PRO":
                                    return HttpResponseRedirect(f"https://{host}:42443/otp/")
                                return HttpResponseRedirect(f"http://{host}:4200/otp/")
                            else:
                                logger.error("Error during login: %s", login_response.text)
                                return Response(f"Error during login: {login_response.text}", status=status.HTTP_500_INTERNAL_SERVER_ERROR)
                        else:
                            logger.error("Error in serializer validation: %s", serializer.errors)
                            return Response(f"Error in serialize validation: {serializer.errors}", status=status.HTTP_400_BAD_REQUEST)
                    else:
                        logger.error("Error obtaining user info: %s", user_info_response.json())
                        return Response(f"Error to obtain user info: {user_info_response.json()}", status=status.HTTP_400_BAD_REQUEST)
                else:
                    logger.error("Error getting token: %s", response_data)
                    return Response(f"Error getting token: {response_data}", status=status.HTTP_400_BAD_REQUEST)
            except requests.exceptions.RequestException as e:
                logger.error("RequestException during token request: %s", e)
                return Response(f"Error during request: {e}", status=status.HTTP_500_INTERNAL_SERVER_ERROR)
        else:
            logger.warning("No code provided for registration.")
            return Response("No code has been provided.", status=status.HTTP_400_BAD_REQUEST)
        
class GetUserInfo(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="path",
                schema=coreschema.String(),
                description="Username of the user to retrieve."
            )
        ]
    )
    def get(self, request, *args, **kwargs):
        username = kwargs.get('username')
        if Player.objects.filter(username=username).exists():
            user = Player.objects.get(username=username)
            cache_key = f"user_data_{user.id}"
            cached_user_data = cache.get(cache_key)
            if cached_user_data:
                logger.info("Retrieved user data from cache for username: %s", username)
                return Response(cached_user_data, status=status.HTTP_200_OK)
            serializer = UserSerializer(user)
            cache.set(cache_key, serializer.data, timeout=3600)
            logger.info("Retrieved user data from database and cached it for username: %s", username)
            return Response(serializer.data, status=status.HTTP_200_OK)
        else:
            logger.warning("User not found in database: %s", username)
            return Response("No user in db.", status=status.HTTP_404_NOT_FOUND)

class GetUserById(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "id",
                required=True,
                location="path",
                schema=coreschema.String(),
                description="Id of the user to retrieve."
            )
        ]
    )
    def get(self, request, *args, **kwargs):
        id = kwargs.get('id')
        if Player.objects.filter(id=id).exists():
            user = Player.objects.get(id=id)
            cache_key = f"user_data_{user.id}"
            cached_user_data = cache.get(cache_key)
            if cached_user_data:
                logger.info("Retrieved user data from cache for user ID: %s", id)
                return Response(cached_user_data, status=status.HTTP_200_OK)
            serializer = UserSerializer(user)
            cache.set(cache_key, serializer.data, timeout=3600)
            logger.info("Retrieved user data from database and cached it for user ID: %s", id)
            return Response(serializer.data, status=status.HTTP_200_OK)
        else:
            logger.warning("User not found in database: %s", id)
            return Response("No user in db.", status=status.HTTP_404_NOT_FOUND)


class GameListView(APIView):
    permission_classes = [IsAuthenticated]
    schema = AutoSchema()
    def get(self, request, *args, **kwargs):
        games = Game.objects.all()
        if not games.exists():
            logger.warning("No games found in database.")
            return Response("No games found.", status=status.HTTP_404_NOT_FOUND)
        serializer = GameSerializer(games, many=True)
        logger.info("Retrieved list of all games.")
        return Response(serializer.data)


class UserGamesView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="path",
                schema=coreschema.String(),
                description="Games of user identified by username."
            )
        ]
    )
    def get(self, request, *args, **kwargs):
        username = kwargs.get('username')
        try:
            player = Player.objects.get(username=username)
        except ObjectDoesNotExist:
            logger.warning("User not found in database: %s", username)
            return Response("No user found in db.", status=status.HTTP_404_NOT_FOUND)

        games = Game.objects.filter(
            Q(player_x=player) | Q(player_o=player) | Q(winner=player)
        ).distinct()
        if not games:
            logger.warning("No games found for user: %s", username)
            return Response("No games found for user.", status=status.HTTP_404_NOT_FOUND)

        serializer = GameSerializer(games, many=True)
        logger.info("Retrieved games for user: %s", username)
        return Response(serializer.data, status=status.HTTP_200_OK)

class PlayerWinsView(APIView):
    permission_classes = [IsAuthenticated]
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "username",
                required=True,
                location="path",
                schema=coreschema.String(),
                description="Games of user identified by username."
            )
        ]
    )
    def get(self, request, *args, **kwargs):
        username = kwargs.get('username')
        
        try:
            player = Player.objects.get(username=username)
        except ObjectDoesNotExist:
            logger.warning("User not found in database: %s", username)
            return Response("No user found in db.", status=status.HTTP_404_NOT_FOUND)

        wins = Game.objects.filter(winner=player).distinct()

        if not wins.exists():
            logger.warning("No wins found for user: %s", username)
            return Response("No wins found for user.", status=status.HTTP_404_NOT_FOUND)

        serializer = GameSerializer(wins, many=True)
        logger.info("Retrieved wins for user: %s", username)
        return Response(serializer.data, status=status.HTTP_200_OK)

class AddChatRoomView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "chat_room",
                required=True,
                location="path",
                schema=coreschema.String(),
                description="Chat room to add to the player's chatRooms array."
            )
        ]
    )

    def post(self, request, chat_room):
        user = request.user
        logger.info("Attempting to add chat room to player: %s", user.username)

        if not chat_room:
            logger.warning("Chat room string is required.")
            return Response({'error': _('Chat room string is required.')}, status=status.HTTP_400_BAD_REQUEST)

        if user.chatRooms is None:
            user.chatRooms = []

        if chat_room in user.chatRooms:
            logger.warning("Chat room already exists in the list: %s", chat_room)
            return Response({'error': _('Chat room already exists in the list.')}, status=status.HTTP_400_BAD_REQUEST)

        user.chatRooms.append(chat_room)
        user.save()
        clear_user_cache(user.id)
        logger.info("Chat room added successfully to player: %s", user.username)

        return Response({'Chat room added successfully'}, status=status.HTTP_201_CREATED)


class RemoveChatRoomView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "chat_room",
                required=True,
                location="path",
                schema=coreschema.String(),
                description="Chat room to remove from the player's chatRooms array."
            )
        ]
    )

    def post(self, request, chat_room):
        user = request.user
        logger.info("Attempting to remove chat room from player: %s", user.username)

        if not chat_room:
            logger.warning("Chat room string is required.")
            return Response({'error': _('Chat room string is required.')}, status=status.HTTP_400_BAD_REQUEST)

        if user.chatRooms is None or chat_room not in user.chatRooms:
            logger.warning("Chat room does not exist in the list: %s", chat_room)
            return Response({'error': _('Chat room does not exist in the list.')}, status=status.HTTP_400_BAD_REQUEST)

        user.chatRooms.remove(chat_room)
        user.save()
        clear_user_cache(user.id)
        logger.info("Chat room removed successfully from player: %s", user.username)

        return Response({'Chat room removed successfully'}, status=status.HTTP_201_CREATED)


class ListUsersInChatRoomView(APIView):
    permission_classes = (IsAuthenticated,)
    schema = AutoSchema(
        manual_fields=[
            coreapi.Field(
                "chat_room",
                required=True,
                location="path",
                schema=coreschema.String(),
                description="Chat room to search for in users' chatRooms arrays."
            )
        ]
    )

    def get(self, request, chat_room):
        logger.info("Attempting to list users in chat room: %s", chat_room)

        if not chat_room:
            logger.warning("Chat room string is required.")
            return Response({'error': _('Chat room string is required.')}, status=status.HTTP_400_BAD_REQUEST)

        User = get_user_model()
        users_in_chat_room = User.objects.filter(chatRooms__contains=[chat_room], is_online=True).values_list('username', flat=True)

        if not users_in_chat_room:
            logger.warning("No users found in chat room: %s", chat_room)
            return Response({'error': _('No users found in the specified chat room.')}, status=status.HTTP_404_NOT_FOUND)

        logger.info("Users found in chat room: %s", chat_room)
        return Response({'usernames': list(users_in_chat_room)}, status=status.HTTP_200_OK)

class TestErrorView(APIView):
    def get(self, request, *args, **kwargs):
        return Response({'error': _('This is a simulated error for alert testing.')}, status=status.HTTP_500_INTERNAL_SERVER_ERROR)