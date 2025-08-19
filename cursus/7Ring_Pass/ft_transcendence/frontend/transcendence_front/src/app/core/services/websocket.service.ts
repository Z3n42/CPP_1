import { Injectable, } from '@angular/core';
import { UserDataService } from './user-data.service';
import { Router } from '@angular/router';
import { ChatParticipantsService } from './chat-participants.service';
import { ApiService } from './api.service';

interface MsgData {
	user: string;
	avatar: string;
	message: string;
	timestamp: string;
	isGame: boolean;
	gameId: string;
	isGreeting: boolean;
	invitation: string;
}

@Injectable({
  providedIn: 'root'
})
export class WebSocketService {
	public	activeSocketPath: string = "main";
	public	allChatsPaths: string [] = ["main"];
	private	activeSocket: WebSocket | null = null;
	public	chatsSockets = new Map<string, WebSocket>;
	public	currentMsg: MsgData = { user: '', avatar: '', message: '', timestamp: '', isGame: false, gameId: ' ', isGreeting: false, invitation: ' '};
	public	chatMessages = new Map<string, MsgData[]>
	public	messages: MsgData[] = [];
	public	parsedObjects: [] = [];
	public	onConnected: (path: string) => void = () => {};
	public	blockedUsers: string[] = [];


	constructor(public userDataService: UserDataService, private router: Router, public chatPartiServ: ChatParticipantsService, public apiSrv: ApiService){}

	private loadBlockedUsers(): void {
    	this.apiSrv.getBlockedUsers(this.userDataService.username()).subscribe(
      		response => {
        		this.blockedUsers = response.blocked;
      		},
      		error => {
        		console.error('Error fetching blocked users:', error);
      		}
    	);
  	}

	generateChatRoomUrl(roomPath : string) : string {
		const defaultPath = `wss://${window.location.hostname}:8443/ws/chat/`;
		this.chatPartiServ.addChatRoom(roomPath);
		return(defaultPath + roomPath + '/')
	}

	changeActiveSocket(socketName: string) :boolean{
		if (this.chatsSockets.has(socketName)){
			const newActiveSocket = this.chatsSockets.get(socketName);
			if (newActiveSocket != undefined){
				this.activeSocket = newActiveSocket;
				this.activeSocketPath = socketName;
				console.log("Active socket changed, now is->", this.activeSocketPath)
				return (true);
			}
		}
		return (false);
	}

	updateUserData(username: string, avatarUrl: string): void {
		this.currentMsg.user = username;
		this.currentMsg.avatar = avatarUrl;
		this.loadBlockedUsers();
	}

	initializeWebSocketConnection(path: string): void {
		if (path !== '' && !this.chatsSockets.has(path)){
			const chatSocket = new WebSocket( this.generateChatRoomUrl(path) );
			chatSocket.onopen = () => { if (this.onConnected) { this.onConnected(path); } };
			chatSocket.onclose = () => { console.error('Chat socket closed unexpectedly'); };
			chatSocket.onmessage = (e: MessageEvent) => {
				let data: string;
				let parsedObject: any;
				try {
					data = e.data;
					parsedObject = JSON.parse(data);
				} catch (error) {
					console.error('Error handling message:', error);
					return;
				}
				const msg = parsedObject.message;
				const tokens = msg.split('~');
				if (tokens.length == 8) {
					const receivedData : MsgData = {
						user: tokens[2],
						avatar: tokens[1],
						message: tokens[0],
						timestamp: tokens[3],
						isGame: (tokens[5] == '1') ? true : false,
						gameId: (tokens[5] == '1') ? tokens[4] : '',
						isGreeting: (tokens[6] == '1') ? true : false,
						invitation: tokens[7]
					};
					if (!this.blockedUsers.includes(receivedData.user)){
						this.chatMessages.get(path)?.push(receivedData);
					} else {
						console.log("Message from blocked user:", receivedData.user);
					}
				} else {
					console.error('Received data does not contain exact tokens:', tokens);
				}
			};
			chatSocket.onerror = (error) => { console.error('WebSocket error:', error); };
			if (!this.chatsSockets.has(path)){
				this.chatsSockets.set(path, chatSocket);
			}
			if (!this.allChatsPaths.includes(path)){
				this.allChatsPaths.push(path);
			}
			if (!this.chatMessages.has(path)){
				this.chatMessages.set(path, []);
			}
			if (!path.startsWith(this.userDataService.username())){
				this.changeActiveSocket(path);
			}
		}
		else {
			console.error('Failed to establish WebSocket connection');
		}
	}

