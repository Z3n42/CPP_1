/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:09:25 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/13 15:05:05 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "push_swap.h"

void	ft_push_a(int argc, int *a, int *b)
{
	int	count;

	count = argc;
	while(count >= 1)
	{	
		/* printf("1st PA_a[%d]-%d === %d\n", count, a[count], a[count - 1]); */
		a[count] = a[count - 1];
		count--;
	}
	a[0] = b[0];
	count = 0;
	while(argc >= (count + 1))
	{	
		/* printf("2nd PA_b[%d]-%d === %d\n", count, b[count], b[count + 1]); */
		b[count] = b[count + 1];
		count++;
	}
	b[count] = 0;
	write(1, "pa\n", 3);	
}
