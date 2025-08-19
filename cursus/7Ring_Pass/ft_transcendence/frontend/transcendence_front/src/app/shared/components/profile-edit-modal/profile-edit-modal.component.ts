import { Component, Input, OnInit } from '@angular/core';
import { NgbActiveModal } from '@ng-bootstrap/ng-bootstrap';
import { FormBuilder, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';
import { CommonModule } from '@angular/common';
import { UserDataService } from '../../../core/services/user-data.service';
import { ApiService } from '../../../core/services/api.service';

@Component({
  selector: 'app-profile-edit-modal',
  standalone: true,
  imports: [ReactiveFormsModule, CommonModule],
  templateUrl: './profile-edit-modal.component.html', 
  styleUrl: './profile-edit-modal.component.css'
})
export class ProfileEditModalComponent implements OnInit {
  @Input() username: string = '';
  @Input() avatarUrl: string = '';

  editForm: FormGroup;
  selectedFile: File | null = null;
  fileError: string = '';

  constructor(public activeModal: NgbActiveModal, private fb: FormBuilder, public userDataSrv: UserDataService, private apiSrv: ApiService) {
    this.editForm = this.fb.group({
      username: [this.username, Validators.required],
      avatar: ['']
    });
  }

  ngOnInit(): void {
    this.editForm.patchValue({ username: this.username })
  }

  onFileChange(event: any) {
    this.fileError = '';
    if (event.target.files.length > 0) {
      const file: File = event.target.files[0];
      const fileType = file.type;
      if (fileType === 'image/jpeg' || fileType === 'image/png') {
        this.selectedFile = file;
      } else {
        this.selectedFile = null;
        this.fileError = 'Only JPG and PNG files are allowed.';
      }
    }
  }

  onSubmit() {
    if (this.editForm.valid) {
      const formData = new FormData();
      formData.append('username', this.editForm.get('username')?.value);
      if (this.selectedFile) {
        formData.append('avatar', '7');
        formData.append('customAvatar', this.selectedFile);
      }
      this.apiSrv.userUpdate(formData).subscribe(
        (response) => {
          this.activeModal.close(response);
        },
        (error) => {
          if (error.error.username) {
            alert(error.error.username[0]);
          } else {
            alert('An unknown error occurred.')
          }
        }
      )
    }
  }
}
