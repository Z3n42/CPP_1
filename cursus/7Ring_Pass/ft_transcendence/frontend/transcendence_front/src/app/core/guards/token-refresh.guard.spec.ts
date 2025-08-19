import { TestBed } from '@angular/core/testing';
import { CanActivateFn } from '@angular/router';

import { tokenRefreshGuard } from './token-refresh.guard';

describe('tokenRefreshGuard', () => {
  const executeGuard: CanActivateFn = (...guardParameters) => 
      TestBed.runInInjectionContext(() => tokenRefreshGuard(...guardParameters));

  beforeEach(() => {
    TestBed.configureTestingModule({});
  });

  it('should be created', () => {
    expect(executeGuard).toBeTruthy();
  });
});
