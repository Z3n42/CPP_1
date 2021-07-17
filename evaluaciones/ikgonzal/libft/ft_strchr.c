/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:56:10 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/07/15 17:47:21 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		len;

	len = ft_strlen(s);
	c = (char)c;
	str = ((char *)s);
	i = 0;
	if (!*str && !c)
	{
		*str = c;
		return (str);
	}
	while (str[i] != '\0')
	{
		if (c == '\0')
			return (str + len);
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}
