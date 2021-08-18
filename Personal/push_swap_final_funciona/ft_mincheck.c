/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mincheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:53:43 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/05 18:37:40 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	ft_mincheck(int args, int *c)
{
	int i;
	int	j;
	int min;

	i = 0;
	j = 1;
	min = 0;
	/* printf("Minagcr	in=%d\n", args); */
	while(i < (args))
	{
		while(j < (args))
		{
			if((c[i] < c[j]) && (c[i] < c[min]))
				min = i;
			j++;
		}
		i++;
		j = 0;
	}
	/* printf("Min pos = %d\n", min); */
	return (min);
}
