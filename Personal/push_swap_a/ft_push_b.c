/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:36:28 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/05 18:35:31 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "push_swap.h"

void	ft_push_b(int argc, int *a, int *b)
{
	int	count;

	/* printf("Argc en PB = %d\n", argc); */
	count = argc - 1;
 	while(count >= 1)
	{
		/* printf("1st PB-%d\n", count); */
		b[count] = b[count - 1];
		count--;
	}
	b[0] = a[0];
	/* printf("Mid PB\n"); */
	count = 0;
	while(argc > (count + 1))
	{
		/* printf("2nd PB-%d\n", count); */
		a[count] = a[count + 1];
		count++;
	}
	/* printf("Count out PB-%d\n", count); */
	  a[count] = 0;
	write(1, "pb\n", 3);	
}	
