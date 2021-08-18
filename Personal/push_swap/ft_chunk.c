/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:30:22 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/16 16:47:44 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_chunk(int args, int *a)
{
	int count;
	int	j;
	int *chunk;
	int *temp;

	count = 0;
	/* printf("Chunk__Args__ %d", args); */
	chunk = (int *)malloc(args * sizeof(int));
	temp = (int *)malloc(args * sizeof(int));
	while(count < args)
	{
		chunk[count] = a[count];
		/* printf("a[%d] :%d | chunk[%d] :%d\n", count, a[count], count, chunk[count]); */
		count++;
	}
	/* count = 0; */
	/* while(count < args) */
	/* { */
	/* 	printf("chunk preordenado [%d] :%d\n", count, chunk[count]); */
	/* 	count++; */
	/* } */
	ft_sort_chunk(args, chunk);
	/* count = 0; */
	/* while(count < args) */
	/* { */
	/* 	printf("chunk ordenado [%d] :%d\n", count, chunk[count]); */
	/* 	count++; */
	/* } */
	/* ft_index(chunk, args, a); */
	count = 0;
	j = 0;
	while(count < args)
	{
		j = 0;
		/* break; */
		while(j < args)
		{
				/* printf("%d----------se convierte en-------%d\n", chunk[couny], count); */
			if(chunk[count] == a[j])
			{
				/* printf("%d----------se convierte en-------%d\n", a[j], count); */
				/* printf("J ------->%d\n Args------->%d\n", j, args); */
				temp[j] = count;
				/* count++; */
			}
			j++;
		}
		count++;
	}
	count = 0;
	while(count < args)
	{
		a[count] = temp[count];
		/* printf("a[%d] :%d | chunk[%d] :%d\n", count, a[count], count, chunk[count]); */
		count++;
	}
	/* count = 0; */
	/* while(count < args) */
	/* { */
	/* 	printf("+++++++++ A_index ++++ > [%d] :%d\n", count, a[count]); */
	/* 	count++; */
	/* } */
	free(temp);
	free(chunk);
	/* return (a); */
}	
