/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:44:42 by dmarquez          #+#    #+#             */
/*   Updated: 2021/06/07 14:58:19 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	pos;
	size_t	pos2;
	size_t	len;
	char	*str;

	pos = 0;
	pos2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[pos] != '\0')
	{
		str[pos] = s1[pos];
		pos++;
	}
	while (s2[pos2] != '\0')
		str[pos++] = s2[pos2++];
	str[pos] = '\0';
	return (str);
}
