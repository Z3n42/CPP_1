/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:10:03 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:10:04 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*aux;
	char	*aux2;
	size_t	i;

	i = 0;
	aux = dst;
	aux2 = (char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		aux[i] = aux2[i];
		if (aux[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
