/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:24:07 by ecorreia          #+#    #+#             */
/*   Updated: 2021/07/01 19:28:56 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tam(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = (n * -1);
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		siz;
	long	h;
	int		i;
	long	num;

	num = (long)n;
	siz = tam(num) - 1;
	h = 1;
	i = 0;
	while (i++ < siz)
		h *= 10;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	while (siz-- >= 0)
	{
		ft_putchar_fd('0' + (num / h), fd);
		num = num - (num / h * h);
		h /= 10;
	}
}
