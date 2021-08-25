/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:19:18 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/19 20:19:18 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_push_swap.h"

void	ft_get_max_a(t_p *p)
{
	int	i;

	i = 0;
	p->max_a = ft_atoi(p->a[0]);
	while (i < p->a_size)
	{
		if (ft_atoi(p->a[i]) > p->max_a)
			p->max_a = ft_atoi(p->a[i]);
		i++;
	}
}

void	ft_sort_2(t_p *p)
{
	if (p->a_size > 1)
		if (ft_atoi(p->a[0]) < ft_atoi(p->a[1]))
			ft_swap_a(p);
}

void	ft_sort_3(t_p *p)
{
	if (p->a_size < 3)
		ft_sort_2(p);
	else
	{
		ft_get_min_a(p);
		ft_get_max_a(p);
		if (ft_atoi(p->a[1]) == p->min_a && ft_atoi(p->a[0]) == p->max_a)
			ft_swap_a(p);
		if (ft_atoi(p->a[2]) == p->max_a && ft_atoi(p->a[0]) == p->min_a)
		{
			ft_swap_a(p);
			ft_rev_rotate_a(p);
		}
		if (ft_atoi(p->a[2]) == p->max_a && ft_atoi(p->a[1]) == p->min_a)
			ft_rotate_a(p);
		if (ft_atoi(p->a[2]) == p->min_a && ft_atoi(p->a[1]) == p->max_a)
		{
			ft_swap_a(p);
			ft_rotate_a(p);
		}
		if (ft_atoi(p->a[1]) == p->max_a && ft_atoi(p->a[0]) == p->min_a)
			ft_rev_rotate_a(p);
	}
}
