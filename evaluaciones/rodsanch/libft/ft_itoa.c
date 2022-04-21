/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:59:42 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/19 17:07:04 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int nb)
{
	int	nb_len;

	nb_len = 0;
	if (nb == 0)
		nb_len++;
	if (nb < 0)
	{
		nb *= -1;
		nb_len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		nb_len++;
	}
	return (nb_len);
}

char	*ft_charconv(char *dest, int nb, int nb_len)
{
	if (nb == 0)
		*dest = '0';
	if (nb < 0)
	{
		*dest = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		*(dest + nb_len--) = '0' + (nb % 10);
		nb /= 10;
	}
	return (dest);
}

char	*ft_itoa(int nb)
{
	char	*dest;
	int		nb_len;

	if (nb == -2147483648)
	{
		dest = (char *)malloc(sizeof(char) * 12);
		if (!dest)
			return (NULL);
		ft_strlcpy(dest, "-2147483648", 12);
		return (dest);
	}
	nb_len = ft_len(nb);
	dest = (char *)malloc(sizeof(char) * nb_len + 1);
	if (!dest)
		return (NULL);
	*(dest + nb_len--) = '\0';
	dest = ft_charconv(dest, nb, nb_len);
	return (dest);
}

/* int	main(void)
{
	printf("%s\n", ft_itoa(123156));
	return (0);
}
 */