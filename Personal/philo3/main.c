/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:07 by ingonzal          #+#    #+#             */
/*   Updated: 2021/11/13 14:29:30 by ingonzal         ###   ########.fr       */
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

/* typedef struct s_ph{ */
/* 	int				id; */
/* 	int				num; */
/* 	int				date; */
/* 	long			die; */
/* 	long			life; */
/* 	int				blood; */
/* 	int				eat; */
/* 	int				sleep; */
/* 	int				times; */
/* 	int				kill; */
/* 	int				wait; */
/* 	long			eaten; */
/* 	pthread_mutex_t	*mutex; */
/* }	t_ph; */

/* typedef struct s_tab{ */
/* 	int		*fk; */
/* }	t_tab; */

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

void	ft_sleep(t_ph *ph, t_tab *tab)
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
			/* if ((ph->die - ph->life) < 0) */
			/* 	ft_die(ph); */
		}
		/* usleep(ph->sleep * 999); */
		/* printf("%dzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\n", ph->sleep); */
		gettimeofday(&sleep, NULL);
		ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		printf("%ld %d is thinking\n", (ph->die - ph->life), ph->id);
	}
	gettimeofday(&sleep, NULL);
	ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	ft_fork(ph, tab);
}

void	ft_eat(t_ph *ph, t_tab *tab)
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
		tab->fk[ph->id - 1] = -1;
		tab->fk[ph->num - 1] = -1;
		/* pthread_mutex_unlock(ph->mutex); */
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		ft_sleep(ph, tab);
	}
	else
	{
		tab->fk[ph->id - 1] = -1;
		tab->fk[ph->id - 2] = -1;
		/* pthread_mutex_unlock(ph->mutex); */
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		ft_sleep(ph, tab);
	}
}

void	ft_fork(t_ph *ph, t_tab *tab)
{
	struct timeval	take;

	/* while (ph->life < ph->die) */
	/* { */
		/* ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000); */
		pthread_mutex_lock(&ph->mutex[ph->id - 1]);
		if (ph->id == 1 &&/* tab->fk[ph->num] == 0 && */tab->fk[ph->id - 1] == -1)
		{
			gettimeofday(&take, NULL);
			ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
			if ((ph->die - ph->life) < 0)
				ft_die(ph);
			printf("%ld %d has taken a R1.fork\n", (ph->die - ph->life), ph->id);
			tab->fk[ph->id - 1] = 0;
			pthread_mutex_unlock(&ph->mutex[ph->id - 1]);
			pthread_mutex_lock(&ph->mutex[ph->num - 1]);
			if (tab->fk[ph->num - 1] == -1) 
			{
				gettimeofday(&take, NULL);
				ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
				if ((ph->die - ph->life) < 0)
					ft_die(ph);
				tab->fk[ph->num - 1] = 0;
				gettimeofday(&take, NULL);
				ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
				printf("%ld %d has taken a L1A.fork\n", (ph->die - ph->life), ph->id);
				pthread_mutex_unlock(&ph->mutex[ph->num - 1]);
				ft_eat(ph, tab);
			}
			else
			{
				printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
				gettimeofday(&take, NULL);
				ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
				if ((ph->die - ph->life) < 0)
						ft_die(ph);
				/* usleep(take.tv_usec / 1000); */
				if (tab->fk[ph->num - 1] == -1)
				{
					tab->fk[ph->num - 1] = 0;
					gettimeofday(&take, NULL);
					ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
					printf("%ld %d has taken a L1B.fork\n", (ph->die - ph->life), ph->id);
					pthread_mutex_unlock(&ph->mutex[ph->num - 1]);
					ft_eat(ph, tab);
				}
				else
				{
					/* usleep(take.tv_usec * 250); */
					tab->fk[ph->id - 1] = -1;
					pthread_mutex_unlock(&ph->mutex[ph->id - 1]); 
					/* if ((ph->die - ph->life) > ph->eat * 500) */
					ft_fork(ph, tab);
				}
			}
			/* if ((ph->die - ph->life) < 1) */
			/* 	ft_die(ph); */
			/* else */
		}
		else if (tab->fk[ph->id - 1] == -1/* && tab->fk[ph->id - 2] == 0*/)
		{
			/* pthread_mutex_lock(&ph->mutex[ph->id - 1]); */
			gettimeofday(&take, NULL);
			ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
			printf("%ld %d has taken a R2.fork\n", (ph->die - ph->life), ph->id);
			tab->fk[ph->id - 1] = 0;
			pthread_mutex_unlock(&ph->mutex[ph->id - 1]);
			pthread_mutex_lock(&ph->mutex[ph->id - 2]);
			if (tab->fk[ph->id - 2] == -1) 
			{
				tab->fk[ph->id - 2] = 0;
				pthread_mutex_unlock(&ph->mutex[ph->id - 2]);
				gettimeofday(&take, NULL);
				ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
				if ((ph->die - ph->life) < 0)
					ft_die(ph);
				printf("%ld %d has taken a L2A.fork\n", (ph->die - ph->life), ph->id);
				/* gettimeofday(&take, NULL); */
				/* ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000); */
				ft_eat(ph, tab);
			}
			else
			{
				printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
				gettimeofday(&take, NULL);
				ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
				if ((ph->die - ph->life) < 0)
					ft_die(ph);
				/* usleep(take.tv_usec / 1000); */
				if (tab->fk[ph->id - 2] == -1)
				{
					tab->fk[ph->id - 2] = 0;
					pthread_mutex_unlock(&ph->mutex[ph->id - 2]);
					gettimeofday(&take, NULL);
					ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
					printf("%ld %d has taken a L2B.fork\n", (ph->die - ph->life), ph->id);
					ft_eat(ph, tab);
				}
				else
				{
					/* usleep(take.tv_usec * 250); */
					tab->fk[ph->id - 1] = -1;
					pthread_mutex_unlock(&ph->mutex[ph->id - 1]); 
					/* if ((ph->die - ph->life) > ph->eat * 500) */
					ft_fork(ph, tab);
				}
				/* tab->fk[ph->id - 1] = 0; */
				/* pthread_mutex_unlock(ph->mutex); */
				/* if ((ph->id % 2) != 0) */
				/* if ((ph->die - ph->life) > ph->eat * 500) */
				/* usleep(ph->eat * 250); */
				/* ft_fork(ph, tab); */
			}
			/* if ((ph->die - ph->life) < 1) */
			/* 	ft_die(ph); */
			/* else */
			/* ft_eat(ph, tab); */
		}
		/* else */
		/* 	ft_fork(ph, tab); */
	/* } */
}

