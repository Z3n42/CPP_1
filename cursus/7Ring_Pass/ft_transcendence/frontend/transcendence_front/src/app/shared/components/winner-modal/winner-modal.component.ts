import { Component, Input } from '@angular/core';
import { NgbModal } from '@ng-bootstrap/ng-bootstrap';

@Component({
  selector: 'app-winner-modal',
  standalone: true,
  imports: [],
  templateUrl: './winner-modal.component.html',
  styleUrl: './winner-modal.component.css'
})
export class WinnerModalComponent {
  @Input() winner!: string;

  constructor(private activeModal: NgbModal) {}

}
