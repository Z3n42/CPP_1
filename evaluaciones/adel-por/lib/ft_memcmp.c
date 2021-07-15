/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:33:25 by adel-por          #+#    #+#             */
/*   Updated: 2021/06/30 11:17:50 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const	void	*s1, const	void	*s2, size_t	n)
{
	unsigned char	*str;
	unsigned char	*spr;
	size_t			i;

	str = (unsigned char *)s1;
	spr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str[i] < spr[i])
			return (str[i] - spr[i]);
		if (str[i] > spr[i])
			return (str[i] - spr[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	kad[] = "Firstone";
	char	kod[] = "Firstone";
	printf("%d", ft_memcmp(kad, kod, 9));
	return (0);
}*/
