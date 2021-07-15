/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:46:11 by xbasabe-          #+#    #+#             */
/*   Updated: 2021/06/10 12:14:55 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	while (dst[i] && i < size)
		i++;
	count = 0;
	while (i + 1 < size && src[count])
	{
		dst[i] = src [count];
		i++;
		count++;
	}
	if (size > i)
		dst[i] = '\0';
	return (ft_strlen((char *)src) + (i - count));
}
