import { Component } from '@angular/core';
import { NgbActiveModal } from '@ng-bootstrap/ng-bootstrap';
import { Router} from '@angular/router';
import { TournamentService } from '../../../core/services/tournament.service';
import { UserDataService } from '../../../core/services/user-data.service';

@Component({
  selector: 'app-exit-confirmation',
  standalone: true,
  imports: [],
  templateUrl: './exit-confirmation.component.html',
  styleUrl: './exit-confirmation.component.css'
})
export class ExitConfirmationComponent {
	constructor(private tournamentServ: TournamentService, private userDataServ: UserDataService, public activeModal: NgbActiveModal, public router: Router) {}

	confirmExit() {
		this.tournamentServ.currentMsg.isGame = false;
		this.tournamentServ.currentMsg.isGreeting = true;
		this.tournamentServ.currentMsg.avatar = this.userDataServ.avatarUrl();
		this.tournamentServ.currentMsg.message = this.userDataServ.username();
		this.tournamentServ.sendMessage();
		this.activeModal.close('exit');
	}

	confirmExitTournament() {
		this.activeModal.close('exit');
	}

	dismiss() {
		this.activeModal.dismiss('cancel');
	}
}