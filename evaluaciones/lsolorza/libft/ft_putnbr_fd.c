/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:17:05 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:17:12 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnbr_fd(int n, int fd)
{
	if (n >= 10)
	{
		ft_printnbr_fd(n / 10, fd);
	}
	ft_putchar_fd('0' + n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_printnbr_fd(214748364, fd);
		ft_printnbr_fd(8, fd);
	}
	else
	{
		if (n < 0 && n >= -2147483647)
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
		}
		ft_printnbr_fd(n, fd);
	}
}
