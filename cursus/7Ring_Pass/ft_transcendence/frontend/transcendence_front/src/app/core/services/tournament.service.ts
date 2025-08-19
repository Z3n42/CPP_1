import { Injectable, OnDestroy } from '@angular/core';
import { Router, NavigationEnd, Event } from '@angular/router';
import { UserDataService } from './user-data.service';
import { ApiService } from './api.service';
import { Subscription } from 'rxjs';
import { filter } from 'rxjs/operators';
import { NgbModal } from '@ng-bootstrap/ng-bootstrap';
import { WinnerModalComponent } from '../../shared/components/winner-modal/winner-modal.component';

interface MsgData {
	user: string;
	avatar: string;
	message: string;
	isGame: boolean;
	isGreeting: boolean;
	isWinner: boolean;
}

interface Tournament {
	name: string;
	participants: string [];
	finalists: string[];
	champ: string;
	inProgress: boolean;
	socket:  WebSocket | null;
	haveIlost: boolean;
}

@Injectable({
	providedIn: 'root'
})

export class TournamentService implements OnDestroy {
	private defaultTournamentPath = `wss://${window.location.hostname}:8443/ws/tournament/`;
	private defaultChatPath = `wss://${window.location.hostname}:8443/ws/chat/`;
	public	tournament: Tournament = {name: "Main Tournament", participants: [], finalists: [], champ: "", inProgress: false, socket: null, haveIlost: false};
	public	currentMsg: MsgData = { user: '', avatar: '', message: '', isGame: false, isGreeting: false, isWinner: false};
	public	onConnected: (path: string) => void = () => {};
	public	myIndex: string = "";
	private	routerSubscription!: Subscription;

	private handleRouteChange(): void {
		this.currentMsg.isGame = false;
		this.currentMsg.isGreeting = true;
		this.currentMsg.avatar = this.userDataServ.avatarUrl();
		this.currentMsg.message = this.userDataServ.username();
		this.sendMessage();
	}

	constructor( private router: Router, public userDataServ: UserDataService,  private apiSrv: ApiService, private modalService: NgbModal) {
		this.routerSubscription = this.router.events.pipe(
			filter((event): event is NavigationEnd => event instanceof NavigationEnd)
			).subscribe((event: NavigationEnd) => {
			if (!event.url.startsWith('/play') && !event.url.startsWith('/tournament')) {
				this.handleRouteChange();
			}
		});
	}

	ngOnDestroy(): void {
		this.routerSubscription.unsubscribe();
		if (this.tournament.participants.includes(this.userDataServ.username())){
			this.currentMsg.isGreeting = false;
			this.currentMsg.avatar = this.userDataServ.avatarUrl();
			this.currentMsg.message = this.userDataServ.username();
			this.sendMessage();
		}
	}

	restartTournament(): boolean{
		if (this.tournament.name !== ""){
			this.tournament.participants = [];
			this.tournament.finalists = [];
			this.tournament.champ = "";
			this.tournament.inProgress = false;
			this.tournament.haveIlost = false;
			this.currentMsg.isGame = false;
			this.currentMsg.isGreeting = false;
			this.currentMsg.isWinner = false;
			this.myIndex = "";
			return (true);
		}
		return (false);
	}


	//////////	UTILS	///////////

	sleep(milliseconds: number): Promise<void> {
		return new Promise(resolve => setTimeout(resolve, milliseconds));
	}

	async sleepFunction(amount: number) {
		if (amount > 0){
			const seconds = amount * 1000;
			await this.sleep(5000);
		}
	}

	//////////	PARTICIPANTS	///////////

	reorderAlphabetically(arr: string[]): string[] {
		return arr.sort((a, b) => a.localeCompare(b));
	}

	addParticipant(participantName: string) : boolean {
		if (this.tournament.name !== "" &&
			!this.tournament.inProgress &&
			!this.tournament.participants.includes(participantName)){
				this.tournament.participants.push(participantName);
				this.tournament.participants = this.reorderAlphabetically(this.tournament.participants);
				if (this.tournament.participants.length == 4){
					this.tournament.inProgress = true;
					this.startTournament();
				}
				return (true);
		}
		return (false);
	}

