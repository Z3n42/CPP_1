/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:17:26 by iibanez-          #+#    #+#             */
/*   Updated: 2021/06/08 18:03:04 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	while (dst[len1] && len1 < size)
		len1++;
	while (src[len2] && (len1 + len2) < size - 1 && size > 0)
	{
		dst[len1 + len2] = src[len2];
		len2++;
	}
	if (len1 < size)
		dst[len1 + len2] = '\0';
	return (len1 + ft_strlen(src));
}
