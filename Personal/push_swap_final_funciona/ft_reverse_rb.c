/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:51:19 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/05 18:38:28 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

void	ft_reverse_rb(int argc, int *b)
{
	int	count;
	int swap;

	/* printf("Agrc in RRB: %d\n", argc); */
	swap = b[argc - 1];
	count = argc - 1;
	while(count >= 1)
	{
		b[count] = b[count - 1];
		count--;
	}
	b[0] = swap;
	write(1, "rrb\n", 4);
}
