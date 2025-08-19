import { HttpClient } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { Router, ActivatedRoute } from '@angular/router';
import { ApiService } from '../../core/services/api.service';
import { AbstractControl, NgForm, FormGroup, ReactiveFormsModule, FormsModule, ValidationErrors, Validators } from '@angular/forms';
import { CommonModule } from '@angular/common';
import { UserDataService } from '../../core/services/user-data.service';

@Component({
  selector: 'app-otp',
  standalone: true,
  imports: [FormsModule, CommonModule, ReactiveFormsModule],
  templateUrl: './otp.component.html',
  styleUrl: './otp.component.css'
})
export class OtpComponent implements OnInit{
  email: string = '';
  otp: string = '';
  newPassword: string = '';
  confirmPassword: string = '';
  showSuccessMessage: boolean = false;
  source: string | null = null;
  tittleLabel: string = 'OTP';
  buttonLabel: string = 'Send OTP';
  emailSubmitted: boolean = false;
  validOTP: boolean = false;
  forget: boolean = false;

  constructor(private http: HttpClient, private router: Router, private apiSrv: ApiService, private route: ActivatedRoute, private userDataSrv: UserDataService) {}

  ngOnInit(): void {
    this.route.paramMap.subscribe(param => {
      this.source = param.get('source');
      if (this.source === 'register' || this.source === 'forget'){
        this.tittleLabel = 'Verify your Email';
        this.buttonLabel = 'Validate';
      } else if (this.source === 'login' ){
        this.buttonLabel = 'Login';
      }
    });
  }

  onLogin() {
    const userCredentials = {
      email: this.email,
      otp: this.otp
    };

    if (this.source === 'forget'){ this.forget = true }

    this.apiSrv.otpValidation(userCredentials, this.forget).subscribe(
      (response) => {
        if (this.source === 'register') {
          console.log("Registration successful");
          this.showSuccessMessage = true;
        } else {
          localStorage.setItem('accessToken', response.access);
          localStorage.setItem('refreshToken', response.refresh);
          if (this.source === 'forget'){
            this.validOTP = true;
            this.emailSubmitted = true; 
          } else {
            //this.apiSrv.startTokenRefresh();
            this.userDataSrv.fetchUser();
            this.router.navigate(['dashboard']);
          }
        }
      },
      (error) => alert('Login failed') 
    );
  }

  onUpdatePassword(passwordForm: NgForm) {
    if (passwordForm.invalid){
      return;
    }

    if (this.newPassword !== this.confirmPassword) {
      alert('Passwords do not match');
      return;
    }

    const updateCredentials = {
      email: this.email,
      password: this.newPassword,
      password2: this.confirmPassword
    };

    this.apiSrv.userUpdate(updateCredentials).subscribe(
      (response) => {
        alert('Password updated successfully');
        this.redirectToLogin();
      },
      (error) => alert('Failed to update password')
    );
  }
    
  redirectToLogin(): void {
    this.apiSrv.logout();
    this.router.navigate(['/login']);
  }

  reSend(){
    if (this.email){
      this.apiSrv.otpReSend(this.email).subscribe(response => {
        if (response.status === 200) {
          alert('OTP resent successfully');
          this.emailSubmitted = true;
        }
      },
      (error) => {
        if (error.status = 404){
          alert('Email is not registered');
        } else {
          alert(error.message);
        }
      });
    } else {
      alert('Email required!');
    }
  }
}


export function passwordValidator(control: AbstractControl): ValidationErrors | null {
  const password = control.value;
  
  if (!password) {
    return null;
  }

  const hasNumber = /\d/.test(password);
  const hasUpperCase = /[A-Z]/.test(password);
  const hasSymbol = /[(){}\[\]|\\`~!@#$%^&*_\-+=;:'",<>./?]/.test(password);

  const valid = hasNumber && hasUpperCase && hasSymbol;
  
  if (!valid) {
    return {
      passwordStrength: {
        hasNumber,
        hasUpperCase,
        hasSymbol
      }
    };
  }

  return null;
}
