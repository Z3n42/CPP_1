import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';


@Injectable()
export class OauthService {
  private clientId: string = process.env['CLIENT_ID'] || '';
  private redirectUri: string = `https://${window.location.hostname}:8443/user/42/register/`;

  constructor(private http: HttpClient, private router: Router) {}

  login() {
    window.location.href = `https://api.intra.42.fr/oauth/authorize?client_id=${this.clientId}&redirect_uri=${this.redirectUri}&response_type=code`;
  }

  handleAuthCallback() {
    const urlParams = new URLSearchParams(window.location.search);
    const authCode = urlParams.get('code');

    if (authCode) {
      this.http.post('https://api.intra.42.fr/token', {
        code: authCode,
        client_id: this.clientId,
        redirect_uri: this.redirectUri,
        grant_type: 'authorization_code'
      }).subscribe((response: any) => {
        localStorage.setItem('access_token', response.access_token);
        this.router.navigate(['/']);
      });
    }
  }
}
