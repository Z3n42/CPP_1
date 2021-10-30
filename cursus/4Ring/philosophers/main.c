/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:07 by ingonzal          #+#    #+#             */
/*   Updated: 2021/10/25 15:35:57 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

typedef struct s_philo{
	int				id;
	int				num;
	int				*fork;
	int				date;
	long			die;
	long			life;
	int				eat;
	int				sleep;
	int				times;
	pthread_mutex_t	*mutex;
}	t_philo;



void *ft_routine(void *tid)
{
	t_philo	philo;
	struct timeval live;

	philo = *(t_philo *)tid;
	pthread_mutex_unlock(philo.mutex);
	gettimeofday(&live, NULL);
	while (((live.tv_sec * 1000) + (live.tv_usec / 1000)) < philo.die)
	{
		gettimeofday(&live, NULL);
	/* pthread_mutex_lock(&mutex); */
		printf("%ld Philo %d\n", (live.tv_sec * 1000), philo.id);
		/* printf("Num =>%d\n", philo.num); */
	/* pthread_mutex_unlock(&mutex); */
	}
	printf("%ld Philo %d++++++die++++++\n", live.tv_sec * 1000 , philo.id);
	return (0);
}

void	ft_create(t_philo philo)
{
	int 			i;
	pthread_t		*thread;
	struct timeval time;
	
	pthread_mutex_init(philo.mutex, NULL);
	/* philo.id = 0; */
	thread = malloc(philo.num * sizeof(pthread_t));
	gettimeofday(&time, NULL);
	i = -1;
	while (++i < philo.num)
	{
		pthread_mutex_lock(philo.mutex);
		philo.id = i + 1;
		philo.die = (time.tv_sec * 1000) + (time.tv_usec / 1000) + philo.life;
		/* printf("WITH MICROSEC: ->%ld\n", time.tv_sec * 1000 + time.tv_usec / 1000 + philo.life); */
		/* printf("NO_MICROSEC: ->%ld\n", time.tv_sec * 1000 + philo.life); */
		/* printf("NO_MICROSEC: ->%f\n", (float)time.tv_sec * 1000 + philo.life); */
		/* printf("MICROSEC: ->%d\n", time.tv_usec / 1000); */
		/* printf("MICROSEC: ->%f\n", (float)time.tv_usec / 1000); */
		/* printf("MICROSEC: ->%f\n", (float)time.tv_usec); */
		pthread_create(&thread[i], NULL, ft_routine, &philo);
	}
	i = -1;
	while (++i < philo.num)
		pthread_join(thread[i], NULL);
	pthread_mutex_destroy(philo.mutex);
	free(philo.mutex);
	free(thread);
}

void	ft_init(int argc, char** argv)
{
	(void)			argc;
	t_philo			philo;
	
	philo.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo.num = ft_atoi(argv[1]);
	philo.life = ft_atoi(argv[2]);
	philo.eat = ft_atoi(argv[3]);
	philo.sleep = ft_atoi(argv[4]);
	philo.fork = malloc(philo.num * sizeof(int));
	if(philo.num < 1 || philo.life < 1 || philo.eat < 1 || philo.sleep < 1) 
		return ;
	if(!philo.num || !philo.life || !philo.eat || !philo.sleep) 
		return ;
	ft_create(philo);
}

int main(int argc, char** argv )
{
	if(argc >= 5 && argc <= 6)
		ft_init(argc, argv);
	else
		return (0);
}
