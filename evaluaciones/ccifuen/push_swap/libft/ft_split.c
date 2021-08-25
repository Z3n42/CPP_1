/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:48:50 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/11 09:13:05 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_count_m(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			i ++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

char	**ft_free(char **p, size_t count)
{
	size_t	i;

	if (p)
	{
		i = 0;
		while (i < count)
		{
			if (p[i] != NULL)
				free(p[i]);
			i++;
		}
		free (p);
	}
	return (0);
}

static char	*ft_fill(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	**ft_fill_m(char const *s, char c, char **ptr)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			ptr[i] = ft_fill(s, c);
			if (!ptr[i])
				return (ft_free(ptr, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	ptr[i] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		m_size;
	char	**ptr;

	if (!s)
		return (0);
	m_size = ft_count_m(s, c);
	ptr = (char **) malloc((m_size + 1) * sizeof(char *));
	if (!ptr)
		return (0);
	ptr = ft_fill_m(s, c, ptr);
	return (ptr);
}
