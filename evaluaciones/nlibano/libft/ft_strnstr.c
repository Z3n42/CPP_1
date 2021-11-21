/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlibano- <nlibano-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:21:26 by nlibano-          #+#    #+#             */
/*   Updated: 2021/10/31 13:43:45 by nlibano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	size_t	x;

	x = len;
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = -1;
	while (((char *)haystack)[++i] != '\0')
	{
		j = 0;
		while (needle[j] == ((char *)haystack)[i + j] && \
				needle[j] != '\0' && i + j < len)
			j++;
		if (needle[j] == '\0')
			return (&((char *)haystack)[i]);
	}
	return (0);
}
