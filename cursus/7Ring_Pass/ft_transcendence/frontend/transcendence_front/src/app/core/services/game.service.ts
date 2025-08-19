import { Injectable, OnDestroy } from '@angular/core';
import { Router } from '@angular/router';
import { UserDataService } from './user-data.service';
import { BehaviorSubject, Observable } from 'rxjs';

interface gameState {
	paddleWidt: number,
	paddleHeight: number,
	ballSize: number,
	paddleSpeed: number,
	scoreLeft: number,
	scoreRight: number,
	game_in_progress: boolean,
	game_over: boolean,
	player1Y: number,
	player2Y: number,
	player1Up: boolean,
	player1Down: boolean,
	player2Up: boolean,
	player2Down: boolean,
	ballX: number,
	ballY: number,
	ballSpeedX: number,
	ballSpeedY: number,
	winner: string
}

@Injectable({
  providedIn: 'root'
})

export class GameService implements OnDestroy{
	private gameSocket: WebSocket | null = null;
	public path: string = '';
	public onConnected: () => void = () => {};
	public gameInProgress = true;
	public canvas: HTMLCanvasElement | null = null;
	public  context: CanvasRenderingContext2D | null = null;
	public scoreLeft: number = 0;
	public scoreRight: number = 0;
	public playerLeft: string = "0";
	public playerRight: string = "0";
	public winner: string = "";
	private _playerLeft = new BehaviorSubject<string>('0');
	playerLeft$: Observable<string> = this._playerLeft.asObservable();
	private _playerRight = new BehaviorSubject<string>('0');
	playerRight$: Observable<string> = this._playerRight.asObservable();


	constructor(private router: Router, public userDataSrv: UserDataService){

	}

	initialize(){
		this.gameInProgress = true;
		this.scoreLeft = 0;
		this.scoreRight = 0;
		this.playerLeft = "0";	//Can I reamove this ? 
		this.playerRight ="0";	//An this?
		this.setPlayerLeft("0");
		this.setPlayerRight("0");
		this.winner = "";

		this.canvas = document.getElementById('pongCanvas') as HTMLCanvasElement;
		if (!this.canvas) {
		  console.error('Canvas element not found');
		  return;
		}
		this.context = this.canvas.getContext('2d') as CanvasRenderingContext2D;
		if (!this.context) {
		  console.error('2D context not available');
		  return;
		}

		this.addEventListeners();
	}

	

	private handleKeyDown = (event: KeyboardEvent): void => {
		let message: { type: string; player: number; direction: string } | null = null;
		if (this.gameInProgress) {
			if (this.userDataSrv.id() == this.getplayerLeft()) {
				switch (event.key) {
					case 'w':
					message = { type: 'move', player: 1, direction: 'up' };
					break;
					case 's':
					message = { type: 'move', player: 1, direction: 'down' };
					break;
				}
			}
			else {
				switch (event.key) {
					case 'ArrowUp':
					message = { type: 'move', player: 2, direction: 'up' };
					break;
					case 'ArrowDown':
					message = { type: 'move', player: 2, direction: 'down' };
					break;
				}
			}
		}
		if (message && this.gameSocket) {
			this.gameSocket.send(JSON.stringify(message));
		}
	}

	private handleKeyUp = (event: KeyboardEvent): void => {
		let message: { type: string; player: number; direction: string } | null = null;
		if (this.gameInProgress) {
			if (this.userDataSrv.id() == this.getplayerLeft()) {
				switch (event.key) {
					case 'w':
					case 's':
					message = { type: 'move', player: 1, direction: 'stop' };
					break;
				}
			}
			else {
				switch (event.key) {
					case 'ArrowUp':
					case 'ArrowDown':
					message = { type: 'move', player: 2, direction: 'stop' };
					break;
				}
			}
		}
		if (message && this.gameSocket) {
			this.gameSocket.send(JSON.stringify(message));
		}
	}

	private addEventListeners(): void {
		document.addEventListener('keydown', this.handleKeyDown);
		document.addEventListener('keyup', this.handleKeyUp);
	}
	

