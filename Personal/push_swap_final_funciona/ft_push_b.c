/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:36:28 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/13 15:05:22 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "push_swap.h"

void	ft_push_b(int argc, int *a, int *b)
{
	int	count;

	count = argc - 1;
	/* printf("Count en PB = %d\n", count); */
 	while(count >= 1)
	{
		/* printf("1st PB_b[%d]-%d === %d\n", count, b[count], b[count - 1]); */
		/* printf("1st PB_b[%d]-%d\n", count, b[count]); */
		b[count] = b[count - 1];
		count--;
	}
	b[0] = a[0];
	/* printf("Mid PB-%d\n", count); */
	count = 0;
	while(argc > (count + 1))
	{
		/* printf("2nd PBi_a[%d]-%d === %d\n", count, a[count], a[count + 1]); */
		a[count] = a[count + 1];
		count++;
	}
	/* printf("Count out PB-%d\n", count); */
	  a[count] = 0;
	write(1, "pb\n", 3);	
}	
