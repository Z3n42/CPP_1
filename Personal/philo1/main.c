/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:07 by ingonzal          #+#    #+#             */
/*   Updated: 2021/11/09 13:12:25 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

typedef struct s_ph{
	int				id;
	int				num;
	int				date;
	long			die;
	long			life;
	int				blood;
	int				eat;
	int				sleep;
	int				times;
	int				kill;
	int				wait;
	int				eaten;
	pthread_mutex_t	*mutex;
}	t_ph;

typedef struct s_tab{
	int		*fk;
}	t_tab;

void ft_die(t_ph *ph)
{
	struct timeval	die;

	gettimeofday(&die, NULL);
	ph->life = (die.tv_sec * 1000) + (die.tv_usec / 1000);
	if (ph->kill == 0)
	{
		printf("%ld %d died+++++++++++++++++++++++\n", (ph->die - ph->life), ph->id);
		exit(0);
	}
	ph->kill = 1;

}

void	ft_sleep(t_ph *ph)
{
	struct timeval	sleep;

	gettimeofday(&sleep, NULL);
	ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
	if (ph->kill == 0)
	{
		ph->die = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000) + ph->blood;
		printf("%ld %d is sleeping\n", (ph->die - ph->life), ph->id);
		usleep(ph->sleep * 1000);
		printf("%ld %d is thinking\n", (ph->die - ph->life), ph->id);
	}
	ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
	if ((ph->die - ph->life) < 1)
		ft_die(ph);
}

void	ft_eat(t_ph *ph, t_tab *tab)
{
	struct timeval	eat;
	/* long			time; */
	/* long			eatime; */

	/* time = 0; */
	/* eatime = 0; */
	gettimeofday(&eat, NULL);
	ph->life = (eat.tv_sec * 1000) + (eat.tv_usec / 1000);
	if (ph->kill == 0)
	{
		/* ph->die = (eat.tv_sec * 1000) + (eat.tv_usec / 1000) + ph->blood; */
		printf("%ld %d is eating\n", (ph->die - ph->life), ph->id);
	}
	/* time = (eat.tv_sec * 1000) + (eat.tv_usec / 1000); */
	usleep(ph->eat * 1000);
	/* while (time < ph->eat) */
		/* time = (eat.tv_sec * 1000) + (eat.tv_usec / 1000); */
	if (ph->id == 1)
	{
		tab->fk[ph->id - 1] = 0;
		tab->fk[ph->num] = 0;
		if ((ph->die - ph->life) < 1)
			ft_die(ph);
		/* pthread_mutex_unlock(ph->mutex); */
		ft_sleep(ph);
	}
	else
	{
		tab->fk[ph->id - 1] = 0;
		tab->fk[ph->id - 2] = 0;
		if ((ph->die - ph->life) < 1)
			ft_die(ph);
		/* pthread_mutex_unlock(ph->mutex); */
		ft_sleep(ph);
	}
}

void	ft_fork(t_ph *ph, t_tab *tab)
{
	struct timeval	take;

	gettimeofday(&take, NULL);
	pthread_mutex_lock(ph->mutex);
	/* while (ph->life < ph->die) */
	/* { */
		/* ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000); */
		if (ph->id == 1 &&/* tab->fk[ph->num] == 0 && */tab->fk[ph->id - 1] == 0)
		{
			ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
			printf("%ld %d has taken a R.fork\n", (ph->die - ph->life), ph->id);
			tab->fk[ph->id - 1] = 1;
			pthread_mutex_unlock(ph->mutex);
			pthread_mutex_lock(ph->mutex);
			if (tab->fk[ph->num] == 0) 
			{
				if ((ph->die - ph->life) < 1)
					ft_die(ph);
				tab->fk[ph->num] = 1;
				pthread_mutex_unlock(ph->mutex);
				printf("%ld %d has taken a L.fork\n", (ph->die - ph->life), ph->id);
				ft_eat(ph, tab);
			}
			else
			{
				if ((ph->die - ph->life) < 1)
					ft_die(ph);
				tab->fk[ph->id - 1] = 0;
				pthread_mutex_unlock(ph->mutex); 
				usleep(ph->eat * 500);
				ft_fork(ph, tab);
			}
			/* if ((ph->die - ph->life) < 1) */
			/* 	ft_die(ph); */
			/* else */
		}
		else if (tab->fk[ph->id - 1] == 0/* && tab->fk[ph->id - 2] == 0*/)
		{
			ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
			printf("%ld %d has taken a R.fork\n", (ph->die - ph->life), ph->id);
			tab->fk[ph->id - 1] = 1;
			pthread_mutex_unlock(ph->mutex);
			pthread_mutex_lock(ph->mutex);
			if (tab->fk[ph->id - 2] == 0) 
			{
				if ((ph->die - ph->life) < 1)
					ft_die(ph);
				tab->fk[ph->id - 2] = 1;
				pthread_mutex_unlock(ph->mutex);
				printf("%ld %d has taken a L.fork\n", (ph->die - ph->life), ph->id);
				ft_eat(ph, tab);
			}
			else
			{
				if ((ph->die - ph->life) < 1)
					ft_die(ph);
				tab->fk[ph->id - 1] = 0;
				pthread_mutex_unlock(ph->mutex);
				/* if ((ph->id % 2) != 0) */
					usleep(ph->eat * 500);
				ft_fork(ph, tab);
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

	ph = *(t_ph *)tid;
	pthread_mutex_unlock(ph.mutex);
	tab.fk = malloc(ph.num * sizeof(int));
	gettimeofday(&live, NULL);
	while (ph.life < ph.die && ph.kill == 0)
	{
		gettimeofday(&live, NULL);
		ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
		if ((ph.id % 2) == 0 && ph.wait == 0)
		{
			usleep(ph.eat * 1000);
			ph.wait = 1;
		}
		ft_fork(&ph, &tab);
		/* printf("%ld < %ld Philo %d\n", ph.life, ph.die, ph.id); */
	}
	if ((ph.die - ph.life) < 1)
		ft_die(&ph);
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
	gettimeofday(&time, NULL);
	i = -1;
	while (++i < ph->num)
	{
		pthread_mutex_lock(ph->mutex);
		ph->id = i + 1;
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
	ph.mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	ph.num = ft_atoi(argv[1]);
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
	/* 	printf("fork %d\n", philo.fork[i]); */
	/* 	i++; */
	/* } */
	if (argc < 5 || ph.num < 2 || ph.life < 1 || ph.eat < 1 || ph.sleep < 1)
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
