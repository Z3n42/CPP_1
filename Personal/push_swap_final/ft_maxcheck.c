/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:35:24 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/12 19:36:38 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_maxcheck(int args, int *c)
{
	int i;
	int	j;
	int max;

	i = 0;
	j = 1;
	max = 0;
	while(i < (args))
	{
		while(j < (args))
		{
			if((c[i] > c[j]) && (c[i] > c[max]))
				max = i;
			j++;
		}
		i++;
		j = 0;
	}
	return (max);
}
