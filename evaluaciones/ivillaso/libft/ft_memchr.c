/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:10:06 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:10:07 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*aux;

	aux = (char *)s;
	while (n--)
	{
		if (*aux == c)
			return (aux);
		aux++;
	}
	return (0);
}
