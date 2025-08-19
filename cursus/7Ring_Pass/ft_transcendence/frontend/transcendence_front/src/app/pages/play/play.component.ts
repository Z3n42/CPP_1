import { Component, OnInit } from '@angular/core';
import { MenuComponent } from '../../shared/components/menu/menu.component';
import { FooterComponent } from '../../shared/components/footer/footer.component';
import { ChatComponent } from '../../shared/components/chat/chat.component';
import { GameComponent } from '../../shared/components/game/game.component';
import { NgbModal, NgbModalOptions, NgbModule } from '@ng-bootstrap/ng-bootstrap';
import { Observable } from 'rxjs';
import { ActivatedRoute, Router} from '@angular/router';

import { CanComponentDeactivate } from '../../core/guards/can-deactivate.guard';
import { ExitConfirmationComponent } from '../../shared/components/exit-confirmation/exit-confirmation.component';
import { GameFinishedModalComponent } from '../../shared/components/game-finished-modal/game-finished-modal.component';
import { GameService } from '../../core/services/game.service';

@Component({
  selector: 'app-play',
  standalone: true,
  imports: [MenuComponent, FooterComponent, ChatComponent, GameComponent, NgbModule],
  templateUrl: './play.component.html',
  styleUrl: './play.component.css'
})

export class PlayComponent implements OnInit, CanComponentDeactivate{
	private allowNavigation = false;
	gameId: string = '';

	constructor(private route: ActivatedRoute, private router: Router, private modalService: NgbModal, public gameService: GameService) {
	}

	ngOnInit(): void {
		this.route.paramMap.subscribe(params => {
			this.gameId = params.get('id')!;
		});
	}

	canDeactivate(): Observable<boolean> | Promise<boolean> | boolean {
		if (this.allowNavigation) {
			return true;
		}

		const modalOptions: NgbModalOptions = {
			backdrop: 'static',
			keyboard: false
		};

		return new Promise((resolve) => {
			const modalRef = this.gameService.gameInProgress ? this.modalService.open(ExitConfirmationComponent) : this.modalService.open(GameFinishedModalComponent, modalOptions);
			if (this.gameService.gameInProgress === false){
				modalRef.componentInstance.winner = this.gameService.winner;
			}
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