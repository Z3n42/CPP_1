import { Injectable, inject } from '@angular/core';
import { ActivatedRouteSnapshot, CanActivateFn, Router, RouterStateSnapshot } from '@angular/router';
import { ApiService } from '../services/api.service';

@Injectable({
  providedIn: 'root'
})
class PermissionsService{
  constructor(private router: Router, private apiSrv: ApiService){}

  canActivate(next: ActivatedRouteSnapshot, state: RouterStateSnapshot): boolean{
    const excludedRoutes = ['/otp', '/register', '/login'];
    if (!excludedRoutes.includes(state.url)) {
      //this.apiSrv.startTokenRefresh();
    }
    return true;
  }
}

export const tokenRefreshGuard: CanActivateFn = (next: ActivatedRouteSnapshot, state: RouterStateSnapshot) => {
  return inject(PermissionsService).canActivate(next, state);
};
