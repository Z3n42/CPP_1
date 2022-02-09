/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:47:10 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/21 18:12:06 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str1, int c)
{
	char	c_c;
	int		i;
	char	*ptr;

	i = 0;
	c_c = (char)c;
	ptr = (char *)str1;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c_c)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == c_c)
		return (&ptr[i]);
	return (0);
}
