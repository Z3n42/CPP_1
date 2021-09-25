/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_hundred_nums.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:38:53 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/14 18:45:29 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_check_up_moves(t_push *p, int max_value_in_chunk)
{
	int	i;

	i = 0;
	while (i < p->size_a)
	{
		if (p->a[i] < max_value_in_chunk)
			return (i);
		i++;
	}
	return (0);
}

int	ft_check_down_moves(t_push *p, int max_value_in_chunk)
{
	int	i;

	i = p->size_a - 1;
	while (i > 0)
	{
		if (p->a[i] < max_value_in_chunk)
			return (i);
		i--;
	}
	return (0);
}

void	ft_case_up(int change_value, t_push *p)
{
	while (p->a[0] != change_value)
	{
		if (p->a[1] == change_value)
		{
			ft_launch_sa(p);
			break ;
		}
		ft_launch_ra(p);
	}
	ft_launch_pb(p);
}

void	ft_case_down(int change_value, t_push *p)
{
	while (p->a[0] != change_value)
	{
		if (p->a[1] == change_value)
		{
			ft_launch_sa(p);
			break ;
		}
		ft_launch_rra(p);
	}
	ft_launch_pb(p);
}

void	ft_order_hundred_nums(t_push *p)
{
	int	i;
	int	chunk_size;
	int	x;
	int	size;

	x = 0;
	i = 0;
	size = p->size_a;
	chunk_size = 20;
	if (p->size_a % 20 != 0)
		chunk_size = 1;
	while ((p->size_a) != 0)
	{
		i = 0;
		x += chunk_size;
		while (i < chunk_size)
		{
			ft_loop_a(p, x, size);
			i++;
		}
	}
	ft_order_stack_b(p);
}
