import { Routes } from '@angular/router';
import { LoginComponent } from './pages/login/login.component';
import { RegisterComponent } from './pages/register/register.component';
import { DashboardComponent } from './pages/dashboard/dashboard.component';
import { ProfileComponent } from './pages/profile/profile.component';
import { MainChatComponent } from './pages/main-chat/main-chat.component';
import { SettingsComponent } from './pages/settings/settings.component';
import { RankingComponent } from './pages/ranking/ranking.component';
import { AboutComponent } from './pages/about/about.component';
import { PlayComponent } from './pages/play/play.component';
import { TournamentComponent } from './pages/tournament/tournament.component';
import { OtpComponent } from './pages/otp/otp.component';

import { AuthGuard } from './core/guards/auth.guard';
import { canDeactivatePlay } from './core/guards/can-deactivate.guard';
import { canDeactivateTournament } from './core/guards/can-deactivate.guard';
import { tokenRefreshGuard } from './core/guards/token-refresh.guard';
import { userDataResolver } from './core/services/user-data.resolver';

export const routes: Routes = [
    { path: '', redirectTo:'/login', pathMatch: 'full'},
    { path: 'login', component: LoginComponent},
    { path: 'register', component: RegisterComponent},
    { path: 'otp', component: OtpComponent },
    { path: 'otp/:source', component: OtpComponent},
    { path: 'dashboard', component: DashboardComponent, resolve: { userData: userDataResolver }, canActivate: [AuthGuard, tokenRefreshGuard]},
    { path: 'profile', component: ProfileComponent, resolve: { userData: userDataResolver }, canActivate: [AuthGuard, tokenRefreshGuard]},
    { path: 'ranking', component: RankingComponent, canActivate: [AuthGuard, tokenRefreshGuard]},
    { path: 'chat', component: MainChatComponent, resolve: { userData: userDataResolver }, canActivate: [AuthGuard, tokenRefreshGuard]},
    { path: 'settings', component: SettingsComponent, canActivate: [AuthGuard, tokenRefreshGuard]},
    { path: 'about', component: AboutComponent, canActivate: [AuthGuard, tokenRefreshGuard]},
    { path: 'play', component: PlayComponent, canDeactivate: [canDeactivatePlay, AuthGuard, tokenRefreshGuard]},
    { path: 'play/:id', component: PlayComponent, resolve: { userData: userDataResolver }, canDeactivate: [canDeactivatePlay, AuthGuard, tokenRefreshGuard]},
    { path: 'tournament', component: TournamentComponent, canDeactivate: [canDeactivateTournament, AuthGuard, tokenRefreshGuard]},
    { path: '**', component: DashboardComponent, canActivate: [AuthGuard, tokenRefreshGuard]}
];
