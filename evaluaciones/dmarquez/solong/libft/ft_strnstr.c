/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:04:17 by dmarquez          #+#    #+#             */
/*   Updated: 2021/06/03 11:12:50 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[a] != '\0')
	{
		b = 0;
		while (haystack[a + b] == needle[b] && (a + b) < len)
		{
			if (haystack[a + b] == '\0' && needle[b] == '\0')
			{
				return ((char *)&haystack[a]);
			}
			b++;
		}
		if (needle[b] == '\0')
		{
			return ((char *)haystack + a);
		}
		a++;
	}
	return (0);
}
