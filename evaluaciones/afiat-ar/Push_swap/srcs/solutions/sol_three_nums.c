/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_three_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:38:55 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/14 18:38:56 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h" 

void	ft_case_one(t_push *p)
{
	ft_launch_sa(p);
}

void	ft_case_two(t_push *p)
{
	ft_launch_sa(p);
	ft_launch_rra(p);
}

void	ft_case_three(t_push *p)
{
	ft_launch_ra(p);
}

void	ft_case_four(t_push *p)
{
	ft_launch_sa(p);
	ft_launch_ra(p);
}

void	ft_case_five(t_push *p)
{
	ft_launch_rra(p);
}
