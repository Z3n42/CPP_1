/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol_hundred_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:43:31 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/14 18:46:51 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_loop_a(t_push *p, int x, int size)
{
	int	down_moves;
	int	up_moves;

	if (x >= size)
		x = size - 1;
	down_moves = ft_check_down_moves(p, p->aux[x]);
	up_moves = ft_check_up_moves(p, p->aux[x]);
	if (up_moves < (p->size_a - 1) - down_moves)
		ft_case_up(p->a[up_moves], p);
	else
		ft_case_down(p->a[down_moves], p);
}
