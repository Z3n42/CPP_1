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
	int chunk;
	int pos;
	int counter;

	count = args;
	pos = args/6;
	counter = 0;
	chunk = pos;
	ft_chunk(args, a);
	while(count > 0)
	{
		/* if(ft_chunkup(count, chunk, a) == ((count + 1) - ft_chunkdown(count, chunk, a))) */
		/* { */
		/* 	if(ft_chunkup(count, chunk, a) > ((count + 1) - ft_chunkdown(count, chunk, a))) */
		/* 	{ */
				
		/* 		count = ft_rotup(args, count, chunk, a , b); */
		/* 		counter++; */
		/* 	} */
		/* 	else */
		/* 	{ */
		/* 		count = ft_rotdown(args, count, chunk, a , b); */
		/* 		counter++; */
		/* 	} */
		/* 	if(counter == chunk) */
		/* 		chunk += pos; */
		/* } */
		if(ft_chunkup(count, chunk, a) <= ((count + 1) - ft_chunkdown(count, chunk, a)))
		{
			count = ft_rotup(args, count, chunk, a , b);
			counter++;
		}
		else
		{
			count = ft_rotdown(args, count, chunk, a , b);
			counter++;
		}
		if(counter == chunk)
			chunk += pos;
	}
	ft_pushtoa(args, args, count, a, b);
}
