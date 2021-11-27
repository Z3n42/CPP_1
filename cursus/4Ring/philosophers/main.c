/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:07 by ingonzal          #+#    #+#             */
/*   Updated: 2021/11/27 14:15:37 by ingonzal         ###   ########.fr       */
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

	/* pthread_mutex_lock(&ph->mutex[ph->id - 1]); */ 
	/* memset(ph->fk, 0, (ph->num * 4)); */
	/* memset(ph->mutex, 0, (ph->num * 4)); */
	if (ph->kill == 0)
	{
		gettimeofday(&die, NULL);
		ph->life = (die.tv_sec * 1000) + (die.tv_usec / 1000);
		printf("%ld %d died+++++++++++++++++++++++\n", (ph->die - ph->life), ph->id);
		ph->kill = 1;
		printf("%d......%d\n", ph->kill, ph->id);
		/* pthread_mutex_unlock(&ph->mutex[ph->id - 1]); */ 
	}
	/* pthread_mutex_unlock(&ph->mutex[ph->id - 1]); */ 
	/* ft_fork(ph); */
}

void ft_sleeptime(t_ph *ph)
{
	long	sleeptime;
	struct timeval	sleept;

	
	sleeptime = 0;
	gettimeofday(&sleept, NULL);
	ph->life = (sleept.tv_sec * 1000) + (sleept.tv_usec / 1000);
	sleeptime = (sleept.tv_sec * 1000) + (sleept.tv_usec / 1000) + ph->sleep;
	while (ph->life < sleeptime)
	{
		gettimeofday(&sleept, NULL);
		ph->life = (sleept.tv_sec * 1000) + (sleept.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
	}
}

void	ft_sleep(t_ph *ph)
{
	struct timeval	sleep;
	
	if (ph->kill == 0)
	{
		gettimeofday(&sleep, NULL);
		ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		printf("%ld %d is sleeping\n", (ph->die - ph->life), ph->id);
		if (ph->num % 2 != 0)
			usleep(500);
		ft_sleeptime(ph);
		gettimeofday(&sleep, NULL);
		ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		printf("%ld %d is thinking\n", (ph->die - ph->life), ph->id);
		if (ph->num % 2 != 0)
			usleep(500);
	}
	gettimeofday(&sleep, NULL);
	ph->life = (sleep.tv_sec * 1000) + (sleep.tv_usec / 1000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
}

void	ft_eatime(t_ph *ph)
{
	long		eatime;
	struct timeval	eatt;

	eatime = 0;
	gettimeofday(&eatt, NULL);
	ph->life = (eatt.tv_sec * 1000) + (eatt.tv_usec / 1000);
	eatime = (eatt.tv_sec * 1000) + (eatt.tv_usec / 1000) + ph->eat;
	while (ph->life < eatime)
	{
		gettimeofday(&eatt, NULL);
		ph->life = (eatt.tv_sec * 1000) + (eatt.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
	}
}

void	ft_freeforks(t_ph *ph)
{
	if (ph->id == 1)
	{
		pthread_mutex_lock(&ph->mutex[ph->id - 1]);
		ph->fk[ph->id - 1] = -1;
		pthread_mutex_unlock(&ph->mutex[ph->id - 1]);
		pthread_mutex_lock(&ph->mutex[ph->num - 1]);
		ph->fk[ph->num - 1] = -1;
		pthread_mutex_unlock(&ph->mutex[ph->num - 1]);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		ft_sleep(ph);
	}
	else
	{
		pthread_mutex_lock(&ph->mutex[ph->id - 1]);
		ph->fk[ph->id - 1] = -1;
		pthread_mutex_unlock(&ph->mutex[ph->id - 1]);
		pthread_mutex_lock(&ph->mutex[ph->id - 2]);
		ph->fk[ph->id - 2] = -1;
		pthread_mutex_unlock(&ph->mutex[ph->id - 2]);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		ft_sleep(ph);
	}
}

void	ft_eat(t_ph *ph)
{
	struct timeval	eat;

	if (ph->kill == 0)
	{
		ft_eatime(ph);
		gettimeofday(&eat, NULL);
		ph->life = (eat.tv_sec * 1000) + (eat.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		printf("%ld %d is eating\n", (ph->die - ph->life), ph->id);
		ph->die = (eat.tv_sec * 1000) + (eat.tv_usec / 1000) + ph->blood;
		ph->print = 0;
	}
	ft_freeforks(ph);
}

void	ft_fkl1a(t_ph *ph, struct timeval take)
{
	pthread_mutex_lock(&ph->mutex[ph->num - 1]);
	ph->fk[ph->num - 1] = 0;
	pthread_mutex_unlock(&ph->mutex[ph->num - 1]);
	gettimeofday(&take, NULL);
	ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	gettimeofday(&take, NULL);
	ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
	printf("%ld %d has taken a L1A.fork\n", (ph->die - ph->life), ph->id);
	if (ph->kill == 0)
		ft_eat(ph);
}

void	ft_fkl1b(t_ph *ph, struct timeval take)
{
	gettimeofday(&take, NULL);
	ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
	usleep(400 + take.tv_usec / 10000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	if (ph->fk[ph->num - 1] == -1)
	{
		pthread_mutex_lock(&ph->mutex[ph->num - 1]);
		ph->fk[ph->num - 1] = 0;
		pthread_mutex_unlock(&ph->mutex[ph->num - 1]);
		gettimeofday(&take, NULL);
		ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
		printf("%ld %d has taken a L1B.fork\n", (ph->die - ph->life), ph->id);
		ft_eat(ph);
	}
	else
	{
		ph->fk[ph->id - 1] = -1;
		pthread_mutex_unlock(&ph->mutex[ph->id - 1]); 
		if (ph->num % 2 != 0)
			usleep(140);
		if (ph->num == 1)
			usleep(1000);
		ft_fk1(ph);
	}
}

void	ft_fk1(t_ph *ph)
{
	struct timeval	take;

	if (ph->fk[ph->id - 1] == -1)
	{
		pthread_mutex_lock(&ph->mutex[ph->id - 1]);
		ph->fk[ph->id - 1] = 0;
		pthread_mutex_unlock(&ph->mutex[ph->id - 1]);
		gettimeofday(&take, NULL);
		ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		if (ph->print == 0)
			{
				printf("%ld %d has taken a R1.fork\n", (ph->die - ph->life), ph->id);
				ph->print = 1;
			}
		if (ph->fk[ph->num - 1] == -1) 
			ft_fkl1a(ph, take);
		else
			ft_fkl1b(ph, take);
	}
}

void	ft_fkl2a(t_ph *ph, struct timeval take2)
{	
	pthread_mutex_lock(&ph->mutex[ph->id - 2]);
	ph->fk[ph->id - 2] = 0;
	pthread_mutex_unlock(&ph->mutex[ph->id - 2]);
	gettimeofday(&take2, NULL);
	ph->life = (take2.tv_sec * 1000) + (take2.tv_usec / 1000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	printf("%ld %d has taken a L2A.fork\n", (ph->die - ph->life), ph->id);
	ft_eat(ph);
}

void	ft_fkl2b(t_ph *ph, struct timeval take2)
{
	gettimeofday(&take2, NULL);
	ph->life = (take2.tv_sec * 1000) + (take2.tv_usec / 1000);
	usleep(400 + take2.tv_usec / 10000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	if (ph->fk[ph->id - 2] == -1)
	{
		pthread_mutex_lock(&ph->mutex[ph->id - 2]);
		ph->fk[ph->id - 2] = 0;
		pthread_mutex_unlock(&ph->mutex[ph->id - 2]);
		gettimeofday(&take2, NULL);
		ph->life = (take2.tv_sec * 1000) + (take2.tv_usec / 1000);
		printf("%ld %d has taken a L2B.fork\n", (ph->die - ph->life), ph->id);
		ft_eat(ph);
	}
	else
	{
		ph->fk[ph->id - 1] = -1;
		pthread_mutex_unlock(&ph->mutex[ph->id - 1]); 
		if (ph->num % 2 != 0)
			usleep(140);
		ft_fk2(ph);
	}
}

void	ft_fk2(t_ph *ph)
{
	struct timeval	take2;

	if (ph->fk[ph->id - 1] == -1)
	{
		pthread_mutex_lock(&ph->mutex[ph->id - 1]);
		ph->fk[ph->id - 1] = 0;
		pthread_mutex_unlock(&ph->mutex[ph->id - 1]);
		gettimeofday(&take2, NULL);
		ph->life = (take2.tv_sec * 1000) + (take2.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
				ft_die(ph);
		if (ph->print == 0)
		{
			printf("%ld %d has taken a R2.fork\n", (ph->die - ph->life), ph->id);
			ph->print = 1;
		}
		if (ph->fk[ph->id - 2] == -1) 
			ft_fkl2a(ph, take2);
		else
			ft_fkl2b(ph, take2);
	}
}

void	ft_fork(t_ph *ph)
{
	/* if (ph->kill == 0) */
	/* { */
		if (ph->id == 1)
			ft_fk1(ph);
		else
			ft_fk2(ph);
	/* } */
}

void	ft_pairtime(t_ph *ph, struct timeval live)
{
	long			pairtime;

	gettimeofday(&live, NULL);
	ph->life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
	pairtime = (live.tv_sec * 1000) + (live.tv_usec / 1000) + (ph->eat/2);
	while (ph->life < pairtime)
	{
		gettimeofday(&live, NULL);
		ph->life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
	}
	ph->wait = 1;
}

void	*ft_routine(void *tid)
{
	t_ph			ph;
	struct timeval	live;

	ph = *(t_ph *)tid;
	pthread_mutex_unlock(&ph.mutex[0]);
	gettimeofday(&live, NULL);
	ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
	ph.die = (live.tv_sec * 1000) + (live.tv_usec / 1000) + ph.blood;
	while (ph.kill == 0)
	{
		gettimeofday(&live, NULL);
		ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
		if ((ph.id % 2) != 0 && ph.wait == 0)
			ft_pairtime(&ph, live);
		ft_fork(&ph);
		if (ph.kill == 1)
			break;
	}
	return (0);
}

void	ft_create(t_ph *ph)
{
	int				i;
	pthread_t		*thread;

	pthread_mutex_init(ph->mutex, NULL);
	thread = malloc(ph->num * sizeof(pthread_t));
	i = -1;
	while (++i < ph->num)
	{
		pthread_mutex_lock(&ph->mutex[0]);
		ph->id = i + 1;
		pthread_create(&thread[i], NULL, ft_routine, ph);
	}
	i = -1;
	while (++i < ph->num)
		pthread_join(thread[i], NULL);
	pthread_mutex_destroy(ph->mutex);
	free(ph->fk);
	free(ph->mutex);
	free(thread);
}

void	ft_init(int argc, char **argv)
{
	t_ph	ph;
	ph.num = ft_atoi(argv[1]);
	ph.mutex = (pthread_mutex_t *)malloc((ph.num) * sizeof(pthread_mutex_t));
	ph.fk = malloc((ph.num) * sizeof(int));
	memset(ph.fk, -1, (ph.num * 4));
	ph.life = ft_atoi(argv[2]);
	ph.blood = ph.life;
	ph.eat = ft_atoi(argv[3]);
	ph.sleep = ft_atoi(argv[4]);
	ph.kill = 0;
	ph.wait = 0;
	ph.print = 0;
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
