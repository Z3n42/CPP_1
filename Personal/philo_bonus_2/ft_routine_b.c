/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:07 by ingonzal          #+#    #+#             */
/*   Updated: 2022/02/04 20:16:30 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <signal.h>
#include "ft_philo_b.h"

void	ft_maxtimes(t_ph *ph)
{
	static int	max;

	if (ph->full == 0)
	{
		max += 1;
		ph->full = 1;
		if (max == ph->num)
			exit(1);
	}
}

void	ft_wait(t_ph *ph)
{
	if (ph->id != ph->num)
		sem_wait(ph->semw);
	sem_post(ph->semw);
}

void *ft_routine(t_ph *ph)
{
	struct timeval	live;

	ft_wait(ph);
	gettimeofday(&live, NULL);
	ph->life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
	ph->die = (live.tv_sec * 1000) + (live.tv_usec / 1000) + ph->blood;
	ph->born = ph->life;
	/* printf("philo ID - %d Born  - %ld\n", ph->id, ph->born); */
	while (ph->stat[0] == 0)
	{
		if ((ph->id % 2) == 0 && ph->wait == 0)
		{
			ph->wait = 1;
			usleep(1500);
		}
		ft_fk1(ph);
		if (ph->stat[0] == 1)
			break ;
	}
	return (0);
}
