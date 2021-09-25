/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:47:11 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/15 10:14:29 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_push *p)
{
	if (p->size_a <= 0)
		return ;
	ft_swap(&p->a[0], &p->a[1]);
}

void	ft_sb(t_push *p)
{	
	if (p->size_b <= 0)
		return ;
	ft_swap(&p->b[0], &p->b[1]);
}

void	ft_ss(t_push *p)
{
	ft_sa(p);
	ft_sb(p);
}
