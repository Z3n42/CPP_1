/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iirazaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:47:11 by iirazaba          #+#    #+#             */
/*   Updated: 2021/04/21 14:00:28 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>

void	ft_print_comb(void)
{
	char	FL;
	char	SL;
	char	TL;

	FL = '0' - 1;
	while (FL++ < '7')
	{
		SL = FL;
		while (SL++ < '8')
		{
			TL = SL;
			while (TL++ < '9')
			{
				if (!(FL == '0' && SL == '1' && TL == '2'))
				{
					write(1, ",", 1);
					write(1, " ", 1);
				}
				write(1, &FL, 1);
				write(1, &SL, 1);
				write(1, &TL, 1);
			}
		}
	}
}
