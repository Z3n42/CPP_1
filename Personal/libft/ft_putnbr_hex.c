/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:52:22 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/23 14:44:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_hex(unsigned int n, int fd)
{
	static int len;

	if (n > 15)
	{
		len = 0;
		ft_putnbr_hex(n / 16, fd);
		ft_putnbr_hex(n % 16, fd);
	}
	else
	{
		len++;
		if(n > 9)
			n += 39;
		ft_putchar_fd(n + '0', fd);
	}
	return (len);
}
