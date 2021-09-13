/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:17:15 by dmarquez          #+#    #+#             */
/*   Updated: 2021/06/03 12:36:35 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;
	size_t	pos;

	pos = 0;
	a = (char *) dst;
	b = (char *) src;
	if (a == 0 && b == 0)
		return (0);
	while (pos < n)
	{
		a[pos] = b[pos];
		pos++;
	}
	return (dst);
}
