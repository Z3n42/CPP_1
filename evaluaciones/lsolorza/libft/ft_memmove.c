/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:03:18 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:03:26 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *str, size_t len)
{
	unsigned const char	*s;
	unsigned char		*d;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned const char *)str;
	if (s == NULL && d == NULL)
		return (NULL);
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
		ft_memcpy(dest, str, len);
	return (dest);
}
