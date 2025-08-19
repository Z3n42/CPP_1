import json
import asyncio
from channels.generic.websocket import AsyncWebsocketConsumer
from channels.db import database_sync_to_async
from pong_back.models import Game, Player
import urllib.parse

game_states_list = {}

class GameConsumer(AsyncWebsocketConsumer):

    async def connect(self):
        self.room_name = self.scope['url_route']['kwargs']['room_name']
        self.room_group_name = f'game_{self.room_name}'
        self.player_id = self.scope['url_route']['kwargs']['player_id']

        can_connect = await self.add_connection(self.room_name)

        if not can_connect:
            game_states_list[self.room_group_name]['channel_names'].append(self.channel_name)
            await self.accept()
            await self.handle_not_permitted()
            await asyncio.sleep(1)  
            return

        await self.channel_layer.group_add(
            self.room_group_name,
            self.channel_name
        )
        
        await self.accept()       

        self.game_state = game_states_list[self.room_group_name]['state']
        await self.create_game()

        if game_states_list[self.room_group_name]['connected_home'] == True and game_states_list[self.room_group_name]['connected_away'] == True:
            if game_states_list[self.room_group_name]['task'] is None:
                await self.message_5sg()
                await self.send_game_state()
                game_states_list[self.room_group_name]['already_started'] = True
                game_states_list[self.room_group_name]['task'] = asyncio.create_task(self.game_loop())
            self.game_state['game_in_progress'] = True
        else:
            self.game_state['game_in_progress'] = False

        if 'wait_task' in game_states_list[self.room_group_name]:
            game_states_list[self.room_group_name]['wait_task'].cancel()
            del game_states_list[self.room_group_name]['wait_task']
            if game_states_list[self.room_group_name]['connected_home'] == True and game_states_list[self.room_group_name]['connected_away'] == True:
                self.game_state['game_in_progress'] = True

    
    async def disconnect(self, close_code):
        await self.channel_layer.group_discard(
            self.room_group_name,
            self.channel_name
        )
      
        if self.room_group_name not in game_states_list:
            return
        
        if self.channel_name in game_states_list[self.room_group_name]['channel_names']:
            return
        
        self.game_state['game_in_progress'] = False

        await self.remove_connection()
        
        if game_states_list[self.room_group_name]['connected_home'] == False and game_states_list[self.room_group_name]['connected_away'] == False: 
            if game_states_list[self.room_group_name]['already_started']:
                game_states_list[self.room_group_name]['wait_task'].cancel()
                del game_states_list[self.room_group_name]['wait_task']
                asyncio.create_task(self.handle_game_end("Player " + self.player_id))
                await asyncio.sleep(1)
                return

            else:
                del game_states_list[self.room_group_name]
                return

        if game_states_list[self.room_group_name]['connected_home'] == False or game_states_list[self.room_group_name]['connected_away'] == False:
            game_states_list[self.room_group_name]['wait_task'] = asyncio.create_task(self.wait_for_reconnection())
    
    
    @database_sync_to_async
    def create_game(self):
        game, created = Game.objects.get_or_create(room_name=self.room_name)
        player = Player.objects.get(id=self.player_id)
        if created:
            game.player_x = player
            self.game_state['player_x'] = game_states_list[self.room_group_name]['home_player']
            player.games += 1
        else:
            if game.player_x is None:
                game.player_x = player
                self.game_state['player_x'] = game_states_list[self.room_group_name]['home_player']
                player.games += 1
            elif game.player_o is None and game.player_x != player:
                game.player_o = player
                self.game_state['player_o'] = game_states_list[self.room_group_name]['away_player']
                player.games += 1
        game.save()
        player.save()
        return game

    @database_sync_to_async
    def winner_select(self, winner):
        numero = int(winner.split()[1])
        game = Game.objects.get(room_name=self.room_name)
        player = Player.objects.get(id=numero)
        game.winner = player
        player.wins += 1
        player.save()
        game.player_o_points = self.game_state['scoreLeft']
        game.player_x_points = self.game_state['scoreRight']
        game.save()

    async def wait_for_reconnection(self):
        try:
            await asyncio.sleep(20)
            if game_states_list[self.room_group_name]['connected_home'] == False or game_states_list[self.room_group_name]['connected_away'] == False:
                if self.player_id == game_states_list[self.room_group_name]['away_player']:
                    remaining_player = "Player " + game_states_list[self.room_group_name]['home_player']
                else:
                    remaining_player = "Player " + game_states_list[self.room_group_name]['away_player']
                
            await self.handle_game_end(remaining_player)
        except asyncio.CancelledError:
            pass


    async def handle_game_end(self, winner):
        self.game_state['game_in_progress'] = False
        self.game_state['game_over'] = True
        await self.winner_select(winner)
        message = f'<div class="game-end-message">{winner} has won this match! The room will be closed</div>'
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'game_update',
                'message': {'type': 'game_end', 'message': message}
            }
        )
        await self.send_game_state()

        await asyncio.sleep(1)
        del game_states_list[self.room_group_name]


    async def message_5sg(self):
        message = f'<div class="game-start-message">5sg to start</div>'
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'game_update',
                'message': {'type': 'game_start', 'message': message}
            }
        )


    @database_sync_to_async
    def add_connection(self, room_name):
        isFinal = False
        if self.parse_room_name(room_name, 0) == 'final':
            isFinal = True
        homePlayer = self.parse_room_name(room_name, 2)
        awayPlayer = self.parse_room_name(room_name, 3)
        
        if self.room_group_name not in game_states_list:
            game_states_list[self.room_group_name] = {
                'task': None,
                'state': self.init_game_state(),
                'channel_names': [],
                'already_started' : False,
                'final' : isFinal,
                'first_connected' : self.player_id, 
                'home_player' : homePlayer,
                'connected_home': False,
                'away_player' : awayPlayer,
                'connected_away': False
            }

            if self.player_id == game_states_list[self.room_group_name]['home_player']:
                game_states_list[self.room_group_name]['connected_home'] = True
                return True
            elif self.player_id == game_states_list[self.room_group_name]['away_player']:
                game_states_list[self.room_group_name]['connected_away'] = True
                return True
            else:
                return False
        
        elif game_states_list[self.room_group_name]['connected_home'] == False or game_states_list[self.room_group_name]['connected_away'] == False:
            if game_states_list[self.room_group_name]['connected_home'] == False and game_states_list[self.room_group_name]['home_player'] == self.player_id:
                game_states_list[self.room_group_name]['connected_home'] = True
                return True
            elif game_states_list[self.room_group_name]['connected_away'] == False and game_states_list[self.room_group_name]['away_player'] == self.player_id:
                game_states_list[self.room_group_name]['connected_away'] = True
                return True
            
            return False                
            
        else:
            return False
        

    def parse_room_name(self, room_name, possition):
        ids = room_name.split('_')
        return (ids[possition])
    

    @database_sync_to_async
    def remove_connection(self):
        if self.player_id == game_states_list[self.room_group_name]['home_player']:
            game_states_list[self.room_group_name]['connected_home'] = False
        elif self.player_id == game_states_list[self.room_group_name]['away_player']:
            game_states_list[self.room_group_name]['connected_away'] = False    

        if game_states_list[self.room_group_name]['connected_home'] == False and game_states_list[self.room_group_name]['connected_away'] == False:
            if game_states_list[self.room_group_name]['task']:
                game_states_list[self.room_group_name]['task'].cancel()


    async def handle_not_permitted(self):
        await self.send(text_data=json.dumps({
            'type': 'direct_message',
            'message': 'The player with id: ' + self.player_id + ' can not connect to this match'
        }))

    async def receive(self, text_data):
        data = json.loads(text_data)
        
        if data['type'] == 'move' and self.game_state['game_in_progress']:
            if data['player'] == 1:
                if data['direction'] == 'up':
                    self.game_state['player1Up'] = True
                    self.game_state['player1Down'] = False
                elif data['direction'] == 'down':
                    self.game_state['player1Up'] = False
                    self.game_state['player1Down'] = True
                elif data['direction'] == 'stop':
                    self.game_state['player1Up'] = False
                    self.game_state['player1Down'] = False
            elif data['player'] == 2:
                if data['direction'] == 'up':
                    self.game_state['player2Up'] = True
                    self.game_state['player2Down'] = False
                elif data['direction'] == 'down':
                    self.game_state['player2Up'] = False
                    self.game_state['player2Down'] = True
                elif data['direction'] == 'stop':
                    self.game_state['player2Up'] = False
                    self.game_state['player2Down'] = False
        elif data['type'] == 'restart':
            await self.restart_game()

    async def game_loop(self):
        await asyncio.sleep(5) 
        
        try:
            while True:
                if self.game_state['game_in_progress']:
                    self.move_everything()
                    await self.send_game_state()
                await asyncio.sleep(0.03)
        except asyncio.CancelledError:
            pass

    def init_game_state(self):
        return {
            'paddleWidth': 10,
            'paddleHeight': 100,
            'ballSize': 10,
            'paddleSpeed': 10,
            'scoreLeft': 0,
            'scoreRight': 0,
            'game_in_progress': True,
            'game_over': False,
            'player1Y': (400 - 100) / 2,
            'player2Y': (400 - 100) / 2,
            'player1Up': False,
            'player1Down': False,
            'player2Up': False,
            'player2Down': False,
            'ballX': 400,
            'ballY': 300,
            'ballSpeedX': -10,
            'ballSpeedY': 9,
            'player_x': 0,
            'player_o':0
        }

    def reset_ball(self):
        self.game_state['ballX'] = 400
        self.game_state['ballY'] = 300
        
        if self.game_state['scoreRight'] > self.game_state['scoreLeft']:
            self.game_state['ballSpeedX'] = 10
        else:
            self.game_state['ballSpeedX'] = -10
        
        self.game_state['ballSpeedY'] = 9

    def move_everything(self):
        if not self.game_state['game_in_progress']:
            return
        
        self.game_state['ballX'] += self.game_state['ballSpeedX']
        self.game_state['ballY'] += self.game_state['ballSpeedY']

        if self.game_state['ballY'] <= 0 or self.game_state['ballY'] >= 400:
            self.game_state['ballSpeedY'] = -self.game_state['ballSpeedY']

        if self.game_state['ballX'] <= 0:
            if self.game_state['ballY'] > self.game_state['player1Y'] and self.game_state['ballY'] < self.game_state['player1Y'] + self.game_state['paddleHeight']:
                self.game_state['ballSpeedX'] = -self.game_state['ballSpeedX']
            else:
                self.game_state['scoreRight'] += 1
                if self.game_state['scoreRight'] >=3:
                    asyncio.create_task(self.handle_game_end("Player " + game_states_list[self.room_group_name]['away_player']))
                else:
                    self.reset_ball()

        if self.game_state['ballX'] >= 800:
            if self.game_state['ballY'] > self.game_state['player2Y'] and self.game_state['ballY'] < self.game_state['player2Y'] + self.game_state['paddleHeight']:
                self.game_state['ballSpeedX'] = -self.game_state['ballSpeedX']
            else:
                self.game_state['scoreLeft'] += 1
                if self.game_state['scoreLeft'] >=3:
                    asyncio.create_task(self.handle_game_end("Player " + game_states_list[self.room_group_name]['home_player']))
                else:
                    self.reset_ball()

        if self.game_state['player1Up'] and self.game_state['player1Y'] > 0:
            self.game_state['player1Y'] -= self.game_state['paddleSpeed']
        if self.game_state['player1Down'] and self.game_state['player1Y'] < 400 - self.game_state['paddleHeight']:
            self.game_state['player1Y'] += self.game_state['paddleSpeed']
        if self.game_state['player2Up'] and self.game_state['player2Y'] > 0:
            self.game_state['player2Y'] -= self.game_state['paddleSpeed']
        if self.game_state['player2Down'] and self.game_state['player2Y'] < 400 - self.game_state['paddleHeight']:
            self.game_state['player2Y'] += self.game_state['paddleSpeed']

    async def send_game_state(self):
        game_state = {
            'player1Y': self.game_state['player1Y'],
            'player2Y': self.game_state['player2Y'],
            'ballX': self.game_state['ballX'],
            'ballY': self.game_state['ballY'],
            'scoreLeft': self.game_state['scoreLeft'],
            'scoreRight': self.game_state['scoreRight'],
            'game_in_progress': self.game_state['game_in_progress'],
            'player_x': self.game_state['player_x'],
            'player_o': self.game_state['player_o']
        }
        
        await self.channel_layer.group_send(
            self.room_group_name,
            {
                'type': 'game_update',
                'message': game_state
            }
        )

    async def restart_game(self):
        if self.game_state['game_over']:
            return  
        
        self.game_state.update(self.init_game_state())
        game_states_list[self.room_group_name]['task'] = asyncio.create_task(self.game_loop())

    async def game_update(self, event):
        message = event['message']
        await self.send(text_data=json.dumps(message))