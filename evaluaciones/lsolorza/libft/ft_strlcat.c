/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:04:48 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:05:00 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t size)
{
	const char	*s;
	char		*d;
	size_t		flen;
	size_t		diff;

	s = str;
	d = dest;
	diff = size;
	while (diff-- != 0 && *d != '\0')
		d++;
	flen = d - dest;
	diff = size - flen;
	if (diff == 0)
		return (flen + ft_strlen(str));
	while (*str != '\0')
	{
		if (diff > 1)
		{
			*d++ = *str;
			diff--;
		}
		str++;
	}
	*d = '\0';
	return (flen + (str - s));
}
