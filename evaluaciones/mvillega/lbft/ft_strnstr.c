/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillega <mvillega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:31:17 by mvillega          #+#    #+#             */
/*   Updated: 2021/07/08 15:28:05 by mvillega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	size_t	i;
	size_t	needle_len;
	char	*stack;

	i = 0;
	stack = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (needle_len == 0 || haystack == needle)
		return (stack);
	while (stack[i] != '\0' && i < len)
	{
		c = 0;
		while (stack[i + c] != '\0' && needle[c]
			!= '\0' && stack[i + c] == needle[c] && i + c < len)
			c++;
		if (c == needle_len)
			return (stack + i);
		i++;
	}
	return (0);
}
