/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunkdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:10:55 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/16 18:30:49 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_chunkdown(int args, int chunk, int *a)
{
	int	count;
	/* int	counte; */

	count = args - 1;
	/* printf("Chunkdw  args[%d]\n", args); */
		/* counte = 0; */
		/* while(args > (counte)) */
		/* { */
		/* 	printf("a_hundred_2[%d] :%d\n", counte, a[counte]); */
		/* 	counte++; */
		/* } */

	while (count >= 0)
	{
			/* printf("Chunkdw  count[%d]\n", count); */
			/* printf("Chunkdw  pos****%d**\n", a[count]); */
		if(a[count] <= chunk)
		{
			/* printf("Chunkdw chunk****%d**\n", chunk); */
			return (count);
		}
		count--;
	}	
	return(ft_mincheck(args, a));
}
