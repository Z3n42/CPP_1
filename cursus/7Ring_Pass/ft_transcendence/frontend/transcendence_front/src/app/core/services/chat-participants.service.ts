import { Injectable } from '@angular/core';
import { ApiService } from '../services/api.service';
import { firstValueFrom } from 'rxjs';


@Injectable({
  providedIn: 'root'
})
export class ChatParticipantsService {
	public roomParticipantsMap = new Map<string, string[]>;
	constructor(private apiSrv: ApiService) { }

	addChatRoom(roomName: string){
		this.apiSrv.addChatRoom(roomName).subscribe(
			() => {
				if (!this.roomParticipantsMap.has(roomName)) {
					this.roomParticipantsMap.set(roomName, []);
				}
			},
			(error) => { console.error('Error adding room with name->', roomName, " / error: ", error); }
		);
	}

	async getParticipansInRoom(roomName: string) {
		try {
			const response = await firstValueFrom(this.apiSrv.getUsersInChatRoom(roomName));
			this.roomParticipantsMap.set(roomName, response.usernames);
		}
		catch (error) {
			console.error('Error getting participants of room->', roomName, " / error: ", error);
		}
	  }

	removeChatRoom(roomName: string){
		this.apiSrv.removeChatRoom(roomName).subscribe(
			() => {
			},
			(error) => { console.error('Error removing chat room: ', error); }
		);
	}
}
