/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:05:11 by iibanez-          #+#    #+#             */
/*   Updated: 2021/06/24 18:40:58 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_digits(long n)
{
	int	digits;

	digits = 1;
	if (n < 0)
		n = n * -1;
	while (n / 10 > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		dig;
	char	*dest;
	long	num;

	dig = ft_count_digits((long) n);
	if (n < 0)
		dig++;
	dest = malloc(sizeof(*dest) * (dig + 1));
	if (dest == NULL)
		return (NULL);
	dest[dig] = '\0';
	num = (long) n;
	if (num < 0)
	{
		dest[0] = '-';
		num = num * (-1);
	}
	while (num >= 10)
	{
		dig--;
		dest[dig] = (num % 10) + '0';
		num = num / 10;
	}
	dest[dig - 1] = num + '0';
	return (dest);
}
