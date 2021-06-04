/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:23:39 by jsmith            #+#    #+#             */
/*   Updated: 2021/06/02 19:43:16 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**free_malloc(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		++i;
	}
	free(str);
	return (0);
}

static unsigned int	count_size(char *s, char c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c)
			++s;
		if (!*s)
			break ;
		while (*s && *s != c)
			++s;
		++i;
	}
	return (i);
}

static char	*split_word(char *diff, int num)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (num + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < num)
	{
		ptr[i] = diff[i];
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	char			*start;
	unsigned int	word_size;
	unsigned int	i;

	word_size = count_size((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (word_size + 1));
	if (!str || !s || !c)
		return (NULL);
	i = 0;
	while (i < word_size)
	{
		while (*s == c)
			++s;
		start = (char *)s;
		while (*s != c && *s)
			++s;
		str[i] = split_word(start, s - start);
		if (!str[i])
			return (free_malloc(str));
		++i;
	}
	str[i] = 0;
	return (str);
}
