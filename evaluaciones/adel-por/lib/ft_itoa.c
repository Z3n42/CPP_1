/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:57:17 by adel-por          #+#    #+#             */
/*   Updated: 2021/07/07 18:42:49 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long n)
{
	int	h;

	h = 1;
	if (n < 0)
	{
		h++;
		n *= -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		h++;
	}
	return (h);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	k;

	k = (long)n;
	count = ft_count(k);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (k < 0)
		k *= -1;
	str[0] = '-';
	if (k == 0)
		*str = n + '0';
	while (k > 0)
	{
		str[--count] = (k % 10) + '0';
		k = k / 10;
	}
	return (str);
}

/*int	main(void)
{
	printf("%s", ft_itoa(-2147483648));
	return (0);
}*/
