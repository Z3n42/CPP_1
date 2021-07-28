/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:03:02 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/26 15:18:20 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdint.h>

void	ft_putnbr_p(uintptr_t n, int fd)
{
	static int len;
	/* printf("len en put: %d\n", len); */
	if (n > 15)
	{	
		len = 0;
		ft_putnbr_p(n / 16, fd);
		ft_putnbr_p(n % 16, fd);
	}
	else
	{
		if(n > 9)
			n += 39;
		len++;
		ft_putchar_fd(n + '0', fd);
	}
}
