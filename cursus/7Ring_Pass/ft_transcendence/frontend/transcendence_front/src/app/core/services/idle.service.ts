import { Injectable, NgZone } from '@angular/core';
import { Router } from '@angular/router';
import { Observable, Subscription, fromEvent, merge, timer } from 'rxjs';
import { switchMap, takeUntil, tap } from 'rxjs/operators';
import { ApiService } from './api.service';
import { error } from 'console';

@Injectable({
  providedIn: 'root'
})
export class IdleService {
  private idleTimeout = 10 * 60 * 1000; // 10 minutos
  private idle$: Observable<any>;
  private timeoutSub: Subscription | undefined;
  
  constructor(private apiSrv: ApiService, private router: Router, private ngZone: NgZone) { 
    this.idle$ = merge(
      fromEvent(document, 'mousemove'),
      fromEvent(document, 'keydown'),
      fromEvent(document, 'click')
    );
  }

  startWatching() {
    if (this.apiSrv.isLoggedIn()) {
      this.ngZone.runOutsideAngular(() => {
        this.timeoutSub = this.idle$.pipe(
          switchMap(() => timer(this.idleTimeout)),//switchMap coge cada evento emitido por this.idle$ y lo transforma en un nuevo Observable. El cual resetea el timer.
          tap(() => this.ngZone.run(() => {this.showIdleModal()})) // tap dispara el Modal
        ).subscribe();
      });
    }
  }

  stopWatching() {
    this.timeoutSub?.unsubscribe();
  }

  private showIdleModal() {
    const userConfirmed = window.confirm('Are you still there?');

    if (!userConfirmed) {
        this.apiSrv.logout();
    } else {
      this.apiSrv.refreshTokenCall().subscribe(
        (response) => {
          this.resetTimeout();
          //this.apiSrv.startTokenRefresh();
        },
        (error) => {
          this.stopWatching();
          this.apiSrv.logout();
        }
      )
    }
  }

  private resetTimeout() {
    this.stopWatching();
    this.startWatching();
  }
}
