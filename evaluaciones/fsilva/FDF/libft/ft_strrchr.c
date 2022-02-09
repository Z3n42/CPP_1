/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:55:10 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/11/01 13:52:57 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		len_str;	

	ptr = (char *)s;
	len_str = ft_strlen(s) + 1;
	while (--len_str >= 0)
	{
		if (ptr[len_str] == (char)c)
			return (&ptr[len_str]);
	}
	return (0);
}
