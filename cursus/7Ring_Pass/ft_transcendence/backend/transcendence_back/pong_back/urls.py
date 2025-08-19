from django.urls import path
from rest_framework_simplejwt.views import TokenRefreshView
from .views import (MyTokenObtainPairView,RegisterView,AllUsersView,LogoutView,RegisterFtUserView,UserView,AddFriendView,
                    RemoveFriendView, IsFriendView, UserFriendsView, AddBlockedView, RemoveBlockedView, IsBlockedView, UserBlockedView,
                    GetUserInfo, GetUserById, VerifyOTPView, SendOTPView, GameListView, UserGamesView, AddChatRoomView, RemoveChatRoomView,
                    ListUsersInChatRoomView, PlayerWinsView, TestErrorView, AmIBlockedView)

app_name = 'pong_back' 

urlpatterns = [
    path('login/', MyTokenObtainPairView.as_view(), name='token_obtain_pair'),
    path('login/refresh/', TokenRefreshView.as_view(), name='token_refresh'),
    path('register/', RegisterView.as_view(), name='auth_register'),
    path('42/register/', RegisterFtUserView.as_view(), name='ft_register'),
    path('logout/', LogoutView.as_view(), name='auth_logout'),
    path('me/', UserView.as_view(), name='me'),
    path('otp/', VerifyOTPView.as_view(), name='otp'),
    path('otp/send/', SendOTPView.as_view(), name='otp_send'),
    path('addFriend/', AddFriendView.as_view(), name='add_friend'),
    path('removeFriend/', RemoveFriendView.as_view(), name='remove_friend'),
    path('is_friend/<str:username>/', IsFriendView.as_view(), name='is_friend'),
    path('friends_list/', UserFriendsView.as_view(), name='friends_list'),
    path('blockUser/', AddBlockedView.as_view(), name='add_blocked'),
    path('unBlockUser/', RemoveBlockedView.as_view(), name='remove_blocked'),
    path('is_blocked/<str:username>/', IsBlockedView.as_view(), name='is_blocked'),
    path('am_i_blocked/<str:username>/', AmIBlockedView.as_view(), name='am_i_blocked'),
    path('blocked_list/', UserBlockedView.as_view(), name='blocked_list'),
    path('data/<str:username>/', GetUserInfo.as_view(), name='take_info'),
    path('idData/<int:id>/', GetUserById.as_view(), name='take_info_by_id'),
    path('games/', GameListView.as_view(), name='game-list'),
    path('games/user/<str:username>/', UserGamesView.as_view(), name='user-games'),
    path('games/user/wins/<str:username>/', PlayerWinsView.as_view(), name='user-games'),
    path('add_chatRoom/<str:chat_room>/', AddChatRoomView.as_view(), name='add_chat_room'),
    path('remove_chatRoom/<str:chat_room>/', RemoveChatRoomView.as_view(), name='remove_chat_room'),
    path('users_in_chatRoom/<str:chat_room>/', ListUsersInChatRoomView.as_view(), name='users_in_chat_room'),
    path('test-error/', TestErrorView.as_view(), name='test-error'),
    path('', AllUsersView.as_view(), name='all'),
]
