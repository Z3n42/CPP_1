/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:33:57 by lugonzal          #+#    #+#             */
/*   Updated: 2021/04/30 13:39:06 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char in1, char in2, char in3, char in4)
{
	if (in1 == '9' && in2 == '8' && in3 == '9' && in4 == '9')
	{
		write(1, &in1, 1);
		write(1, &in2, 1);
		write(1, " ", 1);
		write(1, &in3, 1);
		write(1, &in4, 1);
	}
	else
	{
		write(1, &in1, 1);
		write(1, &in2, 1);
		write(1, " ", 1);
		write(1, &in3, 1);
		write(1, &in4, 1);
		write(1, ", ", 2);
	}
}

void	ft_n4(char n1, char n2, char n3, char n4)
{
	while (n4 <= '9')
	{
		if (n1 < n3 || (n1 == n3 && n2 < n4))
			ft_putchar (n1, n2, n3, n4);
		n4++;
	}
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;

	n1 = '0';
	while (n1 <= '9')
	{
		n2 = '0';
		while (n2 <= '8')
		{
			n3 = '0';
			while (n3 <= '9')
			{
				n4 = '0';
				ft_n4(n1, n2, n3, n4);
				n3++;
			}
			n2++;
		}
		n1++;
	}
}

int	main(void)
{
	ft_print_comb2();
}
