/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:31:37 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 11:00:22 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	pos;

	pos = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (pos >= 0)
	{
		if (s[pos] == (char) c)
			return ((char *)&s[pos]);
		pos--;
	}
	return (0);
}
