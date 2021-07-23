/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:57:03 by iibanez-          #+#    #+#             */
/*   Updated: 2021/07/01 18:27:34 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*dest;
	size_t	init_len;

	if (!s1)
		return (NULL);
	init_len = ft_strlen(s1);
	if (!s1 || !set)
		return ((char *)s1);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	if (*s1 != '\0')
	{
		size = ft_strlen(s1);
		while (size && ft_strchr(set, s1[size]))
			size--;
		dest = ft_substr((char *)s1, 0, size + 1);
		return (dest);
	}
	dest = malloc(sizeof(char *) * 1);
	if (dest == NULL)
		return (NULL);
	dest[0] = '\0';
	return (dest);
}
