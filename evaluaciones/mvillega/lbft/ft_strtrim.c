/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillega <mvillega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:07:12 by mvillega          #+#    #+#             */
/*   Updated: 2021/07/08 17:18:45 by mvillega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	size_t	end;
	char	*rtrn;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (isinset(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		rtrn = ft_strdup("");
		if (!rtrn)
			return (NULL);
		else
			return (rtrn);
	}
	while (isinset(s1[end - 1], set) == 0)
		end--;
	rtrn = ft_substr(s1, start, end - start);
	return (rtrn);
}
