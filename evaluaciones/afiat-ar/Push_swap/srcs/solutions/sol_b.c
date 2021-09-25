/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:38:41 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/14 18:38:42 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_case_rb(t_push *p, int i)
{
	int	change_value;

	change_value = p->b[i];
	while (p->b[0] != change_value)
	{
		if (p->b[1] == change_value)
			ft_launch_sb(p);
		else
			ft_launch_rb(p);
	}
	ft_launch_pa(p);
}

static void	ft_case_rrb(t_push *p, int i)
{
	int	change_value;

	change_value = p->b[i];
	while (p->b[0] != change_value)
	{
		if (p->b[1] == change_value)
			ft_launch_sb(p);
		else
			ft_launch_rrb(p);
	}
	ft_launch_pa(p);
}

void	ft_order_stack_b(t_push *p)
{
	int	max_value;
	int	i;

	i = 0;
	max_value = -2147483647;
	while (p->size_b != 0)
	{
		i = 0;
		max_value = -2147483647;
		while (i < p->size_b)
		{
			if (p->b[i] > max_value)
				max_value = p->b[i];
			i++;
		}
		i = 0;
		while (p->b[i] != max_value)
			i++;
		if (i < ((p->size_b - 1) - i))
			ft_case_rb(p, i);
		else
			ft_case_rrb(p, i);
	}
}
