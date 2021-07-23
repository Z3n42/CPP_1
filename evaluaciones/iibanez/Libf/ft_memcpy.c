/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:09:04 by iibanez-          #+#    #+#             */
/*   Updated: 2021/06/07 19:01:45 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	unsigned int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest1 = (unsigned char *) dest;
	src1 = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		*((char *)dest1 + i) = *((char *)src1 + i);
		i++;
	}
	return (dest1);
}
