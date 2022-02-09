/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:57:02 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/31 22:20:01 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_same(char *hay, char *ned, size_t i, size_t len);

char	*ft_strnstr(const char *haystack, const char *neddle, size_t len)
{
	char	*hay;
	char	*ned;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	hay = (char *)haystack;
	ned = (char *)neddle;
	if (ned[j] == '\0')
		return (&hay[i]);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		if (hay[i] == ned[j])
		{
			if (ft_check_same(hay, ned, i, len))
				return (&hay[i]);
		}
		i++;
	}
	return (NULL);
}

static int	ft_check_same(char *hay, char *ned, size_t i, size_t len)
{
	size_t	j;
	size_t	ned_len;

	j = 0;
	ned_len = ft_strlen(ned);
	while (ned[j] == hay[i] && (hay[i] != '\0'))
	{
		if (i >= len)
			return (0);
		if (j >= ned_len - 1)
			return (1);
		i++;
		j++;
	}
	return (0);
}
