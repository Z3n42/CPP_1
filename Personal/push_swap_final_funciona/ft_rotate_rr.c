/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:02:14 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/03 19:31:42 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

void	ft_rotate_rr(int argc, int *a, int *b)
{
	int	count;
	int swap;

	swap = a[0];
	count = 0;
	while(count < (argc - 1))
	{
		a[count] = a[count + 1];
		count++;
	}
	a[argc - 2] = swap;
	swap = b[0];
	count = 0;
	while(count < (argc - 1))
	{
		b[count] = b[count + 1];
		count++;
	}
	b[argc - 2] = swap;
	write(1, "rr\n", 3);
}
