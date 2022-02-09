/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:23:57 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/07 20:09:05 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft/libft.h"
#include "fdf.h"

static void	remove_newlines(char *s, size_t s_len)
{
	size_t	i;

	i = 0;
	while (i < s_len)
	{
		if (s[i] == '\n')
			s[i] = ' ';
		i++;
	}
}

static size_t	ft_get_num_splits(char *s, char c)
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

/* get_num()
For each split it gets the part of the height or the part of the color.
height -> base 10; colors are provided in hexcolor.
Returns ints both for color and height values.
Deals with maps with only height or with both height and color.
*/
static int	get_num(const char *s, size_t *current, size_t split_len, int base)
{
	char	*split;
	int		num;

	split = (char *)malloc(split_len + 1);
	if (split == NULL)
		error_exit(3);
	ft_strlcpy(split, \
				(const char *)&s[*current - split_len], split_len + 1);
	if (base == 10)
		num = get_height(split, base);
	else
		num = get_color(split, base);
	return (num);
}

static int	ft_get_splits(const char *s, size_t *current, char c, \
							size_t base_and_slen[2])
{
	size_t	split_len;
	int		base;
	size_t	s_len;

	base = (int)base_and_slen[0];
	s_len = base_and_slen[1];
	split_len = 0;
	while (*current <= s_len)
	{
		if ((*current == 0 && s[*current] == c) || \
				(s[*current] == c && s[*current - 1] == c))
		{
		}
		else if (s[*current] == c || *current == s_len)
			return (get_num(s, current, split_len, base));
		else
			split_len++;
		*current = *current + 1;
	}
	error_exit(3);
	return (-1);
}

int	*ft_split_to_int(char *s, char c, int base)
{
	size_t	base_and_slen[2];
	size_t	num_s;
	int		*ptr;
	size_t	i;
	size_t	current;

	if (!s)
		return (NULL);
	base_and_slen[0] = (size_t)base;
	base_and_slen[1] = ft_strlen(s);
	remove_newlines(s, base_and_slen[1]);
	num_s = ft_get_num_splits((char *)s, c);
	ptr = (int *)malloc(sizeof(int) * (num_s + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[0] = num_s;
	i = 1;
	current = 0;
	while (i <= num_s)
	{
		ptr[i] = ft_get_splits(s, &current, c, base_and_slen);
		i++;
		current++;
	}
	return (ptr);
}
