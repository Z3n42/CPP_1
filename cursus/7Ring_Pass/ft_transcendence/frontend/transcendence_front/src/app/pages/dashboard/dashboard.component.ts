import { Component } from '@angular/core';
import { RouterLink, Router } from '@angular/router';
import { MenuComponent } from '../../shared/components/menu/menu.component';
import { FooterComponent } from '../../shared/components/footer/footer.component';


@Component({
  selector: 'app-dashboard',
  standalone: true,
  imports: [RouterLink, MenuComponent, FooterComponent],
  templateUrl: './dashboard.component.html',
  styleUrl: './dashboard.component.css'
})
export class DashboardComponent {
	constructor(private router: Router){ }
	
	generateUniqueId(): string {
		const timestamp = Date.now().toString(36); // Convert timestamp to base-36 string
		const random = Math.random().toString(36).substring(2, 15); // Generate a random string
		return `${timestamp}${random}`;
	}
	
	navigateToOnlineGame(){
		this.router.navigate(['/play', this.generateUniqueId()]);
	}
}
