import { Component, OnDestroy, OnInit } 			from '@angular/core';
import { MenuComponent }			from '../../shared/components/menu/menu.component';
import { FooterComponent }			from '../../shared/components/footer/footer.component';
import { TournamentService }		from '../../core/services/tournament.service';
import { UserDataService }			from '../../core/services/user-data.service';
import { ChatParticipantsService }	from '../../core/services/chat-participants.service';
import { Observable }				from 'rxjs';
import { NgbModal } from '@ng-bootstrap/ng-bootstrap';
import { ExitConfirmationComponent } from '../../shared/components/exit-confirmation/exit-confirmation.component';
import { CanComponentDeactivate } from '../../core/guards/can-deactivate.guard';


@Component({
  selector: 'app-tournament',
  standalone: true,
  imports: [MenuComponent, FooterComponent],
  templateUrl: './tournament.component.html',
  styleUrl: './tournament.component.css'
})
export class TournamentComponent implements OnInit, OnDestroy, CanComponentDeactivate {
	private allowNavigation = false;
	public	insideTournament : boolean = false;
	constructor(public tournamentServ: TournamentService, public userDataServ: UserDataService, public chatPartiServ: ChatParticipantsService, private modalService: NgbModal){
	}

	ngOnInit(): void {
		window.addEventListener('beforeunload', (event) => this.beforeUnloadHandler(event));
		if (this.tournamentServ.tournament.socket === null){
			this.tournamentServ.initTournamentSocket("maintournament");
			this.tournamentServ.onConnected = (path: string) => {
				this.tournamentServ.currentMsg.isGreeting = false;
				this.tournamentServ.currentMsg.isGame = false;
				this.tournamentServ.currentMsg.avatar = this.userDataServ.avatarUrl();
				this.tournamentServ.currentMsg.message = this.userDataServ.username();
				this.tournamentServ.sendMessage();
			};
		}
	}

	ngOnDestroy(): void {
		window.removeEventListener('beforeunload', (event) => this.beforeUnloadHandler(event));
	}

	beforeUnloadHandler(event: Event) {
		this.removeMeFromTournament();
	}

	addMeToTournament(){
		this.tournamentServ.currentMsg.isGame = true;
		this.tournamentServ.currentMsg.isGreeting = false;
		this.tournamentServ.currentMsg.avatar = this.userDataServ.avatarUrl();
		this.tournamentServ.currentMsg.message = this.userDataServ.username();
		this.tournamentServ.sendMessage();
		this.tournamentServ.currentMsg.isGame = false;
		this.insideTournament = true;
	}

	removeMeFromTournament(){
		this.tournamentServ.currentMsg.isGame = false;
		this.tournamentServ.currentMsg.isGreeting = true;
		this.tournamentServ.currentMsg.avatar = this.userDataServ.avatarUrl();
		this.tournamentServ.currentMsg.message = this.userDataServ.username();
		this.tournamentServ.sendMessage();
		this.insideTournament = false;
	}

	canDeactivate(): Observable<boolean> | Promise<boolean> | boolean {
		if (this.allowNavigation) {
			return true;
		}

		return new Promise((resolve) => {
			const modalRef = this.modalService.open(ExitConfirmationComponent);
			modalRef.result.then(
			(result) => {
				if (result === 'exit') {
				this.allowNavigation = true;
				resolve(true);
				} else {
				resolve(false);
				}
			},
			(reason) => {
				resolve(false);
			}
			);
		});
	}
}