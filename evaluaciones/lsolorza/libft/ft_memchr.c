/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:03:36 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:03:44 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	const char	*s;

	s = str;
	while (size-- != 0)
	{
		if (*s++ == c)
			return ((void *)(--s));
	}
	return (NULL);
}
