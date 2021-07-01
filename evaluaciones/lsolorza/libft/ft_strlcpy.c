/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:04:30 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:04:37 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *str, size_t size)
{
	char		*d;
	const char	*s;
	size_t		x;

	d = dest;
	s = str;
	x = 0;
	if (d == 0 && s == 0)
		return (0);
	if (size == 0)
		return (ft_strlen(str));
	while (*s != '\0' && x < (size - 1))
	{	
		*d++ = *s++;
		x++;
	}
	*d = '\0';
	return (ft_strlen(str));
}
