/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:08:59 by ecorreia          #+#    #+#             */
/*   Updated: 2021/07/01 21:09:00 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		index;
	int		i;

	index = 0;
	str = (char *)s;
	i = ft_strlen(str);
	while (index <= i)
	{
		if (str[index] == c)
			return (str + index);
		index++;
	}
	return (NULL);
}
