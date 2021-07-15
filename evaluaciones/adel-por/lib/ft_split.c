/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:55:17 by adel-por          #+#    #+#             */
/*   Updated: 2021/07/09 19:33:18 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cant_delim(char const	*s, char	c)
{
	int	lim;
	int	i;

	i = 0;
	if (s[0] && s[0] != c)
		i++;
	lim = 0;
	while (lim < (int)ft_strlen(s))
	{
		if (s[lim] == c && s[lim + 1] != c && s[lim + 1])
			i++;
		lim++;
	}
	return (i);
}

static char	*str_nolim(char const	*s, char c, int i)
{
	int		j;
	int		k;
	char	*newstr;

	j = i;
	while (s[i] && s[i] != c)
		i++;
	newstr = (char *)malloc(sizeof(char) * ((i - j) + 1));
	if (!newstr)
		return (NULL);
	k = 0;
	while (j != i)
	{
		newstr[k] = s[j];
		k++;
		j++;
	}
	newstr[k] = '\0';
	return (newstr);
}

static int	lim_check(char	*s, char	c, int i)
{
	int	j;
	int	k;

	k = 0;
	j = i;
	while (s[i] && s[i] != c)
		i++;
	while (j != i)
	{
		j++;
		k++;
	}
	return (k);
}

char	**ft_split(char const	*s, char	c)
{
	int		i;
	int		k;
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * ((cant_delim(s, c)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (i <= (int)ft_strlen(s) && cant_delim(s, c))
	{
		if (lim_check((char *)s, c, i))
		{
			str[k] = str_nolim(s, c, i);
			i += (ft_strlen(str[k]) + 1);
			k++;
		}
		else
			i++;
	}
	str[k] = NULL;
	return (str);
}
