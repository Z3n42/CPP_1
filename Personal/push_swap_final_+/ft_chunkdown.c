/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunkdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:10:55 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/16 13:16:30 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_chunkdown(int args, int chunk, int *a)
{
	int	count;

	count = args;
	/* printf("Chunkdw  args[%d]\n", args); */
	/* printf("Chunkdw  count[%d]\n", count); */
	while (count >= 0)
	{
		if(a[count] <= chunk)
		{
			/* printf("Chunkdw chunk****%d**\n", chunk); */
			/* printf("Chunkdw  pos****%d**\n", a[count]); */
			return (count);
		}
		count--;
	}	
	return(ft_mincheck(args, a));
}
