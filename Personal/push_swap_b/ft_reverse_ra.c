/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_ra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 13:26:35 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/13 15:05:33 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

void	ft_reverse_ra(int argc, int *a)
{
	int	count;
	int swap;

	/* printf("Agrc in RRA: %d\n", argc); */
	swap = a[argc - 1];
	count = argc - 1;
	while(count >= 1)
	{
		a[count] = a[count - 1];
		count--;
	}
	a[0] = swap;
	write(1, "rra\n", 4);
}
