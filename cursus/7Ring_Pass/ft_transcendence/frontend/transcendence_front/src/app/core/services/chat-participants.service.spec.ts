import { TestBed } from '@angular/core/testing';

import { ChatParticipantsService } from './chat-participants.service';

describe('ChatParticipantsService', () => {
  let service: ChatParticipantsService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(ChatParticipantsService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
