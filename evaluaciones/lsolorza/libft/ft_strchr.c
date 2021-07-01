/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:05:11 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:05:21 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if (ft_strlen(str) == 0 && (char)c != '\0')
		return (NULL);
	if ((char)c == '\0')
	{
		while (*str)
			str++;
		return ((char *)(str));
	}
	else
	{
		while (*str != '\0')
		{	
			if (*str == (char)c)
				return ((char *)(str));
			str++;
		}
	}
	return (NULL);
}
