/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:10:09 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:10:10 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp (const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux;
	unsigned char	*aux2;

	aux = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (n--)
	{
		if (*aux++ != *aux2++)
			return (*(aux - 1) - *(aux2 - 1));
	}
	return (0);
}
