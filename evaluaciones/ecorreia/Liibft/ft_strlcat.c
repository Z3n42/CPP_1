/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:58:21 by ecorreia          #+#    #+#             */
/*   Updated: 2021/07/02 17:51:51 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	u;
	size_t	index;

	index = 0;
	i = ft_strlen(dst);
	u = 0;
	while (src[u])
		u++;
	if (dstsize <= i)
		u = u + dstsize;
	else
		u = u + i;
	while (src[index] && i + 1 < dstsize)
		dst[i++] = src[index++];
	dst[i] = '\0';
	return (u);
}
