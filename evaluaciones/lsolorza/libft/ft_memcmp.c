/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:03:54 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:04:02 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	const char	*d1;
	const char	*d2;
	int			i;
	int			x;

	d1 = s1;
	d2 = s2;
	i = 0;
	x = 0;
	while (size-- != 0)
	{
		if (d1[i] != d2[i])
		{
			x = (unsigned char)d1[i] - (unsigned char)d2[i];
			break ;
		}
		i++;
	}
	return (x);
}
