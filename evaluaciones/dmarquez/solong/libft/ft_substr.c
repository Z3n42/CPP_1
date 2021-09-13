/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:50:40 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 11:00:33 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	size_t	pos;
	char	*str;

	pos = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		str = (char *)malloc(1);
	else
		str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	while (s[start] != '\0' && pos < len && start < ft_strlen(s))
		str[pos++] = s[start++];
	str[pos] = '\0';
	return (str);
}
