/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:42:23 by dmarquez          #+#    #+#             */
/*   Updated: 2021/06/08 11:42:23 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_istrim(char c, char const	*set)
{
	while (*set && *set != c)
		set++;
	if (*set)
		return (1);
	return (0);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_istrim(s1[start], set))
		start++;
	while (ft_istrim(s1[end], set))
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
