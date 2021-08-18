/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:26:41 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/02 12:36:47 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

void	ft_reverse_rr(int argc, int *a, int *b)
{
	int	count;
	int swap;
	int swapb;

	swap = a[argc - 2];
	swapb = b[argc - 2];
	count = argc - 2;
	while(count >= 1)
	{
		a[count] = a[count - 1];
		b[count] = b[count - 1];
		count--;
	}
	a[0] = swap;
	b[0] = swapb;
	write(1, "rrr\n", 4);
}
