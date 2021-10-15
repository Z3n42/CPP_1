/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:35:35 by ecorreia          #+#    #+#             */
/*   Updated: 2021/06/29 19:53:18 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	int		index;
	char	*str;

	index = 0;
	size = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	while (index < size)
	{
		str[index] = s[index];
		index++;
	}
	return (str);
}
