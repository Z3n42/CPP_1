/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_five_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:38:50 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/14 18:50:54 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_make_ra(t_push *p, int low_num)
{
	int	i;

	i = 0;
	while (i < p->size_a)
	{
		if (p->a[0] == low_num)
			break ;
		ft_launch_ra(p);
	}
}

void	ft_loop(t_push *p)
{
	int	low_num;
	int	i;

	i = 0;
	low_num = 2147483647;
	while (i < p->size_a)
	{
		if (low_num > p->a[i])
			low_num = p->a[i];
		i++;
	}
	ft_make_ra(p, low_num);
	ft_launch_pb(p);
}

void	ft_case_five_nums(t_push *p)
{
	int	times;

	times = 0;
	while (times < 2)
	{
		ft_loop(p);
		times++;
	}
	ft_order_three_nums(p);
	ft_launch_pa(p);
	ft_launch_pa(p);
}

void	ft_case_four_nums(t_push *p)
{
	ft_loop(p);
	ft_order_three_nums(p);
	ft_launch_pa(p);
}

void	ft_order_five_nums(t_push *p)
{
	if (p->size_a == 4)
		ft_case_four_nums(p);
	else
		ft_case_five_nums(p);
}
