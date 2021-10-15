/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:46:26 by ecorreia          #+#    #+#             */
/*   Updated: 2021/06/29 19:21:16 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			index;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	index = 0;
	while (str[index] && str2[index] != '\0' && index < n)
	{
		if (str[index] != str2[index])
			return (str[index] - str2[index]);
		index++;
	}
	if (index != n)
		return (str[index] - str2[index]);
	return (0);
}
