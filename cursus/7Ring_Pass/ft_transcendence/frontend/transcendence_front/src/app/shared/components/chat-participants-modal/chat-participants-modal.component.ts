import { Component, OnInit, OnDestroy } from '@angular/core';
import { NgbActiveModal, NgbModal } from '@ng-bootstrap/ng-bootstrap';
import { Router } from '@angular/router';
import { ApiService } from '../../../core/services/api.service';
import { UserDataService } from '../../../core/services/user-data.service';
import { WebSocketService } from '../../../core/services/websocket.service';
import { error } from 'console';
import { catchError, forkJoin, map, of } from 'rxjs';

interface Participant {
	username: string;
	blocked: boolean;
}

@Component({
  selector: 'app-chat-participants-modal',
  standalone: true,
  imports: [],
  templateUrl: './chat-participants-modal.component.html',
  styleUrl: './chat-participants-modal.component.css'
})
export class ChatParticipantsModalComponent implements OnInit, OnDestroy {
	public room: string = "";
	public me: string = "";
	roomParticipants: Participant[] = [];
	selectedUser: any = null;

	constructor(public activeModal: NgbActiveModal, private router: Router, private apiSrv: ApiService, private userDataService: UserDataService, private webSocketService: WebSocketService, private modalService: NgbModal) {
		this.me = userDataService.username();
	}

	ngOnInit() {
    	this.apiSrv.getUsersInChatRoom(this.room).subscribe(
      		(response) => {
        		const participantObservables = response.usernames.map((participant: string) =>
          			this.apiSrv.amIblocked(participant).pipe(
            			map(() => ({ username: participant, blocked: true })), // Bloqueado
            			catchError((error) => {
              				if (error.status === 404) {
                				return of({ username: participant, blocked: false });
              				} else if (error.status === 400) {
                				console.error('Bad request for participant:', participant);
              				}
              				return of({ username: participant, blocked: false });
            			})
          			)
        		);
        		forkJoin(participantObservables).subscribe(
          			(participants) => {
            			this.roomParticipants = participants;
						console.log(this.roomParticipants);
          			},
          			(error) => {
            			console.error('Error getting blocked status for participants', error);
          			}
        		);
      		},
      		(error) => {
        		console.error('Error getting participants of room->', this.room, ' / error:', error);
    		}
    	);
  	}

	ngOnDestroy() {
	}

	handleStartChat(username: string){
		for( let i = 0; i < this.webSocketService.allChatsPaths.length; ++i){
			if (this.webSocketService.allChatsPaths[i].startsWith(username)){
				this.webSocketService.changeActiveSocket(username+this.me);
				this.activeModal.close();
				return ;
			}
		}
		this.webSocketService.currentMsg.message = " ";
		this.webSocketService.currentMsg.invitation = username;
		this.webSocketService.sendMessage(false);
		this.webSocketService.initializeWebSocketConnection(username + this.me);
		this.activeModal.close();
	}

	handleUserInfo(username: string, content: any) {
		this.apiSrv.getUsers().subscribe(users => {
			this.selectedUser = users.find(user => user.username === username);
			if (this.selectedUser) {
				this.modalService.open(content, { size: 'lg' });
			}
		})
	}

	avatarUrl(user: any): string {
    	if (user.avatar === 7 && user.customAvatar) {
      		return `https://${window.location.hostname}:8443${user.customAvatar}`;
    	} else if (user.avatar === 0) {
      		return `assets/avatar/42.png`;
    	} else {
      		return `assets/avatar/monstruo-${user.avatar}.png`;
    	}
  	}
}
