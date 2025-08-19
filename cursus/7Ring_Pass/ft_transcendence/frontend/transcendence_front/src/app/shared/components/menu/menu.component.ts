import { Component, OnInit } from '@angular/core';
import { Router, RouterLink } from '@angular/router';
import { ApiService } from '../../../core/services/api.service';
import { UserDataService } from '../../../core/services/user-data.service';
import { HttpClientModule } from '@angular/common/http';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'app-menu',
  standalone: true,
  imports: [CommonModule, HttpClientModule, RouterLink],
  templateUrl: './menu.component.html',
  styleUrl: './menu.component.css'
})
export class MenuComponent implements OnInit{
	currentRoute: string;
	showHome = true;
	showRank = true;
	showSettings = true;
	showProfile = true;

	constructor(private router: Router, private apiSrv: ApiService, private userDataSrv: UserDataService) {
		this.currentRoute = this.router.url;
	}

	ngOnInit(): void {
		this.userDataSrv.fetchUser();
	}

	atHome(){ return this.currentRoute === '/dashboard' ? true : false }
	atRank(){ return this.currentRoute === '/ranking' ? true : false }
	atChat(){ return this.currentRoute === '/chat' ? true : false }
	atProfile(){ return this.currentRoute === '/profile' ? true : false }

	homeOver() { this.showHome = false; }
	homeOut() { this.showHome = true; }
	rankOver() { this.showRank = false; }
	rankOut() { this.showRank = true; }
	profileOver() { this.showProfile = false; }
	profileOut() { this.showProfile = true; }

	getAvatarUrl(): string {
		return this.userDataSrv.avatarUrl();
	}

	logout() { 
		//this.apiSrv.stopTokenRefresh();
		this.userDataSrv.setUser({ id: '', email: '', username: 'Guest User', avatar: 1, wins: 0, games: 0, is_2fa: false });
		this.apiSrv.logout().subscribe(
			(response) => {
				console.log('Logged out successfully');
			},
			(error) => {
				console.error('Failed to logout', error);
			}
		)
	}
}