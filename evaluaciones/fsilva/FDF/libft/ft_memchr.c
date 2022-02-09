/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:12:32 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/21 18:16:49 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	c_c;
	size_t			i;
	char			*strc;

	c_c = (unsigned char)c;
	i = 0;
	strc = (char *)str;
	while (i < n)
	{
		if ((unsigned char)strc[i] == c_c)
			return ((void *)&strc[i]);
		i++;
	}
	return (0);
}
