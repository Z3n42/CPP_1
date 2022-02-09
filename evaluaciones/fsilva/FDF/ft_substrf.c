/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:19:06 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/02 18:16:55 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdlib.h>

static size_t	ft_check_len(size_t len, unsigned int start, const char *s);

char	*ft_substrf(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_check_len(len, start, s);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	free(s);
	return (ptr);
}

static size_t	ft_check_len(size_t len, unsigned int start, const char *s)
{
	int	leni;
	int	starti;
	int	s_len;

	s_len = (int)ft_strlen(s);
	starti = (int)start;
	leni = (int)len;
	if (s_len - starti < leni)
	{
		if (s_len - starti < 0)
			leni = 0;
		else
			leni = s_len - start;
	}
	return ((size_t)leni);
}
