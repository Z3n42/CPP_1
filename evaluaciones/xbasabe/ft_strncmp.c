/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:48:15 by xbasabe-          #+#    #+#             */
/*   Updated: 2021/07/14 12:50:50 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;
	char			*cstr1;
	char			*cstr2;

	i = 0;
	cstr1 = (char *)str1;
	cstr2 = (char *)str2;
	while (cstr1[i] != '\0' && cstr2[i] != '\0' && i < n)
	{
		if (cstr1[i] != cstr2[i])
			return ((unsigned char)cstr1[i] - (unsigned char)cstr2[i]);
		++i;
	}
	if (i != n)
		return ((unsigned char)cstr1[i] - (unsigned char)cstr2[i]);
	return (0);
}
