/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:05:32 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:05:42 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	while (s >= str)
	{
		if (*s == (unsigned char)c)
			return ((char *)(s));
		s--;
	}
	return (0);
}
