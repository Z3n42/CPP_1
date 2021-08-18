/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:11:59 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/06 14:15:38 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

void 	ft_error(int args, int *c)
{
	int i;
	int	j;

	i = 0;
	j = 1;
	/* printf("Argc in=%d\n", args); */
	while(i < args)
	{
		/* printf("Error count i: %d\n", i); */
		while(j < args)
		{
			/* printf("Error count j: %d\n", j); */
			if(c[i] == c[j])
				{
					write(1, "ERROR\n", 6);
					exit(1);
				}
			j++;
		}
		i++;
		j = i + 1;
	}
}
