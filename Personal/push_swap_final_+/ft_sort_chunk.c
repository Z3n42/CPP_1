/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:28:23 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/16 14:39:07 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort_chunk(int size, int *chunk)
{
	int	change;
	int	count;
	int	pos;

	count = 0;
	while (count < size)
	{
		pos = count + 1;
		while (pos < size)
		{
			if (chunk[count] > chunk[pos])
			{
				change = chunk[count];
				chunk[count] = chunk[pos];
				chunk[pos] = change;
			}
			pos++;
		}
		count++;
	}
	count = 0;
	while(count < size)
	{
		printf("chunk short [%d] :%d\n", count, chunk[count]);
		count++;
	}
}
