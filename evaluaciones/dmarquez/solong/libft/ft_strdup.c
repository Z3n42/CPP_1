/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:17:53 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:59:55 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	pos;
	char	*str;

	pos = 0;
	size = ft_strlen(s1);
	str = (char *)malloc(size + 1);
	if (str == 0)
		return (0);
	while (s1[pos] != '\0')
	{
		str[pos] = s1[pos];
		pos++;
	}
	str[pos] = '\0';
	return (str);
}
