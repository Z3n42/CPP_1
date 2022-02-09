/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:30:44 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/27 16:48:04 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destc;
	char	*srcc;

	destc = (char *)dest;
	srcc = (char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			destc[n - 1] = srcc[n - 1];
			n--;
		}
		return (destc);
	}
	else
		return (ft_memcpy(dest, (const void *)src, n));
}
