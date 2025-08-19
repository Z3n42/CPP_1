from django.shortcuts import render


def index(request):
    return render(request, "game/index.html")

def room(request, room_name, player_id):
    context = {
        'room_name': room_name,
        'player_id': player_id
    }
    return render(request, 'game/room.html', context)
