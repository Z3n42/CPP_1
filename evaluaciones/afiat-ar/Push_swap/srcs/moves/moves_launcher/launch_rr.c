/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:47:47 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/14 18:47:47 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_launch_rra(t_push *p)
{
	ft_rra(p);
	ft_printf("rra\n");
}

void	ft_launch_rrb(t_push *p)
{
	ft_rrb(p);
	ft_printf("rrb\n");
}

void	ft_launch_rrr(t_push *p)
{
	ft_rra(p);
	ft_rrb(p);
	ft_printf("rrr\n");
}
