/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:45:06 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/27 19:06:01 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	if (destsize == 0)
		return (src_len);
	while ((i < destsize - 1) && (j < src_len))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (destsize > 0)
		dest[i] = '\0';
	if (destsize < dest_len)
		return (src_len + destsize);
	else
		return (src_len + dest_len);
}
