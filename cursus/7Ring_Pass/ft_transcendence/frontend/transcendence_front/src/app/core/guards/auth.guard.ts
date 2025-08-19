import { Injectable, inject } from '@angular/core';
import { ActivatedRouteSnapshot, CanActivate, CanActivateChildFn, CanActivateFn, Router, RouterState, RouterStateSnapshot } from '@angular/router';
import { ApiService } from '../services/api.service';

@Injectable({
  providedIn: 'root'
})
class PermissionsService{
  constructor(private router: Router, private apiSrv: ApiService){}

  canActivate(next: ActivatedRouteSnapshot, state: RouterStateSnapshot): boolean{
    const loggedIn = this.apiSrv.isLoggedIn();
    if (loggedIn) {
      return true;
    } else {
      this.router.navigate(['/login']);
      return false;
    }
  }
}

export const AuthGuard: CanActivateFn = (next: ActivatedRouteSnapshot, state: RouterStateSnapshot): boolean => { 
  return inject(PermissionsService).canActivate(next, state);
}