	sendMessage(isGame:boolean): void {
		if (this.currentMsg.message === '' && isGame == false) {
			return;
		}

		if (this.activeSocket) {
			if (isGame){
				this.currentMsg.message = "I challenge the first one to join"
				this.currentMsg.gameId = this.generateUniqueId();
			}
			else {
				this.currentMsg.gameId = " "
			}
			this.currentMsg.timestamp = this.generateLocalHour();
			this.currentMsg.isGame = isGame;
			const buffer : string= this.concatMsg();
			this.activeSocket.send(JSON.stringify({message: buffer}));
			this.currentMsg.isGreeting = false;
			this.currentMsg.message = '';
			this.currentMsg.timestamp = '';
			this.currentMsg.invitation = ' ';
		} else {
			console.error('WebSocket connection is not established.');
		}
	}

	sendMessageOnChat(isGame:boolean, chatName: string): void {
		if ((this.currentMsg.message === '' && isGame == false) || !this.chatsSockets.has(chatName)) {
			return;
		}

		if (this.chatsSockets.get(chatName)) {
			if (isGame){
				this.currentMsg.message = "I challenge the first one to join"
				this.currentMsg.gameId = this.generateUniqueId();
			}
			else {
				this.currentMsg.gameId = " "
			}
			this.currentMsg.timestamp = this.generateLocalHour();
			this.currentMsg.isGame = isGame;
			const buffer : string= this.concatMsg();
			this.chatsSockets.get(chatName)?.send(JSON.stringify({message: buffer}));
			this.currentMsg.isGreeting = false;
			this.currentMsg.message = '';
			this.currentMsg.timestamp = '';
			this.currentMsg.invitation = ' ';
		} else {
			console.error('WebSocket connection is not established.');
		}
	}

	concatMsg(){
		return this.currentMsg.message + "~" + this.currentMsg.avatar + '~' + this.currentMsg.user + '~' + this.currentMsg.timestamp + '~' + this.currentMsg.gameId  + '~' + (this.currentMsg.isGame ? '1' : '0') + '~' + (this.currentMsg.isGreeting ? '1' : '0') + '~' + (this.currentMsg.invitation);
	}

	generateLocalHour(): string {
		const now = new Date();
		const hour = now.getHours();
		const minutes = now.getMinutes();
		const formattedHour = hour < 10 ? `0${hour}` : `${hour}`;
		const formattedMinutes = minutes < 10 ? `0${minutes}` : `${minutes}`;
		return `${formattedHour}:${formattedMinutes}`;
	}

	generateUniqueId(): string {
		const timestamp = Date.now().toString(36);
		const random = Math.random().toString(36).substring(2, 15);
		return `${timestamp}${random}`;
	}

	closeWebSocketConnection(path: string): void {
		if (this.activeSocket){
			this.activeSocket.close();
		}
		const mainSocket = this.chatsSockets.get("main");
		this.activeSocketPath = "main";
		if (mainSocket != undefined){
			this.activeSocket = mainSocket;
		}
		else {
			this.activeSocket = null
		}
		this.chatPartiServ.removeChatRoom(path);
		if (this.chatsSockets.get(path)){
			this.chatsSockets.get(path)?.close();
		}
		this.chatsSockets.delete(path);
		this.chatMessages.delete(path);
		this.allChatsPaths = this.allChatsPaths.filter(item => item !== path);

	}

	closeAllWebSockets() : void {
		if (this.activeSocket){
			this.activeSocket.close();
			this.activeSocket = null
		}
		this.activeSocketPath = "main";
		const keys = Array.from(this.chatMessages.keys());
		for (let i = 0; i < keys.length; ++i){
			this.chatPartiServ.removeChatRoom(keys[i]);
		}
		for (let value of this.chatsSockets.values()) {
			if (value){
				value.close();
			}
		}
		this.chatsSockets.clear();
		this.chatMessages.clear();
		this.allChatsPaths = ["main"];

	}
}