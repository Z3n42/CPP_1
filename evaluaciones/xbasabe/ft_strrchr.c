/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:18:22 by xbasabe-          #+#    #+#             */
/*   Updated: 2021/06/14 09:55:23 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str);

char	*ft_strrchr(const char *s, int c)
{
	char	*cstr;

	cstr = (char *)s;
	cstr = cstr + ft_strlen(cstr);
	while (cstr >= s)
	{
		if (*cstr == c)
			return (cstr);
		cstr--;
	}
	return (NULL);
}
