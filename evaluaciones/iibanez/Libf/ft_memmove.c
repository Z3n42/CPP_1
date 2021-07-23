/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:20:50 by iibanez-          #+#    #+#             */
/*   Updated: 2021/06/08 18:19:25 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src1;
	unsigned char	*dest1;
	size_t			i;

	src1 = (unsigned char *) src;
	dest1 = (unsigned char *) dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest1 > src1)
	{
		while (n-- > 0)
			dest1[n] = src1[n];
	}
	else
	{
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	return (dest1);
}
