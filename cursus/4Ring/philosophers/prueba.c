/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:54:47 by ingonzal          #+#    #+#             */
/*   Updated: 2021/10/08 20:05:18 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int mails = 0;
pthread_mutex_t mutex;

void *routine()
{
	int i;

	i = 0;
	printf("Antes =>%d\n", mails);
	pthread_mutex_lock(&mutex);
	while (i < 10000000) 
	{
		mails++;
		i++;
	}
	pthread_mutex_unlock(&mutex);
	printf("Despues =>%d\n", mails);
	/* return (0); */
}

int	main(int argc, char** argv)
{

	(void)argc;
	(void)argv;
	pthread_mutex_init(&mutex, NULL);
	pthread_t t1;
	pthread_t t2;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("Total =>%d\n", mails);
	pthread_mutex_destroy(&mutex);
	return (0);
}
