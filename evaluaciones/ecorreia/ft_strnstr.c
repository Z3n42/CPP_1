/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 19:59:35 by ecorreia          #+#    #+#             */
/*   Updated: 2021/07/02 18:28:25 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	u;

	i = 0;
	if (!find[0])
		return ((char *)str);
	while (str[i] && i < len)
	{
		u = 0;
		while (str[i + u] == find[u] && (i + u) < len)
		{
			if (find[u + 1] == 0)
				return ((char *)&str[i]);
			u++;
		}
		i++;
	}
	return (0);
}
