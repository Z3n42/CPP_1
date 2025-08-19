import { Component, OnInit } from '@angular/core';
import { MenuComponent } from '../../shared/components/menu/menu.component';
import { FooterComponent } from '../../shared/components/footer/footer.component';
import { UserDataService } from '../../core/services/user-data.service';
import { FormsModule } from '@angular/forms';
import { ApiService } from '../../core/services/api.service';
import { CommonModule } from '@angular/common';
import { forkJoin, Observable } from 'rxjs';
import { UserStatus } from '../../core/models/user.model';
import { NgbModal } from '@ng-bootstrap/ng-bootstrap';
import { ProfileEditModalComponent } from '../../shared/components/profile-edit-modal/profile-edit-modal.component';

@Component({
  selector: 'app-profile',
  standalone: true,
  imports: [MenuComponent, FooterComponent, FormsModule, CommonModule],
  templateUrl: './profile.component.html',
  styleUrl: './profile.component.css'
})
export class ProfileComponent implements OnInit {
  username: string = '';
  searchUsername: string = '';
  searchedUser: any = null;
  searchAttempted: boolean = false;
  friendsList: UserStatus[] = [];
  blockedList: any[] = [];
  allUsers: any[] = [];
  is2FAEnabled: boolean = false;

  constructor(private modalService: NgbModal, public userDataSrv: UserDataService, private apiSrv: ApiService){}

  ngOnInit(): void {
    this.loadFriendList();
    this.loadBlockedList();
    this.loadAllUsers();
  }

  loadAllUsers(): void {
    this.apiSrv.getUsers().subscribe(
      (response) => {
        this.allUsers = response;
      },
      (error) => {
        console.error('Error loading users', error);
      }
    );
  }

  loadFriendList(): void {
    this.friendsList = [];
    this.apiSrv.getFriends(this.userDataSrv.username()).subscribe(
      (response) => {
        const friends = response.friends;
        const userDataObservables: Observable<UserStatus>[] = friends.map((friendUsername: string) =>
          this.apiSrv.userDataIsOnline(friendUsername)
        );
        forkJoin(userDataObservables).subscribe(
        (userDataResponses: UserStatus[]) => {
          this.friendsList = userDataResponses;
          console.log(this.friendsList);
        },
        (error) => {
          console.error('Error loading friends', error);
        });
      },
      (error) => {
        console.error('Error loading friends list', error);
      }
    );
  }

  addFriend(username: string): void {
    const user = {
			username: username
		};
    this.apiSrv.addFriend(user).subscribe(
      (response) => {
        this.loadFriendList();
        alert('Friend added successfully');
      },
      (error) => {
        console.error('Error adding friend', error);
      }
    );
  }

  removeFriend(username: string): void {
    const user = {
      username: username
    };
    this.apiSrv.removeFriend(user).subscribe(
      (response) => {
        this.loadFriendList();
        alert('Friend removed successfully');
      },
      (error) => {
        console.error('Error removing friend', error);
      }
    );
  }

  loadBlockedList(): void {
    this.blockedList = [];
    this.apiSrv.getBlockedUsers(this.userDataSrv.username()).subscribe(
      (response) => {
        const blocked = response.blocked;
        forkJoin(blocked).subscribe(
          this.blockedList = blocked)
        },
        (error) => {
          console.error('Error loading friends', error);
        }
    );
  }

  addBlocked(username: string): void {
    const user = {
			username: username
		};
    this.apiSrv.addBlockedUser(user).subscribe(
      (response) => {
        this.loadBlockedList();
        alert('User blocked successfully');
      },
      (error) => {
        console.error('Error blocking user', error);
      }
    );
  }

  removeBlocked(username: string): void {
    const user = {
      username: username
    };
    this.apiSrv.removeBlockedUser(user).subscribe(
      (response) => {
        this.loadBlockedList();
        alert('User unblocked successfully');
      },
      (error) => {
        console.error('Error unblocking user', error);
      }
    );
  }

  searchUser(): void {
    this.searchAttempted = true;
    if (this.searchUsername) {
      this.searchedUser = this.allUsers.find(user => user.username.toLowerCase() === this.searchUsername.toLowerCase());
      if (!this.searchedUser) {
        console.error('User not found');
      }
    }
  }

  openEditModal() {
    const modalRef = this.modalService.open(ProfileEditModalComponent);
    modalRef.componentInstance.username = this.userDataSrv.username();
    modalRef.result.then((result) => {
      if (result) {
        this.userDataSrv.setUser(result);
        console.log(result);
      }
    }, (reason) => {
      console.log('Dismissed:', reason);
    });
  }
  
    update2FAStatus(): void {
    const updateUser = { is_2fa: this.is2FAEnabled };
    this.apiSrv.userUpdate(updateUser).subscribe(
      (response) => {
        console.log('2FA status updated', response);
        this.userDataSrv.setIs2FAEnabled(this.is2FAEnabled);
      },
      (error) => {
        console.error('Error updating 2FA status', error);
      }
    );
  }
}
