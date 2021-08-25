/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:30:22 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/20 12:17:31 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_push_swap.h"

void	ft_get_max_b(t_p *p)
{
	int	i;

	i = 0;
	p->max_b = ft_atoi(p->b[0]);
	while (i < p->b_size)
	{
		if (ft_atoi(p->b[i]) > p->max_b)
			p->max_b = ft_atoi(p->b[i]);
		i++;
	}
}

int	ft_search_n_m_b(t_p *p)
{
	int	i;

	i = 0;
	ft_get_max_b(p);
	while (i < p->b_size)
	{
		if (ft_atoi(p->b[i]) == p->max_b)
			break ;
		i++;
	}
	if (i >= p->b_size / 2)
		return (i);
	else
		return (i * -1);
}

int	ft_check_max_b(t_p *p)
{
	ft_get_max_b(p);
	if (ft_atoi(p->b[p->b_size - 1]) == p->max_b)
		return (1);
	return (0);
}

void	ft_move_100(t_p *p, int i)
{
	while (!ft_check_up_5(p, i))
	{
		if (ft_search_next_5(p, i) == p->a_size - 2)
		{
			if (p->b[p->b_size - 1] < p->b[p->b_size - 2] && p->b_size > 1)
				ft_swap_s(p);
			else
				ft_swap_a(p);
		}
		if (ft_search_next_5(p, i) > 0
			&& ft_search_next_5(p, i) != p->a_size - 1)
		{
			if (ft_search_n_m_b(p) > 0 && ft_search_n_m_b(p) != p->b_size - 1)
				ft_rotate_r(p);
			else
				ft_rotate_a(p);
		}
		else
		{
			if (ft_search_n_m_b(p) <= 0)
				ft_rev_rotate_r(p);
			else
				ft_rev_rotate_a(p);
		}
	}
}

void	ft_sort_100(t_p *p)
{
	int	i;

	ft_get_tracks_5(p);
	i = 0;
	while (i < 4)
	{
		if (ft_check_sort(p))
			break ;
		while (ft_check_next_5(p, i))
		{
			ft_move_100(p, i);
			ft_push_b(p);
		}
		i++;
	}
	ft_sort_50(p);
}