void	*ft_routine(void *tid)
{
	t_ph			ph;
	t_tab			tab;
	struct timeval	live;
	long			pairtime;

	ph = *(t_ph *)tid;
	pthread_mutex_unlock(&ph.mutex[ph.id - 1]);
	tab.fk = malloc((ph.num - 1) * sizeof(int));
	memset(tab.fk, -1, (ph.num * 4));
	/* len = -1; */
	/* while (++len < ph.num) */
	/* { */
	/*	printf("%d......%d................................\n", ph.num, tab.fk[len]);*/
	/* } */
	gettimeofday(&live, NULL);
	ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
	while (ph.life < ph.die && ph.kill == 0)
	{
		gettimeofday(&live, NULL);
		ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
		if ((ph.id % 2) != 0 && ph.wait == 0)
		{
			
			gettimeofday(&live, NULL);
			ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
			pairtime = (live.tv_sec * 1000) + (live.tv_usec / 1000) + ph.eat;
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
		ft_fork(&ph, &tab);
		/* //printf("%ld < %ld Philo %d\n", ph.life, ph.die, ph.id); */
	}
	free(tab.fk);
	return (0);
}

void	ft_create(t_ph *ph)
{
	int				i;
	pthread_t		*thread;
	struct timeval	time;

	pthread_mutex_init(ph->mutex, NULL);
	/* philo.id = 0; */
	thread = malloc(ph->num * sizeof(pthread_t));
	i = -1;
	while (++i < ph->num)
	{
		pthread_mutex_lock(&ph->mutex[i]);
		ph->id = i + 1;
		gettimeofday(&time, NULL);
		ph->die = (time.tv_sec * 1000) + (time.tv_usec / 1000) + ph->blood;
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
	ph.mutex = (pthread_mutex_t *)malloc((ph.num - 1) * sizeof(pthread_mutex_t));
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
