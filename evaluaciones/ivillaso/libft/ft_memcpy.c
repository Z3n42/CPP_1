/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:10:11 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:10:12 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*aux;
	unsigned char	*aux2;

	aux = dst;
	aux2 = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
		*aux++ = *aux2++;
	return (dst);
}
