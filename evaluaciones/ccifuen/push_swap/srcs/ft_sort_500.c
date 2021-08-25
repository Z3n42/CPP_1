/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:33:54 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/20 12:16:36 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_push_swap.h"

void	ft_move_500(t_p *p, int i)
{
	while (!ft_check_up_11(p, i))
	{
		if (ft_search_next_11(p, i) == p->a_size - 2)
		{
			if (p->b[p->b_size - 1] < p->b[p->b_size - 2] && p->b_size > 1)
				ft_swap_s(p);
			else
				ft_swap_a(p);
		}
		if (ft_search_next_11(p, i) > 0
			&& ft_search_next_11(p, i) != p->a_size - 1)
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

void	ft_sort_500(t_p *p)
{
	int	i;

	ft_get_tracks_11(p);
	i = 0;
	while (i < 8)
	{
		if (ft_check_sort(p))
			break ;
		while (ft_check_next_11(p, i))
		{
			ft_move_500(p, i);
			ft_push_b(p);
		}
		i++;
	}
	ft_sort_100(p);
}
