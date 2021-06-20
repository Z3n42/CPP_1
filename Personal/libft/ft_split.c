/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:35:30 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/20 18:59:40 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(char const *s, char c)
{
	int	counter;
	int	pos;

	counter = 0;
	pos = 0;
	while (s[counter])
	{
		if (s[counter] == c && s[counter + 1] != c)
			pos++;
		counter++;
	}
	return (pos + 1);
}

static void	*ft_free(char **tab, int pos)
{
	while (tab[--pos])
		free (tab[pos]);
	free (tab);
	return (NULL);
}

static char	**ft_instr(char **tab, char *str, char c)
{
	int	count;
	int	len;
	int	pos;

	pos = 0;
	len = 0;
	count = -1;
	while (str[++count])
	{
		if (str[count] != c)
		{
			len++;
			if (str[count + 1] == c || str[count + 1] == '\0')
			{
				tab[pos] = ft_substr(str, (count - len) + 1, len);
				if (!tab[pos])
					return (ft_free(tab, pos));
				pos++;
				len = 0;
			}
		}
	}
	tab[pos] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	*set;
	char	**tab;
	int		pos;

	if (!s)
		return (NULL);
	set = &c;
	str = ft_strtrim(s, set);
	if (!str)
		return (NULL);
	pos = ft_count(str, c);
	tab = (char **)malloc((pos + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (ft_instr(tab, str, c));
}
