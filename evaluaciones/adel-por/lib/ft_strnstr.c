/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 13:01:32 by adel-por          #+#    #+#             */
/*   Updated: 2021/06/30 17:58:40 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		k = 0;
		while (haystack[i + k] == needle[k])
		{
			if (i + k < len && needle[k + 1] == '\0')
				return ((char *)&haystack[i]);
			k++;
		}
		i++;
	}
	return (NULL);
}
