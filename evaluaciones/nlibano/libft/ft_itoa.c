/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlibano- <nlibano-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:19:23 by nlibano-          #+#    #+#             */
/*   Updated: 2021/11/19 19:42:32 by nlibano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_itoa_size(int n)
{
	long int	num;
	size_t		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		num = num * -1;
		count++;
	}	
	while (num / 10)
	{
		count++;
		num = num / 10;
	}
	count++;
	return (count);
}

static char	*ft_put_mumber(long int num, char *dst)
{
	size_t		j;
	long int	i;

	j = 0;
	if (num < 0)
	{
		num = num * -1;
		dst[0] = '-';
		j++;
	}
	i = 1;
	while (num / i != 0)
		i *= 10;
	while (i != 1)
	{
		i /= 10;
		dst[j] = (num % (10 * i) - num % i) / i + '0';
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*dst;

	num = n;
	dst = (char *)malloc(sizeof(char) * ft_get_itoa_size(n) + 1);
	if (!dst)
		return (NULL);
	if (num == 0)
	{
		dst[0] = '0';
		dst[1] = '\0';
		return (dst);
	}
	dst = ft_put_mumber(num, dst);
	return (dst);
}
