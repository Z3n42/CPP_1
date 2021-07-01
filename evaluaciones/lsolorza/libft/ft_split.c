/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:12:57 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:13:04 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	ft_get_split(char const **s, size_t *slen, char c)
{
	int	i;

	*s += *slen;
	*slen = 0;
	i = 0;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[i])
	{
		if ((*s)[i] == c)
			return ;
		(*slen)++;
		i++;
	}
}

static void	*ft_free(char **split, int i)
{
	int	x;

	x = 0;
	if (split)
	{
		while (x < i)
		{
			free(split[x]);
			x++;
		}
		free(split);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	slen;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	words = ft_get_words(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	slen = 0;
	while (i < words)
	{
		ft_get_split(&s, &slen, c);
		split[i] = (char *)malloc(sizeof(char) * (slen + 1));
		if (split[i] == NULL)
			return (ft_free(split, i));
		ft_strlcpy(split[i], s, slen + 1);
		i++;
	}
	split[i] = NULL;
	return (split);
}
