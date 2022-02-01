/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:07 by ingonzal          #+#    #+#             */
/*   Updated: 2022/02/01 16:54:58 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_philo.h"

void	ft_fork(t_ph *ph)
{
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	if (ph->id == 1)
		ft_fk1(ph);
	else
		ft_fk2(ph);
}

void	ft_pairtime(t_ph *ph, struct timeval live)
{
	long			pairtime;

	gettimeofday(&live, NULL);
	ph->life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
	pairtime = (live.tv_sec * 1000) + (live.tv_usec / 1000) + (ph->eat / 2);
	while (ph->life < pairtime)
	{
		gettimeofday(&live, NULL);
		ph->life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		usleep(250);
	}
	ph->wait = 1;
}

void	ft_maxtimes(t_ph *ph)
{
	static int	max;

	if (ph->full == 0)
	{
		max += 1;
		ph->full = 1;
		/* printf("MAX . %d\n", max); */
		if (max == ph->num)
		{
			/* printf("**********************************************************\n"); */
			ph->stat[0] = 1;
			
		}
	}
}

void	ft_wait(t_ph *ph)
{
	static int door;

	door += 1;
	while(door != ph->num)
	{
		/* printf("Door %d --> Num %d\n", door, ph->num); */
		if (door != ph->num)
			usleep(50);
	}
}

void	*ft_routine(void *tid)
{
	t_ph			ph;
	struct timeval	live;

	ph = *(t_ph *)tid;
	ph.left = ph.id - 2;
	ph.right = ph.id - 1;
	if (ph.id == 1)
		ph.left = ph.num - 1;
	pthread_mutex_unlock(&ph.mutex[0]);
	ft_wait(&ph);
	/* if ((ph.id % 2) == 0 && ph.wait == 0) */
	/* 	usleep(50); */
	gettimeofday(&live, NULL);
	ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
	ph.die = (live.tv_sec * 1000) + (live.tv_usec / 1000) + ph.blood;
	ph.born = ph.life;
	/* printf("ID - %d Time - %ld\n", ph.id, ph.life); */
	while (ph.stat[0] == 0)
	{
		gettimeofday(&live, NULL);
		ph.life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
		if ((ph.die - ph.life) < 0)
			ft_die(&ph);
		if ((ph.id % 2) != 0 && ph.wait == 0)
		{
			ph.wait = 1;
			usleep(250);
			/* ft_pairtime(&ph, live); */
		}
		ft_fk1(&ph);
		/* printf("ID - %d * times - %d * max - %d * stat - %d\n", ph.id, ph.times, ph.max, ph.stat[0]); */
		/* printf("**********************************************************\n"); */
		if (ph.max != -1 && ph.times == ph.max)
			ft_maxtimes(&ph);
		if (ph.stat[0] == 1)
			break ;
	}
	return (0);
}
