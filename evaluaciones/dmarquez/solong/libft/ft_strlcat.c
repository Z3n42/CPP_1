/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:32:11 by dmarquez          #+#    #+#             */
/*   Updated: 2021/05/31 15:52:41 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lng;
	size_t	lngori;
	size_t	pos;

	lng = ft_strlen(dst);
	lngori = lng;
	pos = 0;
	while (src[pos] != '\0' && dstsize > 0 && lng < (dstsize - 1))
	{
		dst[lng] = src[pos];
		pos++;
		lng++;
	}
	if (dstsize != 0 || lngori < dstsize)
		dst[lng] = '\0';
	if (lng > (dstsize - 1) && dstsize != 0)
		return (dstsize + ft_strlen(src));
	if (dstsize != 0)
		return (lngori + ft_strlen(src));
	return (ft_strlen(src));
}
