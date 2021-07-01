/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:11:13 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:11:14 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*aux;
	unsigned int	i;
	size_t			j;

	aux = (char *)haystack;
	j = 0;
	if (*needle == 0)
		return (aux);
	while (*aux && j <= len)
	{	
		i = 0;
		while (aux[i] == needle[i])
		{
			if (i + 1 == ft_strlen(needle) && j + i < len)
				return (aux);
			i++;
		}
		aux++;
		j++;
	}
	return (0);
}
