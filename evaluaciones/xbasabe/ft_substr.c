/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:49:39 by xbasabe-          #+#    #+#             */
/*   Updated: 2021/07/14 13:55:18 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lenth;
	void	*s2;

	if (s == NULL)
		return (0);
	i = 0;
	lenth = ft_strlen((char *)s);
	s2 = (char *)malloc(len * sizeof(char) + 1);
	if (s2 == NULL)
		return (NULL);
	if (start < lenth)
	{
		while ((i + start) < (start + len) && s[i] != '\0')
		{
			*(char *)(s2 + i) = *(char *)(s + i + start);
			i++;
		}
	}
	*(char *)(s2 + i) = '\0';
	return (s2);
}
