/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 19:45:04 by ecorreia          #+#    #+#             */
/*   Updated: 2021/06/29 19:31:46 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	char	*str;

	str = (char *)s;
	index = 0;
	if (!n)
		return (NULL);
	while (index < n)
	{
		if (str[index] == c)
		{
			return (str + index);
		}
		index++;
	}
	return (NULL);
}
