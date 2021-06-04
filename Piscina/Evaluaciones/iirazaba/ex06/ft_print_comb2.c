/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iirazaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:14:07 by iirazaba          #+#    #+#             */
/*   Updated: 2021/04/21 14:07:34 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char a)
{
	write(1, &a, 1);
}

void	ft_print_comb2(void)
{
	int	PNUM;
	int	SNUM;

	PNUM = 0;
	SNUM = 1;
	while (PNUM <= 98)
	{
		while (SNUM <= 99)
		{
			if (PNUM < SNUM)
			{
				put_char((PNUM / 10) + '0');
				put_char((PNUM % 10) + '0');
				put_char(' ');
				put_char((SNUM / 10) + '0');
				put_char((SNUM % 10) + '0');
				if (PNUM < 98)
					write(1, ", ", 2);
			}
			SNUM++;
		}
		PNUM++;
		SNUM = PNUM + 1;
	}
}
