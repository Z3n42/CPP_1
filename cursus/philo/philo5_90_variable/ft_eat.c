/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:07 by ingonzal          #+#    #+#             */
/*   Updated: 2022/02/01 17:55:59 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_philo.h"

void	ft_eatime(t_ph *ph)
{
	long			eatime;
	struct timeval	eatt;

	eatime = 0;
	gettimeofday(&eatt, NULL);
	ph->life = (eatt.tv_sec * 1000) + (eatt.tv_usec / 1000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	eatime = (eatt.tv_sec * 1000) + (eatt.tv_usec / 1000) + ph->eat;
	while (ph->life < eatime)
	{
		gettimeofday(&eatt, NULL);
		ph->life = (eatt.tv_sec * 1000) + (eatt.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		usleep(175);
	}
}

/* void	ft_freeforks(t_ph *ph) */
/* { */
	/* if (ph->id == 1) */
	/* { */
		/* pthread_mutex_unlock(&ph->mutex[ph->right]); */
		/* printf("Philo %d free %d\n", ph->id, ph->right); */
		/* pthread_mutex_unlock(&ph->mutex[ph->left]); */
		/* printf("Philo %d free %d\n", ph->id, ph->left); */
		/* if ((ph->die - ph->life) < 0) */
		/* 	ft_die(ph); */
		/* ft_sleep(ph); */
	/* } */
	/* else */
	/* { */
		/* pthread_mutex_unlock(&ph->mutex[ph->]); */
		/* printf("Philo %d free %d\n", ph->id, ph->id - 1); */
		/* pthread_mutex_unlock(&ph->mutex[ph->left]); */
		/* printf("Philo %d free %d\n", ph->id, ph->left); */
		/* if ((ph->die - ph->life) < 0) */
			/* ft_die(ph); */
		/* ft_sleep(ph); */
	/* } */
/* } */

void	ft_eat(t_ph *ph)
{
	struct timeval	eat;

	if (ph->kill == 0 && ph->stat[0] == 0)
	{
		ft_eatime(ph);
		gettimeofday(&eat, NULL);
		ph->life = (eat.tv_sec * 1000) + (eat.tv_usec / 1000);
		if ((ph->die - ph->life) < 0)
			ft_die(ph);
		if (ph->kill == 0 && ph->stat[0] == 0)
		{
			printf("%ld %d is eating\n", (ph->life - ph->born), ph->id);
			if (ph->max != -1)
				ph->times += 1;
		}
		ph->die = (eat.tv_sec * 1000) + (eat.tv_usec / 1000) + ph->blood;
		ph->print = 0;
	}
	/* pthread_mutex_lock(&ph->mutex[ph->right]); */
	ph->fk[ph->right] = -1;
	pthread_mutex_unlock(&ph->mutex[ph->right]);
	/* printf("Philo %d free %d\n", ph->id, ph->right); */
	/* pthread_mutex_lock(&ph->mutex[ph->left]); */
	ph->fk[ph->left] = -1;
	pthread_mutex_unlock(&ph->mutex[ph->left]);
	/* printf("Philo %d free %d\n", ph->id, ph->left); */
	gettimeofday(&eat, NULL);
	ph->life = (eat.tv_sec * 1000) + (eat.tv_usec / 1000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	ft_sleep(ph);
	/* ft_freeforks(ph); */
}
