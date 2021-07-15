/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:48:32 by xbasabe-          #+#    #+#             */
/*   Updated: 2021/06/16 12:40:16 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *search, size_t len)
{
	size_t	i;
	size_t	j;

	if (*search == '\0')
		return ((char *)str);
	i = 0;
	j = 0;
	while (1)
	{
		if (search[j] == 0)
			return ((char *)(str + (i - j)));
		if (str[i] == search[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		if (str[i] == '\0' || i >= len)
			return (NULL);
		i++;
	}
}
