/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:30:22 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/13 21:19:23 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	 *ft_chunk(int args, int *a)
{
	int count;
	int	j;
	int *chunk;

	count = 0;
	chunk = (int *)malloc(args * sizeof(int));
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
	count = 0;
	j = 1;
	while(count < args)
	{
		/* break; */
		while(j < args)
		{
			if(chunk[count] == a[j])
				a[j] = count;
			j++;
		}
		count++;
		j = 0;
	}
	/* count = 0; */
	/* while(count < args) */
	/* { */
	/* 	printf("+++++++++ A_index ++++ > [%d] :%d\n", count, a[count]); */
	/* 	count++; */
	/* } */
	return (chunk);
}	
