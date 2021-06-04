/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerwig- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:41:07 by dgerwig-          #+#    #+#             */
/*   Updated: 2021/05/04 14:30:23 by dgerwig-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length] != 0)
	{
		length++;
	}
	return (length);
}

char	*ft_strdup(char *src)
{
	int		index;
	char	*dest;

	index = 0;
	dest = malloc((ft_strlen(src) +1) * sizeof(char));
	if (dest == NULL)
		return (0);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
