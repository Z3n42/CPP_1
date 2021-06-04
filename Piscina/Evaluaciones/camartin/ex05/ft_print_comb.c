/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:08:43 by camartin          #+#    #+#             */
/*   Updated: 2021/04/21 16:36:07 by camartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_distinct (int vfirst, int vsecond, int vthird)
{
	write (1, &vfirst, 1);
	write (1, &vsecond, 1);
	write (1, &vthird, 1);
	if (vfirst !='7' || vsecond != '8' || vthird != '9')
		write (1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	first;
	int	second;
	int	third;

	first = '0';
	while (first <= '9')
	{
		second = first + 1;
		while (second <= '9')
		{
			third = second + 1;
			while (third <= '9')
			{
				ft_distinct (first, second, third);
				third++;
			}
			second++;
		}
		first++;
	}
}
