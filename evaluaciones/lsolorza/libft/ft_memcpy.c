/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:02:35 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:02:45 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *str, size_t size)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dest;
	s = (unsigned const char *)str;
	if (d == NULL && s == NULL)
		return (NULL);
	while (size--)
		d[size] = s[size];
	return ((unsigned char *)(d));
}
