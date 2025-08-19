import { Component } from '@angular/core';
import { MenuComponent } from '../../shared/components/menu/menu.component';
import { FooterComponent } from '../../shared/components/footer/footer.component';

@Component({
  selector: 'app-settings',
  standalone: true,
  imports: [MenuComponent, FooterComponent],
  templateUrl: './settings.component.html',
  styleUrl: './settings.component.css'
})
export class SettingsComponent {

}
