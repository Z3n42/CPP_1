/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlibano- <nlibano-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:16:08 by nlibano-          #+#    #+#             */
/*   Updated: 2021/10/26 19:17:36 by nlibano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
	}
	if (c == 0)
		return (&str[i]);
	return (0);
}