	removeEventListeners(): void {
		document.removeEventListener('keydown', this.handleKeyDown.bind(this));
		document.removeEventListener('keyup', this.handleKeyUp.bind(this));
	}

	ngOnDestroy() {
		this.removeEventListeners();
	}

	initializeWebSocketConnection(): void {
		if (this.path !== '') {
			this.gameSocket = new WebSocket(this.path);
			this.gameSocket.onopen = () => {
				if (this.onConnected) {
					this.onConnected();
				}
			};

			this.gameSocket.onclose = () => { console.error('Chat socket closed unexpectedly'); };

			this.gameSocket.onmessage = (e: MessageEvent) => {
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
				if (parsedObject.type === 'game_end'){
					this.gameInProgress = false;
					const match = msg.match(/Player (\d+)/);
					if (match && match[1]) {
            					const winnerNumber = match[1];
						if (winnerNumber != this._playerLeft.value) {
							this.winner = this._playerRight.value;
						} else {
							this.winner = this._playerLeft.value;
						}
					}
				}
				else {
					this.drawEverything(parsedObject); 
					if (parsedObject.scoreLeft != this.scoreLeft){
						this.scoreLeft = parsedObject.scoreLeft;
					}
					if (parsedObject.scoreRight != this.scoreRight){
						this.scoreRight = parsedObject.scoreRight;
					}
					if (parsedObject.player_x != this.getplayerLeft()){
						this.setPlayerLeft(parsedObject.player_x);
					}
					if (parsedObject.player_o != this.getplayerRight()){
						this.setPlayerRight(parsedObject.player_o);
					}
				}
			};
			this.gameSocket.onerror = (error) => { console.error('WebSocket error:', error); };
		}
		else {
			console.error('Failed to establish WebSocket connection');
		}
	}

	generateGameRoomUrl(gameId: string){
		const defaultPath = (gameId.startsWith("semi_") || gameId.startsWith("final_")) ? `wss://${window.location.hostname}:8443/ws/tournament/` : `wss://${window.location.hostname}:8443/ws/game/`;
		this.path = defaultPath + gameId + '/' + this.userDataSrv.id() + '/';
		console.log("Path to connect->", this.path);
	}

	drawEverything(gameState: gameState) {
		const paddleWidth = 10, paddleHeight = 100, ballSize = 10;
		if (this.context && this.canvas){
			this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);
			this.drawRect(0, 0, this.canvas.width, this.canvas.height, 'black');
			this.drawNet();
			this.drawRect(0, gameState.player1Y, paddleWidth, paddleHeight, 'white');
			this.drawRect(this.canvas.width - paddleWidth, gameState.player2Y, paddleWidth, paddleHeight, 'white');
			this.drawCircle(gameState.ballX, gameState.ballY, ballSize, 'white');
		}
	}

	drawRect(x: number, y: number, width: number, height: number, color: string) {
		if (this.context){
			this.context.fillStyle = color;
			this.context.fillRect(x, y, width, height);
		}
	}

	drawNet() {
		if (this.canvas){
			for (let i = 0; i < this.canvas.height; i += 15) {
				this.drawRect(this.canvas.width / 2 - 1, i, 2, 10, 'white');
			}
		}
	}

	drawCircle(x: number, y: number, radius: number, color: string) {
		if (this.context){
			this.context.fillStyle = color;
			this.context.beginPath();
			this.context.arc(x, y, radius, 0, Math.PI * 2, true);
			this.context.closePath();
			this.context.fill();
		}
	}

	closeWebSocketConnection(): void {
		if (this.gameSocket) {
			this.gameSocket.close();
			console.log("Game Socket closed!");
			this.gameSocket = null;
		}
	}

	setPlayerLeft(value: string): void {
		this._playerLeft.next(value);
	}
	getplayerLeft(): string {
		return this._playerLeft.value;
	}

	setPlayerRight(value: string): void {
		this._playerRight.next(value);
	}
	getplayerRight(): string {
		return this._playerRight.value;
	}
}
