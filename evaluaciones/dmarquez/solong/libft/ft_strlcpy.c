/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:18:25 by dmarquez          #+#    #+#             */
/*   Updated: 2021/06/04 15:22:47 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	pos;

	pos = 0;
	if (!dst && !src)
		return (0);
	while (src[pos] != '\0' && dstsize > 0 && pos < (dstsize - 1))
	{
		dst[pos] = src[pos];
		pos++;
	}
	if (dstsize != 0)
		dst[pos] = '\0';
	return (ft_strlen(src));
}
