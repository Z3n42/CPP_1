/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:30:22 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/16 15:47:06 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_chunk(int args, int *a)
{
	int count;
	int	j;
	int *chunk;

	count = 0;
	/* printf("Chunk__Args__ %d", args); */
	chunk = (int *)malloc(args * sizeof(int));
	while(count < args)
	{
		chunk[count] = a[count];
		/* printf("a[%d] :%d | chunk[%d] :%d\n", count, a[count], count, chunk[count]); */
		count++;
	}
	count = 0;
	while(count < args)
	{
		printf("chunk preordenado [%d] :%d\n", count, chunk[count]);
		count++;
	}
	ft_sort_chunk(args, chunk);
	count = 0;
	while(count < args)
	{
		printf("chunk ordenado [%d] :%d\n", count, chunk[count]);
		count++;
	}
	/* ft_index(chunk, args, a); */
	count = 0;
	j = 0;
	while(count < args)
	{
		/* break; */
		while(j < args)
		{
			if(chunk[count] == a[j])
			{
				printf("%d----------se convierte en-------%d\n", a[j], count);
				a[j] = count;
			}
			j++;
		}
		count++;
		j = 0;
	}
	count = 0;
	while(count < args)
	{
		printf("+++++++++ A_index ++++ > [%d] :%d\n", count, a[count]);
		count++;
	}
	free(chunk);
	/* return (a); */
}	
