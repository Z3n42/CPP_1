import { Component, OnInit, OnDestroy, AfterViewChecked, ElementRef, ViewChild } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { CommonModule } from '@angular/common';
import { WebSocketService } from '../../../core/services/websocket.service';
import { UserDataService } from '../../../core/services/user-data.service';
import { Router } from '@angular/router';
import { NgbModal } from '@ng-bootstrap/ng-bootstrap';
import { ChatParticipantsModalComponent } from '../chat-participants-modal/chat-participants-modal.component'

import { ChatListComponent } from '../chat-list/chat-list.component';

@Component({
  selector: 'app-chat',
  standalone: true,
  imports: [CommonModule, FormsModule, ChatListComponent],
  templateUrl: './chat.component.html',
  styleUrls: ['./chat.component.css']
})
export class ChatComponent implements OnInit, OnDestroy, AfterViewChecked{
	@ViewChild('chatContent') private chatContent!: ElementRef;
	private gameId: string = '';
	currentRoute: string = '';
	public chatListExpanded: boolean = false; 
	public newChats: string [] = [];

	constructor(public webSocketService: WebSocketService, private router: Router, public userDataSrv: UserDataService, private modalService: NgbModal) {
		this.currentRoute = this.router.url;
	}

	ngOnInit(): void {
		this.gameId = this.isGameRoute(this.router.url) ? this.router.url.substring(6) : 'main';
		this.webSocketService.updateUserData(this.userDataSrv.username(), this.userDataSrv.avatarUrl());
		
		this.webSocketService.initializeWebSocketConnection( this.gameId );
		this.webSocketService.onConnected = (path: string) => {
			this.webSocketService.currentMsg.isGreeting = true;
			this.webSocketService.currentMsg.message = this.userDataSrv.username() + " has joined the chat";
			this.webSocketService.sendMessageOnChat(false, path);
		};
	}

	ngAfterViewChecked() {
		this.scrollToBottom();
	}

	ngOnDestroy(): void {
		this.webSocketService.currentMsg.isGreeting = true;
		this.webSocketService.currentMsg.message = this.userDataSrv.username() + " left the chat";
		this.webSocketService.sendMessage(false);
		window.removeEventListener('beforeunload', this.handleBeforeUnload);
		console.log("Closing Chat WebSocket connection!");
		this.webSocketService.closeAllWebSockets();
	}

	handleBeforeUnload = (event: BeforeUnloadEvent) => {
		// TODO: Function to close the room chat
	}

	scrollToBottom(): void {
		try {
			if (this.chatContent && this.chatContent.nativeElement) {
				this.chatContent.nativeElement.scrollTop = this.chatContent.nativeElement.scrollHeight;
			}
		} catch (err) {
			console.error('Error scrolling to bottom', err);
		}
	}

	handleButtonClick(): void {
		this.webSocketService.sendMessage(false);
	}
	handleGameClick(): void {
		this.webSocketService.sendMessage(true);
	}
	handleJoinClick(gameId: string): void {
		console.log("going to navigate to id->", gameId);
		this.router.navigate(['/play', gameId]);
	}
	handleParticipantsClick():void{
		const modalRef = this.modalService.open(ChatParticipantsModalComponent);
		modalRef.componentInstance.room = this.gameId;
	}

	isGameRoute(route: string): boolean {
		if (route.length > 6 && route.startsWith("/play/")){
			return true;
		}
		return false;
	}

	toggleCollapse() {
		this.chatListExpanded = !this.chatListExpanded;
		this.newChats = [];
	}

	acceptInvitation(guestUsername: string) : boolean {
		this.webSocketService.initializeWebSocketConnection(this.userDataSrv.username() + guestUsername);
		if (!this.newChats.includes(this.userDataSrv.username() + guestUsername) && !this.chatListExpanded){
			this.newChats.push(this.userDataSrv.username() + guestUsername);
		}
		return (true);
	}
}