/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:16:32 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:11:04 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (0);
	if (dest_size > 0)
	{
		while (src[i] != '\0' && i < dest_size - 1)
		{
			if (src[i] != '\0')
			{
				dest[i] = src[i];
				i++;
			}
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
