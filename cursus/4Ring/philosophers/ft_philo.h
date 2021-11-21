/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:50:41 by ingonzal          #+#    #+#             */
/*   Updated: 2021/11/20 14:21:53 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

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
	long			eaten;
	int				*fk;
	pthread_mutex_t	*mutex;
}	t_ph;

/* typedef struct s_tab{ */
/* 	int		*fk; */
/* }	t_tab; */

void ft_die(t_ph *ph);
void	ft_sleep(t_ph *ph/*, t_tab *tab*/);
void	ft_eat(t_ph *ph/*, t_tab *tab*/);
void	ft_fork(t_ph *ph/*, t_tab *tab*/);
void	*ft_routine(void *tid);
void	ft_create(t_ph *ph);
void	ft_init(int argc, char **argv);


# endif
