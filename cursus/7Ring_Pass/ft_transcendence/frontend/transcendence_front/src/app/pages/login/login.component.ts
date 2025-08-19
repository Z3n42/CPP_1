import { Component, OnInit } from '@angular/core';
import { NgFormModule } from './ngform.module';
import { HttpClient } from '@angular/common/http';
import { OauthService } from '../../core/services/oauth.service';
import { Router } from '@angular/router';
import { CommonModule } from '@angular/common';
import { ApiService } from '../../core/services/api.service';
import { UserDataService } from '../../core/services/user-data.service';

@Component({
  selector: 'app-login',
  standalone: true,
  imports: [NgFormModule, CommonModule],
  templateUrl: './login.component.html',
  styleUrl: './login.component.css'
})

export class LoginComponent {
	email: string = '';
	password: string = '';

	constructor(private http: HttpClient, private authService:OauthService, private router: Router, private apiService: ApiService, private userDataSrv: UserDataService) {}

	onLogin() {
		const userCredentials = {
			email: this.email,
			password: this.password
		};
		this.apiService.userLogin(userCredentials).subscribe(
			(response) => {
        if (response.access && response.refresh) {
			this.userDataSrv.fetchUser();
			this.router.navigate(['/dashboard']);
        } else if (response.redirectUrl) {
          this.router.navigate(['/otp', { source: 'login' }]);
        }
			},
			(error) => alert(error.error.detail) 
		);
	}

	onRegister() {
	  this.router.navigate(['/register']);
	}

	on42Login() {
	  console.log('42 Login clicked');
	  this.authService.login();
	}

	onForget() {
		this.router.navigate(['/otp', {source: 'forget'}]);
	}
}
