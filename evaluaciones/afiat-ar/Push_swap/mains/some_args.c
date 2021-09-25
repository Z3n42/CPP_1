/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:37:30 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/19 12:47:16 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_struct(t_push *p, int size)
{
	p->a = (int *)malloc (sizeof(int) * (size));
	p->aux = (int *)malloc (sizeof(int) * (size));
	p->b = ft_calloc((size), sizeof(int));
	p->size_a = size;
	p->size_b = 0;
}

void	ft_some_args(t_push *p, int argc, char *argv[])
{
	int	i;

	i = 0;
	ft_init_struct(p, argc - 1);
	while (i < (p->size_a))
	{
		p->a[i] = ft_atoi_special(argv[i + 1], p);
		p->aux[i] = ft_atoi_special(argv[i + 1], p);
		if (p->a[i] == 0)
			ft_check_str_or_num(argv[i + 1]);
		i++;
	}
}
