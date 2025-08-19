import json
from channels.generic.websocket import AsyncWebsocketConsumer


class ChatConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        self.room_name = self.scope["url_route"]["kwargs"]["room_name"]
        self.room_group_name = f"chat_{self.room_name}"

        await self.channel_layer.group_add(self.room_group_name, self.channel_name)

        await self.accept()

    async def disconnect(self, close_code):
        await self.channel_layer.group_discard(self.room_group_name, self.channel_name)

    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        message = text_data_json.get("message")
        username = text_data_json.get("username")
        avatar = text_data_json.get("avatar")
        hour = text_data_json.get("hour")
        is_game_challenge = text_data_json.get("isGameChallenge", False)
        game_id = text_data_json.get("gameId", "")
        is_greating = text_data_json.get("isGreating", False)

        await self.channel_layer.group_send(
            self.room_group_name,
            {
                "type": "chat_message",
                "message": message,
                "username": username,
                "avatar": avatar,
                "hour": hour,
                "isGameChallenge": is_game_challenge,
                "gameId": game_id,
                "isGreating": is_greating,
            },
        )

    async def chat_message(self, event):
        message = event["message"]
        username = event["username"]
        avatar = event["avatar"]
        hour = event["hour"]
        is_game_challenge = event["isGameChallenge"]
        game_id = event["gameId"]
        is_greating = event["isGreating"]

        await self.send(
            text_data=json.dumps({
                "message": message,
                "username": username,
                "avatar": avatar,
                "hour": hour,
                "isGameChallenge": is_game_challenge,
                "gameId": game_id,
                "isGreating": is_greating,
            })
        )
