/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:07 by ingonzal          #+#    #+#             */
/*   Updated: 2021/11/24 17:43:04 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "ft_philo.h"

void ft_die(t_ph *ph)
{
	struct timeval	die;

	if (ph->kill == 0)
	{
		gettimeofday(&die, NULL);
		ph->life = (die.tv_sec * 1000) + (die.tv_usec / 1000);
		printf("%ld %d died+++++++++++++++++++++++\n", (ph->die - ph->life), ph->id);
		exit(0);
	}
	ph->kill = 1;
}

void	ft_sleep(t_ph *ph)
{
	struct timeval	sleep;
	long			sleeptime;
	
	sleeptime = 0;
	if (ph->kill == 0)
	{
		gettimeofday(&sleep, NULL);
		ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		/* ph->die = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000) + ph->blood; */
		printf("%ld %d is sleeping\n", (ph->die - ph->life), ph->id);
		gettimeofday(&sleep, NULL);
		ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
		sleeptime = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000) + ph->sleep;
		while (ph->life < sleeptime)
		{
			gettimeofday(&sleep, NULL);
			ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
			if ((ph->die - ph->life) < 0)
				ft_die(ph);
		}
		/* usleep(ph->sleep * 999); */
		/* printf("%dzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n", ph->sleep); */
		gettimeofday(&sleep, NULL);
		ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		printf("%ld %d is thinking\n", (ph->die - ph->life), ph->id);
		if (ph->num % 2 != 0/* && ph->eaten == 0*/)
		{
			usleep(sleep.tv_usec / 1000);
			/* ph->eaten = 1; */
		}
	}
	gettimeofday(&sleep, NULL);
	ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	/* ft_fork(ph, tab); */
}

