/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:28:06 by iibanez-          #+#    #+#             */
/*   Updated: 2021/07/19 16:20:10 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	t_len;
	size_t	i;
	char	*dst;

	if (!s)
		return (NULL);
	t_len = ft_strlen(s);
	if (t_len == 0)
		return (NULL);
	dst = malloc (sizeof(char) * (len) + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while ((i < t_len) && (i < len) \
		&& (s[start + i] != '\0') && (start < t_len))
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
