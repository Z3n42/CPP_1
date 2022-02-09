/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:31:17 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/31 22:17:29 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnum(long int num, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	char		sign;

	sign = 0;
	num = (long int)n;
	if (num < 0)
	{
		sign = '-';
		num = num * -1;
		ft_putchar_fd(sign, fd);
	}
	ft_putnum(num, fd);
}

static void	ft_putnum(long int num, int fd)
{
	char	c;

	if (num < 10)
	{
		c = num + 48;
		ft_putchar_fd(c, fd);
	}
	else
	{
		ft_putnum(num / 10, fd);
		c = (num % 10) + 48;
		ft_putchar_fd(c, fd);
	}
}
