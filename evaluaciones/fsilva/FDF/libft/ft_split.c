/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:23:57 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/31 17:24:41 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_num_splits(char *s, char c);
char	*ft_get_splits(const char *s, size_t *current, char c, size_t s_len);

char	**ft_split(const char *s, char c)
{
	size_t	s_len;
	size_t	num_s;
	char	**ptr;
	size_t	i;
	size_t	current;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	num_s = ft_get_num_splits((char *)s, c);
	ptr = malloc(sizeof(char *) * (num_s + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	current = 0;
	while (i < num_s)
	{
		ptr[i] = ft_get_splits(s, &current, c, s_len);
		if (ptr[i] == NULL && i != 0)
			return (NULL);
		i++;
		current++;
	}
	ptr[num_s] = NULL;
	return (ptr);
}

size_t	ft_get_num_splits(char *s, char c)
{
	size_t	num_s;
	size_t	i;
	size_t	split_on;

	i = 0;
	num_s = 0;
	split_on = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && split_on == 0)
		{
			num_s++;
			split_on = 1;
		}
		else if (s[i] == c && split_on == 1)
			split_on = 0;
		i++;
	}
	return (num_s);
}

char	*ft_get_splits(const char *s, size_t *current, char c, size_t s_len)
{
	char	*split;
	size_t	split_len;

	split_len = 0;
	while (*current <= s_len)
	{
		if ((*current == 0 && s[*current] == c) || \
				(s[*current] == c && s[*current - 1] == c))
		{
		}
		else if (s[*current] == c || *current == s_len)
		{
			split = (char *)malloc(split_len + 1);
			if (split == NULL)
				return (NULL);
			ft_strlcpy(split, \
					(const char *)&s[*current - split_len], split_len + 1);
			return (split);
		}
		else
			split_len++;
		*current = *current + 1;
	}
	return (NULL);
}
