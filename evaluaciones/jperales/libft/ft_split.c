/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:53:04 by jperales          #+#    #+#             */
/*   Updated: 2021/09/07 18:54:10 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freemem(char **str, size_t i)
{
	size_t	j;

	if (str)
	{
		j = 0;
		while (j < i)
		{
			if (str[j] != NULL)
				free (str[i]);
			i++;
		}
		free(str);
	}
	return (NULL);
}

static size_t	ft_count_str(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 1;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (count);
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

size_t	ft_len_str(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**ft_fill_str(char **dest, char const *s, char c)
{
	size_t	i;
	size_t	row;
	size_t	col;
	size_t	string_size;

	i = 0;
	row = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		col = 0;
		string_size = ft_len_str(&s[i], c);
		dest[row] = malloc((string_size + 1) * sizeof(char));
		if (!dest[row])
			return (ft_freemem(dest, row));
		while (col < string_size)
			dest[row][col++] = s[i++];
		dest[row][col] = '\0';
		row++;
	}
	dest[row] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	size;

	if (!s)
		return (0);
	if (ft_strlen(s) > 0)
	{
		size = ft_count_str(s, c);
		dest = malloc((size) * sizeof(char *));
	}
	else
		dest = malloc((0 + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	ft_fill_str(dest, s, c);
	return (dest);
}
