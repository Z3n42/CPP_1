import { Component } from '@angular/core';
import { RouterLink } from '@angular/router';
import { MenuComponent } from '../../shared/components/menu/menu.component';
import { FooterComponent } from '../../shared/components/footer/footer.component';
import { ChatComponent } from '../../shared/components/chat/chat.component';

@Component({
  selector: 'app-main-chat',
  standalone: true,
  imports: [RouterLink, MenuComponent, FooterComponent, ChatComponent],
  templateUrl: './main-chat.component.html',
  styleUrl: './main-chat.component.css'
})

export class MainChatComponent {


}
