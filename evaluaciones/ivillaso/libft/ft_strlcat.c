/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:10:59 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:11:00 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat (char	*dst, const char	*src, size_t	dstsize)
{
	char	*aux;
	char	*aux2;
	size_t	size_c;
	size_t	dst_length;

	aux = dst;
	aux2 = (char *)src;
	size_c = dstsize;
	while (size_c-- && *aux)
		aux++;
	dst_length = aux - dst;
	size_c = dstsize - dst_length;
	if (size_c <= 0)
		return (dst_length + ft_strlen(aux2));
	while (*aux2)
	{
		if (size_c > 1)
		{
			*aux++ = *aux2;
			size_c--;
		}
		aux2++;
	}
	*aux = 0;
	return (dst_length + (aux2 - src));
}
