/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:23:01 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:29:36 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	i = -1;
	tmp_dst = dst;
	tmp_src = src;
	while (++i < n && tmp_src[i] != (unsigned char)c)
		tmp_dst[i] = tmp_src[i];
	if (i == n)
		return (0);
	else
	{
		tmp_dst[i] = tmp_src[i];
		i++;
		return (&tmp_dst[i]);
	}
}
