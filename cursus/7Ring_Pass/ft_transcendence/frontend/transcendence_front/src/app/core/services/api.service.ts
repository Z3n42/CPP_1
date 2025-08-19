import { Injectable } from '@angular/core';
import { HttpClient, HttpErrorResponse, HttpHeaders, HttpResponse } from '@angular/common/http';
import { Observable, Subject, of, throwError } from 'rxjs';  
import { catchError, map, switchMap, tap } from 'rxjs/operators';
import { Router } from '@angular/router';

@Injectable({
	providedIn: 'root'
  })

  export class ApiService {
	private apiUrl = `https://${window.location.hostname}:8443`;
	private tokenRefreshInterval: any = null;
	
 
	constructor(private http: HttpClient, private router: Router) {
	}

	isLoggedIn(): boolean {
		return !!localStorage.getItem('accessToken');
	}
  
	getUsers(): Observable<any[]> {
		const headers = new HttpHeaders({
      		Authorization: `JWT ${this.getAccessToken()}`
    	});
	  	return this.http.get<any[]>((this.apiUrl + '/user/'), { headers })
		.pipe(
		  catchError(this.handleError<any[]>('getUsers', []))
		);
	}

	userDataById(username: string): Observable<{ username: string; avatar: number; customAvatar: string}> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
		});
		return this.http.get<any>(`${this.apiUrl}/user/idData/${username}/`, { headers })
		.pipe(
			map(response =>({
				username: response.username,
				avatar: response.avatar,
				customAvatar: response.customAvatar
			})),
			catchError(this.handleError<{ username: string; avatar: number; customAvatar: string }>('userDataById', { username: '', avatar: 1, customAvatar: '' }))
		);
	}

	getMe(): Observable<any> {
		const headers = new HttpHeaders({
      		Authorization: `JWT ${this.getAccessToken()}`
    	});
		return this.http.get(`${this.apiUrl}/user/me/`, { headers })
		.pipe(
			catchError(this.handleError<any>('getMe', null))
		);
	}

	addUser(newUser:any): Observable<HttpResponse<any>> {
		return this.http.post<any>(`${this.apiUrl}/user/register/`, newUser, { observe: 'response'})
	}
  
	userLogin(userCredentials:{email: string; password: string}): Observable<any> {
		return this.http.post<any>(`${this.apiUrl}/user/login/`, userCredentials).pipe(
      		tap((response: any) => {
				if (response.access && response.refresh) {
        			localStorage.setItem('accessToken', response.access);
        			localStorage.setItem('refreshToken', response.refresh);
				}
      		})
    	);
	}

	userUpdate(updateUser: any): Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
	  	});
		return this.http.put<any>(`${this.apiUrl}/user/me/`, updateUser, { headers })
		.pipe(
			catchError(this.handleError<any>('userUpdate', null))
		)
	}

	userDataIsOnline(username: string): Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
		});
		return this.http.get<any>(`${this.apiUrl}/user/data/${username}/`, { headers })
		.pipe(
			map(response =>({
				username: response.username,
				is_online: response.is_online
			})),
			catchError(this.handleError<any>('userDataIsOnline', null))
		);
	}

	//Chat Endpoints
	addChatRoom(roomName: string) : Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
		});
		return this.http.post<any>(`${this.apiUrl}/user/add_chatRoom/${roomName}/`, {}, { headers })
		.pipe(
			catchError(this.handleError<any>('addChatRoom', null))
		)
	}

	getUsersInChatRoom(roomName: string) : Observable<{usernames: string[]}> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
		});
		return this.http.get<any>(`${this.apiUrl}/user/users_in_chatRoom/${roomName}/`, { headers })
		.pipe(
			catchError(this.handleError<any>('getUsersInChatRoom', null))
		)
	}

	removeChatRoom(roomName: string) : Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
		});
		return this.http.post<any>(`${this.apiUrl}/user/remove_chatRoom/${roomName}/`, {}, { headers })
		.pipe(
			catchError(this.handleError<any>('removeChatRoom', null))
		)
	}

	//Blocked and Friend Endpoints
	addFriend(user:{username: string}): Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
	  	});
    	return this.http.post<any>(`${this.apiUrl}/user/addFriend/`, user, { headers })
		.pipe(
			catchError(this.handleError<any>('addFriend', null))
		)
  	}

	removeFriend(user:{username: string}): Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
	  	});
    	return this.http.post<any>(`${this.apiUrl}/user/removeFriend/`, user, { headers })
		.pipe(
			catchError(this.handleError<any>('removeFriend', null))
		)
  	}

	getFriends(username: string): Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
	  	});
    	return this.http.get<any>(`${this.apiUrl}/user/friends_list/`, { headers })
		.pipe(
			catchError(this.handleError<any>('getFriends', null))
		)
	}	

	addBlockedUser(user:{username: string}): Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
	  	});
    	return this.http.post<any>(`${this.apiUrl}/user/blockUser/`, user, { headers })
		.pipe(
			catchError(this.handleError<any>('addBlockedUser', null))
		)
  	}

	removeBlockedUser(user:{username: string}): Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
	  	});
    	return this.http.post<any>(`${this.apiUrl}/user/unBlockUser/`, user, { headers })
		.pipe(
			catchError(this.handleError<any>('removeBlockedUser', null))
		)
  	}

	getBlockedUsers(username: string): Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
	  	});
    	return this.http.get<any>(`${this.apiUrl}/user/blocked_list/`, { headers })
		.pipe(
			catchError(this.handleError<any>('getBlockedUsers', null))
		)
	}

	amIblocked(username: string): Observable <any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
		});
		return this.http.get<any>(`${this.apiUrl}/user/am_i_blocked/${username}/`, { headers })
		.pipe(
			catchError((error: any) => {
				if (error.status === 401) {
					return this.handleError<any>('amIblocked', null)(error);
				} else {
					return throwError(() => error);
				}
			})
		);
	}

	// GAMES Endpoints
	getGames(): Observable<any> {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
		});
		return this.http.get<any>(`${this.apiUrl}/user/games/`, { headers })
		.pipe(
			catchError(this.handleError<any>('getGames', null))
		)
	}


	// OTP Endpoints
	otpValidation(userCredentials:any, forget: boolean): Observable<any> {
		let headers = new HttpHeaders();
		if (forget) {
			headers = headers.set('forgot', 'true');
		}
		return this.http.post<any>(`${this.apiUrl}/user/otp/`, userCredentials, { headers }).pipe(
      		tap((response: any) => {
        		localStorage.setItem('accessToken', response.access);
        		localStorage.setItem('refreshToken', response.refresh);
			})
    	);
	}

	otpReSend(email:string): Observable<any> {
		return this.http.post<any>(`${this.apiUrl}/user/otp/send/`, { email: email}, { observe: 'response'})
		.pipe(
			catchError(this.handleError<any>('otpReSend', null))
		)
	}

	//TOKENS Endpoints
	getAccessToken(): string | null {
    	return localStorage.getItem('accessToken');
  	}

	refreshTokenCall(): Observable<any> {
    	return this.http.post(`${this.apiUrl}/user/login/refresh/`, { refresh: localStorage.getItem('refreshToken')}).pipe(
      	tap((response: any) => {
        	localStorage.setItem('accessToken', response.access);
        	localStorage.setItem('refreshToken', response.refresh);
			//this.startTokenRefresh();
      	}),
		catchError(error =>{
			if (error.status === 401) {
				localStorage.removeItem('accessToken');
				localStorage.removeItem('refreshToken');
				localStorage.clear();
				this.router.navigate(['']);
			}
			return throwError(error);
		}));
  	}

	/*startTokenRefresh() {
		this.stopTokenRefresh();
		if (!this.tokenRefreshInterval){
    		setInterval(() => {
      			this.refreshTokenCall().subscribe();
    		}, 175000); // 2:55 minutos
		}
  	}

	stopTokenRefresh() {
    	if (this.tokenRefreshInterval) {
      		clearInterval(this.tokenRefreshInterval);
      		this.tokenRefreshInterval = null;
    	}
  	}*/

	logout() {
		const headers = new HttpHeaders({
			Authorization: `JWT ${this.getAccessToken()}`
	  	});
		return this.http.post(`${this.apiUrl}/user/logout/`, {refresh: localStorage.getItem('refreshToken')}, { headers }).pipe(
			tap((response:any) => {
				localStorage.removeItem('accessToken');
				localStorage.removeItem('refreshToken');
				localStorage.clear();
				this.router.navigate(['']);
			}),
				catchError(this.handleError<any>('logout', null))
			);
  	}
  
	private handleError<T>(operation = 'operation', result?: T) {
		return (error: any): Observable<T> => {
			if (error.status === 401) {
				return this.refreshTokenCall().pipe(
					switchMap((response) => {
						localStorage.setItem('accessToken', response.access);
						localStorage.setItem('refreshToken', response.refresh);
						return of(result as T);
					}),
					catchError((error) =>{
						this.logout();
						return throwError(() => error);
					})
				);
   		 	} else {
		  		console.error(`${operation} failed: ${error.message}`);
		  		return of(result as T);
			}
		};
	  }
  }