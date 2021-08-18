/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:59:11 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/18 15:48:19 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_rotup(int args, int count, int chunk, int *a, int *b)
{
	int up;

	up =  ft_chunkup(count, chunk, a);
	while(up != 0 && (a[0] > chunk))
			ft_rotate_a(count, a);
		ft_push_b(args, a, b);
		count--;
		/* counter++; */
	return(count);
}

int	ft_rotdown(int args, int count, int chunk, int *a, int *b)
{
	int	down;

	down =  ft_chunkdown(count, chunk, a);
	while(down != 0 && (a[0] > chunk))
			ft_reverse_ra(count, a);
		ft_push_b(args, a, b);
		count--;
		/* counter++; */
	return(count);
}
