/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:05:43 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/16 15:18:55 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_index(int *chunk, int args, int *a)
{
	int count;
	int	j;

	count = 0;
	j = 0;
	while(count < args)
	{
		while(j < args)
		{
			if(chunk[count] == a[j])
				a[j] = count;
			j++;
		}
		count++;
		j = 0;
	}
}
