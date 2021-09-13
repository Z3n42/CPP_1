/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:55:26 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 11:01:54 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			pos;
	unsigned char	*a;

	pos = 0;
	a = (unsigned char *)s;
	while (pos < n)
	{
		if (a[pos] == (unsigned char)c)
			return ((unsigned char *)&s[pos]);
		pos++;
	}
	return (0);
}
