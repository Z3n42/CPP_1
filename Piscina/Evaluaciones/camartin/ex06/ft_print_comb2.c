/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:31:21 by camartin          #+#    #+#             */
/*   Updated: 2021/04/21 16:38:55 by camartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_first;
int	g_second;
int	g_third;
int	g_fourth;

void	print_number (int v_first, int v_second, int v_third, int v_fourth)
{
	write (1, &v_first, 1);
	write (1, &v_second, 1);
	write (1, " ", 1);
	write (1, &v_third, 1);
	write (1, &v_fourth, 1);
	if (v_first != '9' || v_second !='8' || v_third != '9' || v_fourth != '9')
		write (1, ", ", 2);
}

void	ft_print_comb2 (void)
{
	g_first = '0';
	while (g_first <= '9')
	{
		g_second = '0';
		while (g_second <= '9')
		{
			g_third = g_first;
			while (g_third <= '9')
			{
				g_fourth = g_second + 1;
				while (g_fourth <= '9')
				{
					print_number (g_first, g_second, g_third, g_fourth);
					g_fourth++;
				}
				g_third ++;
			}
			g_second++;
		}
		g_first++;
	}
}
