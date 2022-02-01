/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fk1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:07 by ingonzal          #+#    #+#             */
/*   Updated: 2022/02/01 17:11:33 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_philo.h"

void	ft_fkl1a(t_ph *ph, struct timeval take)
{
	pthread_mutex_lock(&ph->mutex[ph->left]);
	ph->fk[ph->left] = 0;
	gettimeofday(&take, NULL);
	ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	gettimeofday(&take, NULL);
	ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
	/* if (ph->stat[0] == 0) */
		printf("%ld %d has taken a L%d-fork\n", (ph->life - ph->born), ph->id, ph->left);
	ft_eat(ph);
}

void	ft_fkl1b(t_ph *ph, struct timeval take)
{
	usleep(50 + take.tv_usec / 10000);
	gettimeofday(&take, NULL);
	ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	pthread_mutex_lock(&ph->mutex[ph->left]);
	if (ph->fk[ph->left] == -1)
	{
		ph->fk[ph->left] = 0;
		pthread_mutex_unlock(&ph->mutex[ph->left]);
		gettimeofday(&take, NULL);
		ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
		if (ph->stat[0] == 0)
			printf("%ld %d has taken a **R3-fork\n", (ph->life - ph->born), ph->id);
		ft_eat(ph);
	}
	else
	{
		ph->fk[ph->right] = -1;
		pthread_mutex_unlock(&ph->mutex[ph->right]);
		pthread_mutex_unlock(&ph->mutex[ph->left]);
		/* if (ph->num % 2 != 0) */
		/* 	usleep(140); */
		/* if (ph->num == 1) */
		/* 	usleep(1000); */
		ft_fk1(ph);
	}
}

void	ft_fk1(t_ph *ph)
{
	struct timeval	take;

	pthread_mutex_lock(&ph->mutex[ph->right]);
	ph->fk[ph->right] = 0;
	gettimeofday(&take, NULL);
	ph->life = (take.tv_sec * 1000) + (take.tv_usec / 1000);
	if ((ph->die - ph->life) < 0)
		ft_die(ph);
	/* if (ph->print == 0 && ph->stat[0] == 0) */
	/* { */
		printf("%ld %d has taken a R%d-fork\n", (ph->life -  ph->born), ph->id, ph->right);
		ph->print = 1;
	/* } */
	if (ph->fk[ph->left] == -1)
		ft_fkl1a(ph, take);
	else
		ft_fkl1b(ph, take);
}
