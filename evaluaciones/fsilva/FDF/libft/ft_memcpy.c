/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:15:16 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/31 16:54:34 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destc;
	char	*srcc;

	i = 0;
	if (!dest && !src)
		return (NULL);
	destc = (char *)dest;
	srcc = (char *)src;
	while (i < n)
	{
		destc[i] = srcc[i];
		i++;
	}
	return ((void *)destc);
}
