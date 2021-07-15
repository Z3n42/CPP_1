/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillega <mvillega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:02:46 by mvillega          #+#    #+#             */
/*   Updated: 2021/07/08 17:02:50 by mvillega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **p, size_t count)
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
	return (NULL);
}

size_t	ft_count_size(const char	*s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}	
	}
	return (i);
}

static char	*ft_fill_each_pointer(char const *s, char c)
{
	char	*pnt;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	pnt = (char *) malloc((i + 1) * sizeof(char));
	if (!pnt)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		pnt[i] = s[i];
		i++;
	}
	pnt[i] = '\0';
	return (pnt);
}

static char	**ft_fill_pointers(char const *s, char c, char **tab)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			tab[i] = ft_fill_each_pointer(s, c);
			if (!tab[i])
				return (ft_free(tab, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	int		size;
	char	**tab;

	if (!str)
		return (NULL);
	size = ft_count_size(str, c);
	tab = malloc ((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_fill_pointers(str, c, tab);
	return (tab);
}
