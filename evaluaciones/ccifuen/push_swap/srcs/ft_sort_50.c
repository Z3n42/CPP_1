/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_50.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:22:44 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/19 20:22:44 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_push_swap.h"

void	ft_get_min_a(t_p *p)
{
	int	i;

	i = 0;
	p->min_a = ft_atoi(p->a[0]);
	while (i < p->a_size)
	{
		if (ft_atoi(p->a[i]) < p->min_a)
			p->min_a = ft_atoi(p->a[i]);
		i++;
	}
}

int	ft_search_next_min(t_p *p)
{
	int	i;

	i = 0;
	ft_get_min_a(p);
	while (i < p->a_size)
	{
		if (ft_atoi(p->a[i]) == p->min_a)
			break ;
		i++;
	}
	if (i >= p->a_size / 2)
		return (i);
	else
		return (i * -1);
}

int	ft_check_min_a(t_p *p)
{
	ft_get_min_a(p);
	if (ft_atoi(p->a[p->a_size - 1]) == p->min_a)
		return (1);
	return (0);
}

void	ft_sort_50(t_p *p)
{
	while (p->a_size > 2)
	{
		if (ft_check_sort(p))
			break ;
		else if (p->a_size < 4)
		{
			ft_sort_3(p);
			break ;
		}
		while (!ft_check_min_a(p))
		{
			if (ft_search_next_min(p) == p->a_size - 2)
				ft_swap_a(p);
			else if (ft_search_next_min(p) > 0
				&& ft_search_next_min(p) != p->a_size - 1)
				ft_rotate_a(p);
			else if (ft_search_next_min(p) <= 0)
				ft_rev_rotate_a(p);
		}
		if (ft_check_sort(p))
			break ;
		ft_push_b(p);
	}
}
