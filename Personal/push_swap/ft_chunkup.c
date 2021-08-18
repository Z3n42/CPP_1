/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunkup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:08:01 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/16 10:47:53 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_chunkup(int args, int chunk, int *a)
{
	int	count;

	count = 0;
	while(count < args)
	{
		if(a[count] <= chunk)
		{
			/* printf("chunkup count[%d]\n", count); */
			return (count);
		}
		count++;
	}
	return(ft_mincheck(args, a));
}
