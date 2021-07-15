/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillega <mvillega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:39:33 by mvillega          #+#    #+#             */
/*   Updated: 2021/06/02 18:23:09 by mvillega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* tested: working*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstchar;
	const char	*srcconstc;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	dstchar = (char *)dst;
	srcconstc = (const char *)src;
	while (n--)
		dstchar[n] = srcconstc[n];
	return (dst);
}
