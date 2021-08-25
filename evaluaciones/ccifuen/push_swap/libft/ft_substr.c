/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:21:13 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:29:36 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (0);
	i = -1;
	if (start >= (unsigned int)ft_strlen(s))
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	ptr = malloc(len + 1);
	if (ptr == 0)
		return (0);
	while (++i < len)
		ptr[i] = s[start + i];
	ptr[i] = 0;
	return (ptr);
}
