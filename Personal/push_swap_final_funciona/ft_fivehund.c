/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fivehund.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:26:10 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/14 14:13:11 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_fivehund(int args, int *a, int *b)
{
	int	count;
	int *array;
	int chunk;
	int pos;
	int plus;
	int counter;

	/* printf("Hundred args[%d]\n", args); */
	count = args - 1;
	/* printf("Hundred count[%d]\n", count); */
	pos = args/25;
	/* printf("Hundred pos[%d]\n", pos); */
	plus = args/25;
	array = ft_chunk(args, a);
	counter = 0;
	/* while(counter < args) */
	/* { */
	/* 	printf("Array  ordenado [%d] :%d\n", counter, array[counter]); */
	/* 	counter++; */
	/* } */
	chunk = pos;
	while(count >= 0)
	{
		/* printf("Nuev_Chunk=========================================> %d\n", chunk); */
		if(ft_chunkup(count, chunk, a) <= (count - ft_chunkdown(count, chunk, a)))
		{
			/* printf("***************Chunkup in: %d\n", ft_chunkup(count, chunk, a)); */
			/* printf("***************Chunkdown in: %d\n", ft_chunkdown(count, chunk, a)); */
			/* printf("****************Chunkdiff  in: %d\n", (args - ft_chunkdown(count, chunk, a))); */
			while((ft_chunkup(count, chunk, a)) != 0 && (a[0] > chunk))
			/* { */
				/* printf("Chunkup[%d] : %d\n", count, ft_chunkup(count, chunk, a)); */
				ft_rotate_a(count, a);
			/* } */
			/* printf("Chunkup Push[%d] : %d\n", count, ft_chunkup(count, chunk, a)); */
			ft_push_b(args, a, b);
			count--;
			counter++;
			/* printf("ChunkCount UP : %d\n", count); */
		/* counter = 0; */
		/* while(args > (counter)) */
		/* { */
		/* 	printf("b_Chunkup_[%d] :%d\n", counter, b[counter]); */
		/* 	counter++; */
		/* } */
		}
		else
		{
			while((ft_chunkdown(count, chunk, a) != 0) && (a[0] > chunk))
			/* { */
				/* printf("Chunkdown[%d] : %d\n", count, ft_chunkdown(count, chunk, a)); */
				ft_reverse_ra(count + 1, a);
			/* } */
			/* printf("Chunkdown Push[%d] : %d\n", count, ft_chunkdown(count, chunk, a)); */
			ft_push_b(args, a, b);
			count--;
			counter++;
			/* printf("ChunkCount DOWN : %d\n", count); */
		}
		/* counter = 0; */
		/* while(args > (counter)) */
		/* { */
		/* 	printf("a_hundred_2[%d] :%d | b_hundre_2[%d] :%d\n", counter, a[counter], counter, b[counter]); */
		/* 	counter++; */
		/* } */
		if(counter == pos)
		{
			pos += plus;
			/* printf("plus xxxxxxxxxxxxxxxxxxxxxxxxx>> %d\n", plus); */
			if(plus < args - 1)
				chunk = pos;
			else 
				chunk = args;
		}
	/* if((pos + plus) < args) */
	/* 	chunk = array[pos+plus]; */
	/* else */ 
	/* 	chunk = array[args]; */
	}
	/* 	/1* counter = 0; *1/ */
		/* while(args > (counter)) */
		/* { */
		/* 	printf("a_hundred_3[%d] :%d | b_hundre_3[%d] :%d\n", counter, a[counter], counter, b[counter]); */
		/* 	counter++; */
		/* } */
	/* ft_three(count, a); */
		/* printf("MID_Count: %d\n", count); */
		/* printf("MID_Args: %d\n", args); */
	while(count < args - 1)
	{
		/* printf("Maxcheck in : %d\n", ft_maxcheck(count, b)); */
		if(ft_maxcheck(args, b) < (args / 2))
		{
		while(ft_maxcheck(args, b) != 0)
		{
			if((ft_maxcheck(args, b) == 1) && (b[0] < (b[1])))
				ft_swap_b(b);
			else
				/* printf("Maxcheck up : %d\n", ft_maxcheck(count, b)); */
				ft_rotate_b(args, b);
		}
			/* printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW_UP_WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n"); */
			ft_push_a(count, a, b);
			count++;
		}
		else
		{
			while(ft_maxcheck(args, b) != 0)
			{
				/* if((ft_maxcheck(args, b) == 1) && (b[0] < (b[1]))) */
				/* 	ft_swap_b(b); */
				/* else */
			/* /1* { *1/ */
				/* printf("Maxcheck up : %d\n", ft_maxcheck(count, b)); */
				ft_reverse_rb(args, b);
			}
			/* } */
			/* printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW_DOWN_WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n"); */
			ft_push_a(count, a, b);	
			count++;
		}
		/* printf("END_Count: %d\n", count); */
		/* printf("END_Args: %d\n", args); */
		/* counter = 0; */
		/* while(args > (counter)) */
		/* { */
		/* 	printf("a_hundred_fin[%d] :%d | b_hundre_fin[%d] :%d\n", counter, a[counter], counter, b[counter]); */
		/* 	counter++; */
		/* } */
	}
	free(array);
}
