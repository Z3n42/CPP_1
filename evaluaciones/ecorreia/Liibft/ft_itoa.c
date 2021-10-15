/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:15:58 by ecorreia          #+#    #+#             */
/*   Updated: 2021/07/02 18:18:54 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	len(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = (n * -1);
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	num;
	int		sign;

	num = (long)n;
	i = len(num);
	sign = 0;
	if (n < 0)
		num *= -1;
	str = malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (num == 0)
		str[i--] = '0';
	while (num >= 1)
	{
		str[i--] = '0' + (num % 10);
		num = num / 10;
	}
	if (n < 0)
		str[i--] = '-';
	return (str);
}
