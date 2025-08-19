import { Component } from '@angular/core';
import { MenuComponent } from '../../shared/components/menu/menu.component';
import { FooterComponent } from '../../shared/components/footer/footer.component';

@Component({
  selector: 'app-about',
  standalone: true,
  imports: [MenuComponent, FooterComponent],
  templateUrl: './about.component.html',
  styleUrl: './about.component.css'
})
export class AboutComponent {

}
