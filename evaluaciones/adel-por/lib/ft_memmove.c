/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:20:43 by adel-por          #+#    #+#             */
/*   Updated: 2021/07/14 12:55:45 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void	*src, size_t len)
{
	char	*str;
	char	*spr;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	str = (char *)dst;
	spr = (char *)src;
	if (str > spr)
	{
		while (len--)
			str[len] = spr[len];
	}
	while (i < len && str < spr)
	{
		str[i] = spr[i];
		i++;
	}
	return (dst);
}
