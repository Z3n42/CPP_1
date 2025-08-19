import { ComponentFixture, TestBed } from '@angular/core/testing';

import { GameFinishedModalComponent } from './game-finished-modal.component';

describe('GameFinishedModalComponent', () => {
  let component: GameFinishedModalComponent;
  let fixture: ComponentFixture<GameFinishedModalComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [GameFinishedModalComponent]
    })
    .compileComponents();
    
    fixture = TestBed.createComponent(GameFinishedModalComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
