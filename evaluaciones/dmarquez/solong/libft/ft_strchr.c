/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:31:41 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:59:26 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	pos;

	pos = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[pos] != '\0')
	{
		if (s[pos] == (char) c)
			return ((char *)&s[pos]);
		pos++;
	}
	return (0);
}
