import { Injectable, effect } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { User } from '../models/user.model';
import { ApiService } from './api.service';
import { firstValueFrom } from 'rxjs';

@Injectable({
	providedIn: 'root'
})
export class UserDataService {
	private user : User = { id: "", email: "", username: "Guest User", avatar: 1, wins: 0, games: 0, is_2fa: false };

	constructor(private http: HttpClient, private apiSrv: ApiService) {
		/* this.initializeUser(); */
	}

	async initializeUser(): Promise<void> {
		await this.fetchUser();
	}

	public async fetchUser(): Promise<void> {
		try {
			const user = await firstValueFrom(this.apiSrv.getMe());
			if (user) {
				this.setUser(user);
			}
		} catch (error) {
			console.error('Failed to fetch user data in UserDataService', error);
			this.apiSrv.logout();
		}
	}

	id() : string { return this.user.id }
	email() : string { return this.user.email; }
	username() : string{ return this.user.username; }
	avatar() : number{ return this.user.avatar; }
	customAvatar(): string | undefined { return this.user.customAvatar; }
	avatarUrl(): string {
		if (this.user.avatar === 7 && this.user.customAvatar) {
			return `https://${window.location.hostname}:8443${this.user.customAvatar}`;
		} else if (this.user.avatar === 0) {
			return `assets/avatar/42.png`;
		} else {
			return `assets/avatar/monstruo-${this.user.avatar}.png`;
		}
	}
	wins() : number{ return this.user.wins; }
	games(): number { return this.user.games; }
	is2faEnabled(): boolean { return this.user.is_2fa; }
	setIs2FAEnabled(isEnabled: boolean): void { this.user.is_2fa = isEnabled; }
	getUser(): User{ return this.user; }
	setUser(user : User) : void { this.user = user; }
}
