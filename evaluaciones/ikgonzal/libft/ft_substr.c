/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:28:06 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/07/05 17:19:24 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	size_t			k;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	substring = (char *) malloc(sizeof (char) * len + 1);
	if (!substring)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (substring);
	k = 0;
	while (s[start] != '\0' && k < len)
	{
		substring[k] = s[start];
		k++;
		start++;
	}
	substring[k] = '\0';
	return (substring);
}
