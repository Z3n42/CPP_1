import { Component, OnInit } from '@angular/core';
import { AbstractControl, FormBuilder, FormsModule, NgForm, ValidationErrors, Validators } from '@angular/forms';
import { Router, ActivatedRoute } from '@angular/router';
import { CommonModule } from '@angular/common';
import { ApiService } from '../../core/services/api.service';

@Component({
  selector: 'app-register',
  standalone: true,
  imports: [CommonModule, FormsModule],
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent implements OnInit {
  images = [
    { src: 'assets/avatar/monstruo-1.png', alt: 'Image 1' },
    { src: 'assets/avatar/monstruo-2.png', alt: 'Image 2' },
    { src: 'assets/avatar/monstruo-3.png', alt: 'Image 3' },
    { src: 'assets/avatar/monstruo-4.png', alt: 'Image 4' },
    { src: 'assets/avatar/monstruo-5.png', alt: 'Image 5' },
    { src: 'assets/avatar/monstruo-6.png', alt: 'Image 6' },
  ];
  selectedImageIndex: number | null = null;
  registerEmail: string | null = null;
  registerPassword: string | null = null;
  confirmPassword: string | null = null;
  registerUsername: string = '';
  loginForm: any;
  showSuccessMessage: boolean = false;

  constructor(private router: Router, private route: ActivatedRoute, private formBuilder: FormBuilder, private apiService: ApiService) {
    this.loginForm = this.formBuilder.group({
      registerEmail: ['', Validators.required],
      registerPassword: ['', [Validators.required, passwordValidator]]
    });
  }
    
  ngOnInit() {}

  selectImage(index: number): void {
    this.selectedImageIndex = index;
  }

  userOptions(form: NgForm): void {
    if (form.invalid) {
            console.log("Form is invalid");
      console.log("Form errors:", form.errors);
      console.log("Form controls:", form.controls);
      console.log("Form status:", form.status);
      return;
    }

    if (this.selectedImageIndex === null) {
      console.log("Avatar not selected");
      alert('Select an avatar');
      return;
    }

    if (this.registerPassword !== this.confirmPassword){
      alert('Password do not match');
      return;
    }

    const newUser = {
      email: this.registerEmail,
      username: this.registerUsername,
      password: this.registerPassword,
      password2: this.confirmPassword,
      avatar: this.selectedImageIndex
    };

    this.apiService.addUser(newUser).subscribe(response => {
      if (response.status === 201) {
        const redirectUrl = response.body.redirectUrl;
        if (redirectUrl) {
          this.router.navigate(['/otp', { source: 'register'}]);
        }
      }
    }, error => {
      alert(error.error.error);
    });
  }

  goToLogin(){
    this.router.navigate(['']);
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