	removeParticipant(participantName: string){
		if (this.tournament.name !== "" &&
			this.tournament.inProgress == false &&
			this.tournament.participants.includes(participantName)){
				this.tournament.participants = this.tournament.participants.filter(( item ) => item !== participantName);
				return (true);
		}
		return (false);
	}

	setTournamentParticipants(username: string, fromBtn: boolean) : void {
		if (fromBtn){
			this.addParticipant(username);
		}
		else if (username != this.userDataServ.username() && this.tournament.participants.includes(this.userDataServ.username())){
			this.currentMsg.isGame = true;
			this.currentMsg.isGreeting = false;
			this.currentMsg.avatar = this.userDataServ.avatarUrl();
			this.currentMsg.message = this.userDataServ.username();
			this.sendMessage();
			this.currentMsg.isGame = false;
		}

	}



	//////////////////	MESSAGES	///////////////////////

	generateSocketPath(roomPath : string) : string {
		return(this.defaultChatPath + roomPath + '/')
	}

	initTournamentSocket(name: string){
		this.tournament.socket = new WebSocket( this.generateSocketPath(name) );
		this.tournament.socket.onopen = () => { if (this.onConnected) { this.onConnected(name); } };
		this.tournament.socket.onclose = () => { console.error('Tournament socket closed unexpectedly'); };
		this.tournament.socket.onmessage = (e: MessageEvent) => {
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
			if (tokens.length == 5) {
				if(tokens[4] == '1'){
					if (this.tournament.finalists.length <2){
						this.tournament.finalists.push(tokens[0]);
						this.tournament.finalists = this.reorderAlphabetically(this.tournament.finalists);
						if (this.tournament.finalists.length == 2){
							if (this.tournament.finalists.includes(this.userDataServ.username())){
								this.createFinalInvitation();
							}
							else {
								this.tournament.haveIlost = true;
							}
						}
					}
					else {
						this.tournament.champ = tokens[0];
						this.showWinnerModal(tokens[0]);
						this.sleepFunction(10);
						this.restartTournament();
					}
				}
				if (this.tournament.inProgress){
					if (this.tournament.haveIlost == false){
						this.acceptMatchInvitation(tokens[0]);
					}
				}
				else if (tokens[2] == '1'){
					this.removeParticipant(tokens[0]);
				}
				else {
					const fromBtn = tokens[3] == '1' ? true : false;
					this.setTournamentParticipants(tokens[0], fromBtn);
				}
				// Avatar (tokens[1]) has avatar of each participant, could be added
			} else {
				console.error('Received data does not contain exact tokens:', tokens);
			}
		};
		this.tournament.socket.onerror = (error) => { console.error('WebSocket error:', error); };
		
	}

	private showWinnerModal(winner: string) {
    	const modalRef = this.modalService.open(WinnerModalComponent);
    	modalRef.componentInstance.winner = winner;
	}

	sendMessage(): void {
		if (this.currentMsg.message === '') { return; }

		if (this.tournament.socket) {
			const buffer : string= this.concatMsg();
			this.tournament.socket.send(JSON.stringify({message: buffer}));
			this.currentMsg.message = '';
		} else {
			console.error('WebSocket connection is not established.');
		}
	}

	concatMsg(){
		return this.currentMsg.message + "~" + this.currentMsg.avatar + "~" + (this.currentMsg.isGreeting ? '1' : '0') + "~" + (this.currentMsg.isGame ? '1' : '0') + '~' + (this.currentMsg.isWinner ? '1' : '0');
	}



	//////////////////	MATCHES SOCKETS	///////////////////////

	generateUniqueId(): string {
		const timestamp = Date.now().toString(36);
		const random = Math.random().toString(36).substring(2, 15);
		return `${timestamp}${random}`;
	}

	generateTournamentSocketStart(isSemi: boolean) : string {
		const phase = isSemi ? "semi" : "final";
		const hash = this.generateUniqueId();
		return(this.defaultTournamentPath + phase + '_' + hash + '_' + this.userDataServ.id() + '_');
	}

