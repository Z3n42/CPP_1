/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */

/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:18:58 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/16 10:47:51 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_hundred(int args, int *a, int *b)
{
	int	count;
	/* int *array; */
	int chunk;
	int pos;
	int plus;
	int counter;
	/* int	counte; */
	int argb;

	/* printf("Hundred args[%d]\n", args); */
	count = args;
	/* printf("Hundred count[%d]\n", count); */
	pos = args/5;
	/* printf("Hundred pos[%d]\n", pos); */
	plus = args/5;
	/*array = */ft_chunk(args, a);
	counter = 0;
	/* while(counter < args) */
	/* { */
	/* 	printf("Array  ordenado [%d] :%d\n", counter, array[counter]); */
	/* 	counter++; */
	/* } */
	chunk = pos;
	while(count > 0)
	{
		/* printf("Nuevo_Chunk=========================================> %d\n", chunk); */
		if(ft_chunkup(count, chunk, a) <= ((count) - ft_chunkdown(count, chunk, a)))
		{
			/* printf("***************Chunkup in: %d\n", ft_chunkup(count, chunk, a)); */
			/* printf("***************Chunkdown in: %d\n", ft_chunkdown(count, chunk, a)); */
			/* printf("****************Chunkdiff  in: %d\n", (count - ft_chunkdown(count, chunk, a))); */
			while((ft_chunkup(count, chunk, a)) != 0 && (a[0] > chunk))
			{
			/* printf("***************Chunkup in: %d\n", ft_chunkup(count, chunk, a)); */
			/* printf("***************Chunkdown in: %d\n", ft_chunkdown(count, chunk, a)); */
			/* printf("****************Chunkdiff  in: %d\n", (count - ft_chunkdown(count, chunk, a))); */
				/* printf("Chunkup[%d] : %d\n", count, ft_chunkup(count, chunk, a)); */
				ft_rotate_a(count, a);
			}
			/* printf("Chunkup Push[%d] : %d\n", count, a[ft_chunkup(count, chunk, a)]); */
			/* if(a[0] > b[0]) */
			/* 	ft_rotate_b(args, b); */
			ft_push_b(args, a, b);
			count--;
			/* printf("COUNT UP -----> %d\n", count); */
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
			/* printf("***************Chunkup in: %d\n", ft_chunkup(args, chunk, a)); */
			/* printf("***************Chunkdown in: %d\n", ft_chunkdown(args, chunk, a)); */
			/* printf("****************Chunkdiff  in: %d\n", (count - ft_chunkdown(args, chunk, a))); */
			while((ft_chunkdown(count, chunk, a) != 0) && (a[0] > chunk))
			{
			/* printf("***************Chunkup in: %d\n", ft_chunkup(count, chunk, a)); */
			/* printf("***************Chunkdown in: %d\n", ft_chunkdown(count, chunk, a)); */
			/* printf("****************Chunkdiff  in: %d\n", (count - ft_chunkdown(count, chunk, a))); */
			/* 	/1* printf("Chunkdown[%d] : %d\n", count, ft_chunkdown(count, chunk, a)); *1/ */
				ft_reverse_ra(count, a);
				/* sleep(1); */
			}
			/* printf("Chunkdown Push[%d] : %d\n", count, a[ft_chunkdown(count, chunk, a)]); */	
			/* if(a[0] > b[0]) */
			/* 	ft_rotate_b(args, b); */
			ft_push_b(args, a, b);
			count--;
			/* printf("COUNT DOWN -----> %d\n", count); */
			counter++;
			/* printf("ChunkCount DOWN : %d\n", count); */
		}
		/* counte = 0; */
		/* while(args > (counte)) */
		/* { */
		/* 	printf("a_hundred_2[%d] :%d | b_hundre_2[%d] :%d\n", counte, a[counte], counte, b[counte]); */
		/* 	counte++; */
		/* } */
		if(counter == pos)
		{
			pos += plus;
	/* printf("plus xxxxxxxxxxxxxxxxxxxxxxxxx>> %d\n", plus); */
			if(plus < args)
				chunk = pos;
			else 
				chunk = args;
		}
	}
		/* counte = 0; */
		/* while(args > (counte)) */
		/* { */
		/* 	printf("a_hundred_3[%d] :%d | b_hundre_3[%d] :%d\n", counte, a[counte], counte, b[counte]); */
		/* 	counte++; */
		/* } */
	/* ft_three(count, a); */
		/* printf("MID_Count: %d\n", count); */
		/* printf("MID_Args: %d\n", args); */
	argb = args;
		while(count < args)
	{
		/* printf("Maxcheck in : %d\n", ft_maxcheck(count, b)); */
		if(ft_maxcheck(argb, b) <= (argb / 2))
		{
			while(ft_maxcheck(argb, b) != 0)
			{
			if((ft_maxcheck(args, b) == 1) && (b[0] < (b[1])))
				ft_swap_b(b);
			else
				/* printf("Maxcheck up : %d\n", ft_maxcheck(count, b)); */
				ft_rotate_b(argb, b);
				/* sleep(1); */
			}
			/* printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW_UP_WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n"); */
			ft_push_a(args, a, b);
			argb--;
			count++;
		}
		else
		{
			while(ft_maxcheck(argb, b) != 0)
			/* { */
				/* printf("Maxcheck up : %d\n", ft_maxcheck(count, b)); */
				ft_reverse_rb(argb, b);
			/* } */
			/* printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW_DOWN_WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n"); */
			ft_push_a(args, a, b);
			argb--;	
			count++;
		}
		/* printf("END_Count: %d\n", count); */
		/* printf("END_Args: %d\n", args); */
		/* counte = 0; */
		/* while(args > (counte)) */
		/* { */
		/* 	printf("a_hundred_fin[%d] :%d | b_hundre_fin[%d] :%d\n", counte, a[counte], counte, b[counte]); */
		/* 	counte++; */
		/* } */
	}
	/* free(array); */
}
