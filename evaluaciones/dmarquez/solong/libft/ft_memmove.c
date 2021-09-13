/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:06:26 by dmarquez          #+#    #+#             */
/*   Updated: 2021/06/03 16:47:53 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) dst;
	b = (unsigned char *) src;
	if (src < dst)
	{
		while (len > 0)
		{
			len--;
			a[len] = b[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
