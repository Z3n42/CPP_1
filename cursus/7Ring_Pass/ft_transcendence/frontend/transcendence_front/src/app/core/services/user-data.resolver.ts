import { inject } from '@angular/core';
import { ResolveFn } from '@angular/router';
import { UserDataService } from './user-data.service';

export const userDataResolver: ResolveFn<void> = () => {
	const userDataService = inject(UserDataService);
	return userDataService.initializeUser();
};
