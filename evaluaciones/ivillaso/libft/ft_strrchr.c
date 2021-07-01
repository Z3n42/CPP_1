/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:11:16 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:11:17 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*aux;

	aux = (char *)s;
	i = 0;
	while (*aux)
	{
		i++;
		aux++;
	}
	if (*aux == c)
		return (aux);
	aux--;
	while (*aux && i-- > 0)
	{
		if (*aux == c)
			return (aux);
		aux--;
	}
	return (0);
}
