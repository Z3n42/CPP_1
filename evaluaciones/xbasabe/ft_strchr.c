/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:45:34 by xbasabe-          #+#    #+#             */
/*   Updated: 2021/06/14 09:34:02 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*cstr;

	cstr = (char *)str;
	while (*cstr != c)
	{
		if (*cstr == '\0')
			return (0);
		cstr++;
	}
	return (cstr);
}