void	ft_eat(t_ph *ph/*, t_tab *tab*/)
{
	struct timeval	eat;
	/* long			time; */
	long			eatime;

	/* time = 0; */
	eatime = 0;
	if (ph->kill == 0)
	{
		gettimeofday(&eat, NULL);
		ph->life = (eat.tv_sec * 1000) + (eat.tv_usec / 1000);
		eatime = (eat.tv_sec * 1000) + (eat.tv_usec / 1000) + ph->eat;
		while (ph->life < eatime)
		{
			gettimeofday(&eat, NULL);
			ph->life = (eat.tv_sec * 1000) + (eat.tv_usec / 1000);
			if ((ph->die - ph->life) < 0)
				ft_die(ph);
		}
		/* usleep(ph->eat * 999); */
		gettimeofday(&eat, NULL);
		ph->life = (eat.tv_sec * 1000) + (eat.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		printf("%ld %d is eating\n", (ph->die - ph->life), ph->id);
		ph->die = (eat.tv_sec * 1000) + (eat.tv_usec / 1000) + ph->blood;
	}
	/* time = (eat.tv_sec * 1000) + (eat.tv_usec / 1000); */
	/* usleep(ph->eat * 1000); */
	/* while (time < ph->eat) */
		/* time = (eat.tv_sec * 1000) + (eat.tv_usec / 1000); */
	if (ph->id == 1)
	{
		ph->fk[ph->id - 1] = -1;
		ph->fk[ph->num - 1] = -1;
		/* pthread_mutex_unlock(ph->mutex); */
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		ft_sleep(ph/*, tab*/);
	}
	else
	{
		ph->fk[ph->id - 1] = -1;
		ph->fk[ph->id - 2] = -1;
		/* pthread_mutex_unlock(ph->mutex); */
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		ft_sleep(ph/*, tab*/);
	}
}

void	ft_fk1(t_ph *ph)
{	
	struct timeval	take;
	
	pthread_mutex_lock(&ph->mutex[ph->id - 1]);
	if (ph->fk[ph->id - 1] == -1)
		{
			ph->fk[ph->id - 1] = 0;
			pthread_mutex_unlock(&ph->mutex[ph->id - 1]);
			gettimeofday(&take, NULL);
			ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
			if ((ph->die - ph->life) < 0)
				ft_die(ph);
			printf("%ld %d has taken a R1.fork\n", (ph->die - ph->life), ph->id);
			/* printf("__________________________%d\n", ph->fk[ph->num - 1]); */
			pthread_mutex_lock(&ph->mutex[ph->num - 1]);
			if (ph->fk[ph->num - 1] == -1) 
			{
				/* printf("id->>%d_YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY\n", ph->id); */
				ph->fk[ph->num - 1] = 0;
				pthread_mutex_unlock(&ph->mutex[ph->num - 1]);
				gettimeofday(&take, NULL);
				ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
				if ((ph->die - ph->life) < 0)
					ft_die(ph);
				gettimeofday(&take, NULL);
				ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
				printf("%ld %d has taken a L1A.fork\n", (ph->die - ph->life), ph->id);
				ft_eat(ph/*, tab*/);
			}
			else
			{
				pthread_mutex_unlock(&ph->mutex[ph->num - 1]);
				/* printf("Id ->>%d_OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n", ph->id); */
				gettimeofday(&take, NULL);
				ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
				usleep(take.tv_usec / 1000);
				if ((ph->die - ph->life) < 0)
						ft_die(ph);
				pthread_mutex_lock(&ph->mutex[ph->num - 1]);
				if (ph->fk[ph->num - 1] == -1)
				{
					ph->fk[ph->num - 1] = 0;
					pthread_mutex_unlock(&ph->mutex[ph->num - 1]);
					/* printf("id->>%d_XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n", ph->id); */
					gettimeofday(&take, NULL);
					ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
					printf("%ld %d has taken a L1B.fork\n", (ph->die - ph->life), ph->id);
					ft_eat(ph);
				}
				else
				{
					ph->fk[ph->id - 1] = -1;
					pthread_mutex_unlock(&ph->mutex[ph->num - 1]);
					pthread_mutex_unlock(&ph->mutex[ph->id - 1]); 
					usleep(take.tv_usec / 1000);
					/* if ((ph->die - ph->life) > ph->eat * 500) */
					/* printf("id->>%d_FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n", ph->id); */
					ft_fork(ph/*, tab*/);
				}
			}
			/* if ((ph->die - ph->life) < 1) */
			/* 	ft_die(ph); */
			/* else */
		}


}

void	ft_fk2(t_ph *ph)
{
	struct timeval	take2;

	pthread_mutex_lock(&ph->mutex[ph->id - 1]);
	if (ph->fk[ph->id - 1] == -1)
		{
			ph->fk[ph->id - 1] = 0;
			pthread_mutex_unlock(&ph->mutex[ph->id - 1]);
			gettimeofday(&take2, NULL);
			ph->life = (take2.tv_sec * 1000) + (take2.tv_usec / 1000);
			printf("%ld %d has taken a R2.fork\n", (ph->die - ph->life), ph->id);
			/* printf("__________________________%d\n", ph->fk[ph->id - 2]); */
			pthread_mutex_lock(&ph->mutex[ph->id - 2]);
			if (ph->fk[ph->id - 2] == -1) 
			{
				/* printf("id->>%d_YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY\n", ph->id); */
				ph->fk[ph->id - 2] = 0;
				pthread_mutex_unlock(&ph->mutex[ph->id - 2]);
				gettimeofday(&take2, NULL);
				ph->life = (take2.tv_sec * 1000) + (take2.tv_usec / 1000);
				if ((ph->die - ph->life) < 0)
					ft_die(ph);
				printf("%ld %d has taken a L2A.fork\n", (ph->die - ph->life), ph->id);
				/* gettimeofday(&take, NULL); */
				/* ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000); */
				ft_eat(ph/*, tab*/);
			}
			else
			{
				pthread_mutex_unlock(&ph->mutex[ph->id - 2]);
				/* printf("id->>%d_OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n", ph->id); */
				gettimeofday(&take2, NULL);
				ph->life = (take2.tv_sec * 1000) + (take2.tv_usec / 1000);
				usleep(take2.tv_usec / 1000);
				if ((ph->die - ph->life) < 0)
					ft_die(ph);
				pthread_mutex_lock(&ph->mutex[ph->id - 2]);
				if (ph->fk[ph->id - 2] == -1)
				{
					/* printf("id->>%d_XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n", ph->id); */
					ph->fk[ph->id - 2] = 0;
					pthread_mutex_unlock(&ph->mutex[ph->id - 2]);
					gettimeofday(&take2, NULL);
					ph->life = (take2.tv_sec * 1000) + (take2.tv_usec / 1000);
					printf("%ld %d has taken a L2B.fork\n", (ph->die - ph->life), ph->id);
					ft_eat(ph);
				}
				else
				{
					pthread_mutex_unlock(&ph->mutex[ph->id - 2]);
					/* printf("id->>%d_FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n", ph->id); */
					ph->fk[ph->id - 1] = -1;
					pthread_mutex_unlock(&ph->mutex[ph->id - 1]); 
					usleep(take2.tv_usec / 1000);
					/* if ((ph->die - ph->life) > ph->eat * 500) */
					ft_fork(ph/*, tab*/);
				}
				/* ph->fk[ph->id - 1] = 0; */
				/* pthread_mutex_unlock(ph->mutex); */
				/* if ((ph->id % 2) != 0) */
				/* if ((ph->die - ph->life) > ph->eat * 500) */
				/* usleep(ph->eat * 250); */
				/* ft_fork(ph, tab); */
			}

	}
}


void	ft_fork(t_ph *ph/*, t_tab *tab*/)
{
	if (ph->id == 1)
		ft_fk1(ph);
	else
		ft_fk2(ph);
}


void	*ft_routine(void *tid)
{
	t_ph			ph;
	/* t_tab			tab; */
	struct timeval	live;
	long			pairtime;

	ph = *(t_ph *)tid;
	pthread_mutex_unlock(&ph.mutex[0]);
	/* len = -1; */
	/* while (++len < ph.num) */
	/* { */
	/*	printf("%d......%d................................\n", ph.num, ph.fk[len]);*/
	/* } */
	gettimeofday(&live, NULL);
	ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
	ph.die = (live.tv_sec * 1000) + (live.tv_usec / 1000) + ph.blood;
	while (/*ph.life < ph.die && */ph.kill == 0)
	{
		gettimeofday(&live, NULL);
		ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
		if ((ph.id % 2) != 0 && ph.wait == 0)
		{
			if (ph.num % 2 != 0 && ph.id == ph.num + 1)
					usleep(ph.eat/2);
			gettimeofday(&live, NULL);
			ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
			pairtime = (live.tv_sec * 1000) + (live.tv_usec / 1000) + (ph.eat/2);
			while (ph.life < pairtime)
			{
				gettimeofday(&live, NULL);
				ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
			}
			/* usleep(ph.eat * 999); */
			ph.wait = 1;
		}
			/* if ((ph.die - ph.life) < 0) */
		/* 	ft_die(&ph); */
		/* ph.eaten = 0; */
		ft_fork(&ph/*, &tab*/);
		/* //printf("%ld < %ld Philo %d\n", ph.life, ph.die, ph.id); */
	}
	free(ph.fk);
	return (0);
}

void	ft_create(t_ph *ph)
{
	int				i;
	pthread_t		*thread;
	/* struct timeval	time; */

	pthread_mutex_init(ph->mutex, NULL);
	/* philo.id = 0; */
	thread = malloc(ph->num * sizeof(pthread_t));
	i = -1;
	while (++i < ph->num)
	{
		pthread_mutex_lock(&ph->mutex[0]);
		ph->id = i + 1;
		/* gettimeofday(&time, NULL); */
		/* ph->die = (time.tv_sec * 1000) + (time.tv_usec / 1000) + ph->blood; */
		pthread_create(&thread[i], NULL, ft_routine, ph);
	}
	i = -1;
	while (++i < ph->num)
		pthread_join(thread[i], NULL);
	pthread_mutex_destroy(ph->mutex);
	free(ph->mutex);
	free(thread);
}

void	ft_init(int argc, char **argv)
{
	t_ph	ph;
	/* int i; */
	ph.num = ft_atoi(argv[1]);
	ph.mutex = (pthread_mutex_t *)malloc((ph.num) * sizeof(pthread_mutex_t));
	ph.fk = malloc((ph.num) * sizeof(int));
	memset(ph.fk, -1, ((ph.num ) * 4));
	ph.life = ft_atoi(argv[2]);
	ph.blood = ph.life;
	ph.eat = ft_atoi(argv[3]);
	ph.sleep = ft_atoi(argv[4]);
	ph.kill = 0;
	ph.wait = 0;
	ph.eaten = 0;
	/* i = 0; */
	/* while(i < philo.num) */
	/* { */
	/* 	//printf("fork %d\n", philo.fork[i]); */
	/* 	i++; */
	/* } */
	if (argc < 5 || ph.num < 1 || ph.life < 1 || ph.eat < 1 || ph.sleep < 1)
		return ;
	if (!ph.num || !ph.life || !ph.eat || !ph.sleep)
		return ;
	ft_create(&ph);
}

int	main(int argc, char **argv )
{
	if (argc >= 5 && argc <= 6)
		ft_init(argc, argv);
	else
		return (0);
}
