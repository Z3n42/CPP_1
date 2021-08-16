/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:34:18 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/12 12:14:53 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

void	ft_three(int argc, int *a)
{
	int count;

	printf("Argc en three = %d\n", argc);
	printf("three\n");
	/* if((a[0] == a[1]) || (a[1] == a[2]) || (a[2] == a[0])) */
	/* { */
	/* 	write(1, "ERROR\n", 6); */
	/* 	exit(1); */
	/* } */
	if(a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
		ft_swap_a(a);
	if(a[0] > a[1] && a[1] > a[2] && a[2] < a[0])
	{
		ft_swap_a(a);
		ft_reverse_ra(argc, a);
	}
	if(a[0] > a[1] && a[1] < a[2] && a[2] < a[0])
		ft_rotate_a(argc, a);
	if(a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
	{
		ft_swap_a(a);
		ft_rotate_a(argc, a);
	}
	if(a[0] < a[1] && a[1] > a[2] && a[2] < a[0])
		ft_reverse_ra(argc, a);
		count = 0;
		while(argc > (count + 1))
		{
			printf("a_three[%d] :%d\n", count, a[count]);
			count++;
		}
}
