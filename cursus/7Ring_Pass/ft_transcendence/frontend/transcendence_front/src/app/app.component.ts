import { Component, OnInit } from '@angular/core';
import { Router, RouterOutlet } from '@angular/router';
import { LoginComponent } from './pages/login/login.component';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';
import { HttpClientModule } from '@angular/common/http';
import { FormsModule } from '@angular/forms';
import { ApiService } from './core/services/api.service';

const MODULES = [
  RouterOutlet,
  LoginComponent,
  NgbModule,
  HttpClientModule,
  FormsModule,
];

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [MODULES],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {

  constructor(private apiSrv: ApiService, private router: Router){}
  
  title = 'transcendence_front';
}
