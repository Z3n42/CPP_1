/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:49:28 by dmarquez          #+#    #+#             */
/*   Updated: 2021/06/03 12:56:14 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			pos;

	pos = 0;
	a = (unsigned char *) dst;
	b = (unsigned char *) src;
	while (pos < n)
	{
		a[pos] = b[pos];
		if (b[pos] == (unsigned char)c)
			return (((void *)&a[pos + 1]));
		pos++;
	}
	return (0);
}
