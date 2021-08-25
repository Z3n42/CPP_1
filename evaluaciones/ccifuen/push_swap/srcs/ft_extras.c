/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extras.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:21:33 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/20 11:22:56 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_push_swap.h"

void	ft_back_to_a(t_p *p)
{
	while (p->b_size > 0)
	{
		while (!ft_check_max_b(p))
		{
			if (ft_search_n_m_b(p) == p->b_size - 2)
				ft_swap_b(p);
			if (ft_search_n_m_b(p) > 0
				&& ft_search_n_m_b(p) != p->b_size - 1)
				ft_rotate_b(p);
			else if (ft_search_n_m_b(p) <= 0)
				ft_rev_rotate_b(p);
		}
		ft_push_a(p);
	}
}

void	ft_fill_sorted(t_p *p, int t, int a, int b)
{
	t = p->sorted[a];
	p->sorted[a] = p->sorted[b];
	p->sorted[b] = t;
}

void	ft_alloc_sorted(t_p *p)
{
	int	i;
	int	t;
	int	a;
	int	b;

	i = -1;
	if (p->sorted_size > 0)
		free(p->sorted);
	p->sorted_size = p->a_size;
	p->sorted = malloc(sizeof(int) * p->a_size);
	while (++i < p->a_size)
		p->sorted[i] = ft_atoi(p->a[i]);
	a = -1;
	while (++a < p->a_size)
	{
		b = a + 1;
		while (b < p->a_size)
		{
			if (p->sorted[a] > p->sorted[b])
				ft_fill_sorted(p, t, a, b);
			b++;
		}
	}
}
