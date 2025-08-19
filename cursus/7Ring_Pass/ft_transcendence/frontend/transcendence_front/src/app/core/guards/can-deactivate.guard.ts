
import { PlayComponent } from '../../pages/play/play.component';
import { TournamentComponent } from '../../pages/tournament/tournament.component';
import { CanDeactivateFn } from '@angular/router';
import { Observable } from 'rxjs';
import { ActivatedRouteSnapshot, RouterStateSnapshot } from '@angular/router';

export interface CanComponentDeactivate {
	canDeactivate: () => Observable<boolean> | Promise<boolean> | boolean;
}

export const canDeactivatePlay: CanDeactivateFn<PlayComponent> = (component) => {
	return component.canDeactivate ? component.canDeactivate() : true;
};

export const canDeactivateTournament: CanDeactivateFn<TournamentComponent> = (
	component: TournamentComponent,
	currentRoute: ActivatedRouteSnapshot,
	currentState: RouterStateSnapshot,
	nextState?: RouterStateSnapshot
  ) => {

	if (nextState?.url.includes("play")) {
		return true;
	}
	return component.canDeactivate ? component.canDeactivate() : true;
};

