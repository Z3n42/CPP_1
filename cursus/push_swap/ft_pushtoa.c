/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:27:25 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/18 15:09:33 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_pushtoa(int args, int argb, int count, int *a, int *b)
{
	while(count < args)
	{
		if(ft_maxcheck(argb, b) <= (argb / 2))
		{
			while(ft_maxcheck(argb, b) != 0)
			{
				if((ft_maxcheck(argb, b) == 1) && (b[0] < b[1]))
					ft_swap_b(b);
				else
					ft_rotate_b(argb, b);
			}
			ft_push_a(argb, a, b);
			argb--;
			count++;
		}
		else
		{
			while(ft_maxcheck(argb, b) != 0)
				ft_reverse_rb(argb, b);
			ft_push_a(argb, a, b);
			argb--;	
			count++;
		}
	}
}
