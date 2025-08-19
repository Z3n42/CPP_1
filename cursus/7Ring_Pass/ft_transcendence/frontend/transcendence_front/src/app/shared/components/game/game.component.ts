import { Component, OnInit, Input } from '@angular/core';
import { GameService } from '../../../core/services/game.service';
import { UserDataService } from '../../../core/services/user-data.service';
import { ApiService } from '../../../core/services/api.service';
import { Router} from '@angular/router';
import { Subscription } from 'rxjs';
import { stringify } from 'querystring';

@Component({
  selector: 'app-game',
  standalone: true,
  imports: [],
  templateUrl: './game.component.html',
  styleUrl: './game.component.css'
})
export class GameComponent implements OnInit{
	public gameFinishedModalOpened: boolean = false;
	public playerOneUsername : string = "";
	public playerOneAvatar : string = "";
	public playerTwoUsername : string = "";
	public playerTwoAvatar : string = "";
	public oponentLoaded : boolean = false;
	private subscriptionL : Subscription = new Subscription();
	private subscriptionR : Subscription  = new Subscription();
	avatarUrl: string = "";
	@Input() gameId!: string;

	constructor(public userDataService: UserDataService, public gameService: GameService, private router: Router, private apiSrv: ApiService) {
	}

	ngOnInit(): void {
		this.gameService.initialize();
		this.gameService.generateGameRoomUrl(this.gameId);

		this.subscriptionL = this.gameService.playerLeft$.subscribe(value => {
			if (this.oponentLoaded === false){
				if (value != '0' && value != this.userDataService.id() && value !== undefined) {
					this.loadRival(value);
				}
			}
		});
		this.subscriptionR = this.gameService.playerRight$.subscribe(value => {
			if (this.oponentLoaded === false){
				if (value != '0' && value != this.userDataService.id() && value !== undefined) {
					this.loadRival(value);
				}
			}
		});

		this.gameService.initializeWebSocketConnection();
		this.gameService.onConnected = () => {
		};
	}

	ngOnDestroy(): void {
		if (this.subscriptionL) {
			this.subscriptionL.unsubscribe();
		}
		if (this.subscriptionR) {
			this.subscriptionR.unsubscribe();
		}
		this.gameService.closeWebSocketConnection();
	}

	openGameFinishedModal(): void{
		this.gameFinishedModalOpened = true;
		if (this.gameService.winner === this.gameService.getplayerLeft()){
			this.gameService.winner = this.playerOneUsername;
		}
		else {
			this.gameService.winner = this.playerTwoUsername;
		}
		if (this.router.url.includes("semi_") || this.router.url.includes("final_") ){
			this.router.navigate(['/tournament']);
		}
		else {
			this.router.navigate(['/dashboard']);
		}
	}
	

	loadRival(userId: string){
		this.apiSrv.userDataById(userId).subscribe(
			(user: { username: string; avatar: number; customAvatar: string}) => {
				if (user.avatar === 7 && user.customAvatar) {
      				this.avatarUrl = `https://${window.location.hostname}:8443${user.customAvatar}`;
				} else if (user.avatar === 0) {
					this.avatarUrl = `assets/avatar/42.png`;
				}
				else {
					this.avatarUrl = "assets/avatar/monstruo-" + user.avatar + ".png" ;
				}

				if (this.gameService.getplayerLeft() == this.userDataService.id()){
					this.playerOneUsername = this.userDataService.username();
					this.playerOneAvatar = this.userDataService.avatarUrl();
					this.playerTwoUsername = user.username;
					this.playerTwoAvatar = this.avatarUrl;
				}
				else {
					this.playerOneUsername = user.username;
					this.playerOneAvatar =  this.avatarUrl;
					this.playerTwoUsername = this.userDataService.username() ;
					this.playerTwoAvatar = this.userDataService.avatarUrl() ;
				}
				
				this.oponentLoaded = true;
			},
			(error: Error) => {
				console.error('An error occurred:', error.message);
			}
		);
	}
}
