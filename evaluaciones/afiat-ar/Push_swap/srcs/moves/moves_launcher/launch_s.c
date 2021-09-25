/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:47:44 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/14 18:47:45 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ft_launch_sa(t_push *p)
{
	ft_sa(p);
	ft_printf("sa\n");
}

void	ft_launch_sb(t_push *p)
{	
	ft_sb(p);
	ft_printf("sb\n");
}

void	ft_launc_ss(t_push *p)
{
	ft_sa(p);
	ft_sb(p);
	ft_printf("ss\n");
}
