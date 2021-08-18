/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:07:22 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/05 19:46:09 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_checker(int argc, int *a)
{
	int count;
	int less;

	count = 0;
	less = 0;
	while(count < (argc - 1))
	{
		if(a[count] < a[count + 1])
			less++;
		count++;
	}	
	if(less == (argc - 1))
		return (1);
	else
		return (0);
}
