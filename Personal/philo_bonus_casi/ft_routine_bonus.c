/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_bonus.c        	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:08:07 by ingonzal          #+#    #+#             */
/*   Updated: 2022/02/05 13:34:46 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/time.h>
#include "ft_philo_bonus.h"

void	ft_maxtimes(t_ph *ph)
{
	sem_post(ph->sem);
	sem_post(ph->sem);
	exit(0);
}

void	ft_wait(t_ph *ph)
{
	if (ph->id != ph->num)
		sem_wait(ph->semw);
	sem_post(ph->semw);
}

void	*ft_routine(t_ph *ph)
{
	struct timeval	live;

	ft_wait(ph);
	gettimeofday(&live, NULL);
	ph->life = (live.tv_sec * 1000) + (live.tv_usec / 1000);
	ph->die = (live.tv_sec * 1000) + (live.tv_usec / 1000) + ph->blood;
	ph->born = ph->life;
	while (1)
	{
		if ((ph->id % 2) != 0 && ph->wait == 0)
		{
			ph->wait = 1;
			usleep(1500);
		}
		ft_fk1(ph);
	}
	return (0);
}
