import { Component, Input }		from '@angular/core';
import { NgbActiveModal }		from '@ng-bootstrap/ng-bootstrap';
import { Router }				from '@angular/router';
import { TournamentService }	from '../../../core/services/tournament.service';
import { UserDataService }		from '../../../core/services/user-data.service';

@Component({
  selector: 'app-game-finished-modal',
  standalone: true,
  imports: [],
  templateUrl: './game-finished-modal.component.html',
  styleUrl: './game-finished-modal.component.css'
})
export class GameFinishedModalComponent {
	@Input() winner?: string;
	constructor(public activeModal: NgbActiveModal, public router: Router, private userDataServ: UserDataService, private tournamentServ: TournamentService) {}

	returnToDashboard(): void {
		this.activeModal.close('exit');
	}

	returnToTournament(): void {
		if (this.winner && this.winner === this.userDataServ.username()){
			this.tournamentServ.currentMsg.isGreeting = false;
			this.tournamentServ.currentMsg.isGame = false;
			this.tournamentServ.currentMsg.isWinner = true;
			this.tournamentServ.currentMsg.avatar = this.userDataServ.avatarUrl();
			this.tournamentServ.currentMsg.message = this.userDataServ.username();
			this.tournamentServ.sendMessage();
			this.tournamentServ.currentMsg.isWinner = false;
		}
		this.activeModal.close('exit');
	}
}
