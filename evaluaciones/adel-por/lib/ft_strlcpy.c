/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:16:28 by adel-por          #+#    #+#             */
/*   Updated: 2021/06/30 12:44:15 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lsrc;

	if (dest == NULL || src == NULL)
		return (0);
	i = 0;
	lsrc = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (lsrc);
}

/*int	main(void)
{
	char	kad[]= "Firstc";
	char	kod[]= "Se";
	printf("%lu", ft_strlcpy(kad, kod, 6));
	return (0);
}*/