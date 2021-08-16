
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:21:42 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/31 21:20:37 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
	int count;
	int *a;
	int *b;
	/* char **args; */
	
	a = (int *)malloc((argc - 1) * sizeof(int));
	b = (int *)ft_calloc((argc - 1), sizeof(int));
	/* args = (char **)malloc((argc - 1) * sizeof(char *)); */
	if(argc > 1)
	{
		/* count = 1; */
		/* while(count <= (argc - 1)) */
		/* { */
		/* 	args = ft_split(argv[count], ' '); */
		/* 	count++; */
		/* } */
		count = 0;
		while(argc > (count + 1))
		{
			a[count] = ft_atoi_push(argv[count + 1]);
			/* printf("a[%d] :%d | b[%d] :%d\n", count, a[count], count, b[count]); */
			count++;
		}
		/* free(args); */
		if(ft_checker(argc - 1, a) != 1)
			/* ft_mincheck(argc, a); */
		{
			ft_error(argc - 1, a);
			if(argc == 3)
				ft_swap_a(a);
			if(argc == 4)
				ft_three(argc - 1, a);
			if(argc > 4 && argc < 8)
				ft_five(argc - 1, a, b);
			if(argc > 7 && argc < 150)
			/* { */
				/* printf(">>>>>>>>>>>>>>>>>>>>>>>>>>100<<<<<<<<<<<<<<<"); */
				ft_hundred(argc - 1, a, b);
			/* } */
			if(argc > 149)
			/* { */
				/* printf(">>>>>>>>>>>>>>>>>>>>>>>>>>500<<<<<<<<<<<<<<<"); */
				ft_fivehund(argc - 1, a, b);
			/* } */
		}
		/* count = 0; */
		/* while(argc > (count + 1)) */
		/* { */
		/* 	printf("afin[%d] :%d | bfin[%d] :%d\n", count, a[count], count, b[count]); */
		/* 	count++; */
		/* } */
		/* /1* printf("return : %d\n",ft_checker(argc, a)); *1/ */
		/* /1* if(argc >= 2) *1/ */
		/* /1* { *1/ */
		/* 	count = 0; */
		/* ft_rotate_rr(argc, a, b); */
		/* ft_rotate_a(argc, a); */
		/* ft_rotate_b(argc, b); */
		/* ft_rotate_a(argc, a); */
		/* ft_push_a(argc, a, b); */
		/* ft_push_a(argc, a, b); */
		/* ft_push_b(argc, a, b); */
		/* ft_reverse_rr(argc, a, b); */
		/* count = 0; */
		/* while(argc > (count + 1)) */
		/* { */
		/* 	printf("a2[%d] :%d | b2[%d] :%d\n", count, a[count], count, b[count]); */
		/* 	coiuntc++; */
		/* } */
				/* ft_rotate_a(argc, a); */
				/* ft_push_b(argc, a, b); */
				/* ft_push_a(argc, a, b); */
				/* ft_push_a(argc, a, b); */
				/* ft_rotate_rr(argc, a, b); */
				/* count = 0; */
				/* while(a[count] || b[count]) */
				/* { */
				/* 	printf("a3[%d] :%d | b3[%d] :%d\n", count, a[count], count, b[count]); */
					/* count++; */
			/* } */
	}
	free(b);
	return(*a);
}
