/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 20:24:19 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:29:36 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		start;
	int		end;
	char	*ptr;

	if (!s1)
		return (0);
	len = -1;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (++len < ft_strlen(s1) && !ft_check_char(s1[start], set))
		start++;
	while (end && !ft_check_char(s1[end], set))
		end--;
	if (end < start)
		ptr = ft_strdup("");
	else
		ptr = ft_substr(s1, start, end - start + 1);
	return (ptr);
}
