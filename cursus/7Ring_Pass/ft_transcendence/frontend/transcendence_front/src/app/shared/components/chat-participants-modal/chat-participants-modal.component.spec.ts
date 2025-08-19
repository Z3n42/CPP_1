import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ChatParticipantsModalComponent } from './chat-participants-modal.component';

describe('ChatParticipantsModalComponent', () => {
  let component: ChatParticipantsModalComponent;
  let fixture: ComponentFixture<ChatParticipantsModalComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [ChatParticipantsModalComponent]
    })
    .compileComponents();
    
    fixture = TestBed.createComponent(ChatParticipantsModalComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