	generateTournamentSocketEnd(pathFirstPart : string) : string {
		const myId = this.userDataServ.id();
		return(pathFirstPart + myId + '/');
	}



	//////////////////	SEMI & FINALS LOGIC	///////////////////////

	shuffleArray(array: number[]): number[] {
		const shuffled = [...array];
		
		for (let i = shuffled.length - 1; i > 0; i--) {
			const j = Math.floor(Math.random() * (i + 1));
			[shuffled[i], shuffled[j]] = [shuffled[j], shuffled[i]];
		}
		
		return shuffled;
	}

	startTournament(){
		this.tournament.inProgress = true;
		this.createSemiFinalsInvitations();
	}

	createSemiFinalsInvitations(){
		for (let i = 0; i < this.tournament.participants?.length; ++i){
			const username = this.tournament.participants[i];
			if (username == this.userDataServ.username()){
				this.myIndex = String(i);
				if (i == 0 || i == 2){
					this.currentMsg.isGreeting = false;
					const oponent = i == 0 ? this.tournament.participants[1] : this.tournament.participants[3];
					this.currentMsg.message = oponent + " s2:" + this.generateTournamentSocketStart(true);
					this .sendMessage();
				}
			}
		}
	}

	acceptMatchInvitation(msg: string){
		const myUser = this.userDataServ.username();
		const length = myUser.length + 4;

		if (msg.startsWith("s" + this.myIndex + ":")){
			const path = msg.substring(3);
			this.startSemiFinals(path, false);
		}
		else if (msg.startsWith(myUser + " s2:")){
			const path = this.generateTournamentSocketEnd(msg.substring(length));
			this.startSemiFinals(path, true);
		}
		else if (this.tournament.haveIlost == false && msg.startsWith("f" + this.myIndex + ":")){
			const path = msg.substring(3);
			this.startFinal(path, false);
		}
		else if (msg.startsWith(myUser + " f2:")){
			const path = this.generateTournamentSocketEnd(msg.substring(length));
			this.startFinal(path, true);
		}
	}

	startSemiFinals(path: string, sendFullSocketPath: boolean){
		if (sendFullSocketPath){
			const myI = this.myIndex;
			const rivalIndex = (myI == "0") ? "1" : (myI == "1") ? "0" : (myI == "2") ? "3" : "2";   
			this.currentMsg.isGreeting = false;
			this.currentMsg.message = "s" + rivalIndex + ":" + path;
			this .sendMessage();
		}
		if (this.myIndex == "1" || this.myIndex == '3'){
			this.sleepFunction(5);
		}
		const wsLength = this.defaultTournamentPath.length;
		const gameId = path.substring(wsLength, path.length -1);
		this.router.navigate(['/play', gameId]);
	}

	createFinalInvitation(){
		this.sleepFunction(5);
		if (this.tournament.finalists.length == 2){
			for (let i = 0; i < this.tournament.finalists?.length; ++i){
				const username = this.tournament.finalists[i];
				if (username == this.userDataServ.username()){
					this.myIndex = String(i);
					if (i == 0){
						//Message functions could be created to reduce code and standarize message sends: send join, send winner, send game, send remove
						this.currentMsg.isGreeting = false;
						this.currentMsg.isWinner = false;
						this.currentMsg.isGame =false;
						const oponent = this.tournament.finalists[1];
						this.currentMsg.message = oponent + " f2:" + this.generateTournamentSocketStart(false);
						this .sendMessage();
					}
				}
			}
		}
	}

	startFinal(path: string, sendFullSocketPath: boolean){
		if (sendFullSocketPath){
			const myI = this.myIndex;
			const rivalIndex = (myI == "0") ? "1" : "0";   
			this.currentMsg.isGreeting = false;
			this.currentMsg.message = "f" + rivalIndex + ":" + path;
			this .sendMessage();
		}
		if (this.myIndex == "1"){
			this.sleepFunction(5);
		}
		const wsLength = this.defaultTournamentPath.length;
		const gameId = path.substring(wsLength, path.length -1);
		this.router.navigate(['/play', gameId]);
	}
}
