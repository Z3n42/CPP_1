/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:35:27 by iestevez          #+#    #+#             */
/*   Updated: 2021/04/23 12:18:14 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
char	g_a;
char	g_b;
char	g_c;
char	g_d;

void	ft_putchar(char g_a, char g_b, char g_c, char g_d)
{
	if (g_b < '8' || g_a < '9')
	{
		write (1, &g_a, 1);
		write (1, &g_b, 1);
		write (1, " ", 1);
		write (1, &g_c, 1);
		write (1, &g_d, 1);
		write (1, ", ", 1);
	}
	else
	{
		write (1, &g_a, 1);
		write (1, &g_b, 1);
		write (1, " ", 1);
		write (1, &g_c, 1);
		write (1, &g_d, 1);
	}
}

void	ft_print_comb2(void)
{
	g_a = '0';
	{
		while (g_a <= '9' )
		{	
			g_b = '0';
			while (g_b <= '8')
			{
				g_c = g_a;
				while (g_c <= '9')
				{
					g_d = g_b +1;
					while (g_d <= '9')
					{	
						ft_putchar (g_a, g_b, g_c, g_d);
						g_d++;
					}
					g_c++;
				}
				g_b++;
			}
			g_a++;
		}
	}
}


void	ft_print_comb2(void);

int	main(void)
{
	ft_print_comb2();
}
