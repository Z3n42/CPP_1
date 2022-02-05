/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_b.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:50:41 by ingonzal          #+#    #+#             */
/*   Updated: 2022/02/04 20:03:09 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_B_H
# define FT_PHILO_B_H

typedef struct s_ph{
	int				id;
	int				num;
	long			die;
	long			life;
	long			born;
	int				blood;
	int				eat;
	int				sleep;
	int				kill;
	int				wait;
	int				print;
	int				*stat;
	int				times;
	int				full;
	int				max;
	sem_t			*sem;
	sem_t			*semw;
	sem_t			*semd;
}	t_ph;

void	ft_maxtimes(t_ph *ph);
int		ft_atoi(const char *str);
void	ft_die(t_ph *ph);
void	ft_sleep(t_ph *ph);
void	ft_eat(t_ph *ph);
void	ft_eatime(t_ph *ph);
void	ft_fk1(t_ph *ph);
void	*ft_routine(t_ph *ph);
void	ft_create(t_ph *ph);
void	ft_init(int argc, char **argv);

#endif
