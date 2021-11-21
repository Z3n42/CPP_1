/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenito- <hbenito-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:06:58 by hbenito-          #+#    #+#             */
/*   Updated: 2021/11/19 11:33:20 by hbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnum(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		num *= -1;
		count = ft_putchar('-');
	}
	if (num > 9)
		count += ft_putnum(num / 10);
	count += ft_putchar((num % 10) + 48);
	return (count);
}

int	ft_putunnum(unsigned int un)
{
	int	count;

	count = 0;
	if (un > 9)
		count += ft_putunnum(un / 10);
	count += ft_putchar((un % 10) + 48);
	return (count);
}

int	ft_putexa(size_t exa, char c)
{
	int		count;
	char	*b;

	if (c == 'x' || c == 'p')
		b = "0123456789abcdef";
	if (c == 'X')
		b = "0123456789ABCDEF";
	count = 0;
	if (exa > 15)
		count += ft_putexa(exa / 16, c);
	count += write(1, &b[exa % 16], 1);
	return (count);
}
