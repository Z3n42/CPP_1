/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:02:56 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:03:02 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *str, int c, size_t size)
{
	unsigned const char	*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned const char *)str;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i < size)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
