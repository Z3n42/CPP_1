/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:47:49 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/14 18:47:50 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_launch_ra(t_push *p)
{
	ft_ra(p);
	ft_printf("ra\n");
}

void	ft_launch_rb(t_push *p)
{
	ft_rb(p);
	ft_printf("rb\n");
}

void	ft_launch_rr(t_push *p)
{
	ft_ra(p);
	ft_rb(p);
	ft_printf("rr\n");
}
