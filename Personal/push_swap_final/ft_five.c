/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:50:23 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/05 18:40:32 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

void	ft_five(int args, int *a, int *b)
{
	int	count;
	/* int	counter; */

	count = args;
	while(count > 3)
	{
		if(ft_mincheck(count,  a) < (count / 2))
		{
			while(ft_mincheck(count, a) != 0)
			{
				/* printf("Minimo en five ra = %d\n", ft_mincheck(count, a)); */
				ft_rotate_a(count, a);
			}
			ft_push_b(count, a, b);
			count--;
			/* counter = 0; */
			/* while(args > (counter + 1)) */
			/* { */
			/* 	printf("a3[%d] :%d | b3[%d] :%d\n", counter, a[counter], counter, b[counter]); */
			/* counter++; */
			/* } */
		}
		else
		{
			while(ft_mincheck(count, a) != 0)
			{
			
				/* printf("Minimo en five rra = %d\n", ft_mincheck(count, a)); */
				ft_reverse_ra(count, a);
			}
			ft_push_b(count, a, b);	
			count--;
			/* counter = 0; */
			/* while(args > (counter + 1)) */
			/* { */
			/* 	printf("a4[%d] :%d | b4[%d] :%d\n", counter, a[counter], counter, b[counter]); */
			/* 	counter++; */
			/* } */
		}
	}
	/* counter = 0; */
	/* while(args > (counter + 1)) */
	/* { */
	/* 	printf("a5[%d] :%d | b5[%d] :%d\n", counter, a[counter], counter, b[counter]); */
	/* 	counter++; */
	/* } */
	/* printf("Count en five - %d\n", count); */
	ft_three(count, a);
	/* counter = 0; */
	/* while(args > (counter + 1)) */
	/* { */
	/* 	printf("a6[%d] :%d | b6[%d] :%d\n", counter, a[counter], counter, b[counter]); */
	/* 	counter++; */
	/* } */
	while(count < args)
	{
		ft_push_a(count, a, b);
			count++;
	}
}
