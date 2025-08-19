import { Component } from '@angular/core';
import { UserDataService } from '../../../core/services/user-data.service';
import { WebSocketService } from '../../../core/services/websocket.service';

@Component({
  selector: 'app-chat-list',
  standalone: true,
  imports: [],
  templateUrl: './chat-list.component.html',
  styleUrl: './chat-list.component.css'
})
export class ChatListComponent {
	constructor(public webSocketService: WebSocketService ){
	}

	changeActiveChat(newActiveChat: string){
		this.webSocketService.changeActiveSocket(newActiveChat);
	}
}
