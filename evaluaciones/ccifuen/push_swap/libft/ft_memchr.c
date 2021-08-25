/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:25:56 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:29:36 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_str;

	i = -1;
	tmp_str = (unsigned char *)str;
	while (tmp_str[++i] != 0 && i < n)
	{
		if (tmp_str[i] == (unsigned char)c)
			return (&tmp_str[i]);
	}
	if (tmp_str[i] == (unsigned char)c && i != n)
		return (&tmp_str[i]);
	return (0);
}
