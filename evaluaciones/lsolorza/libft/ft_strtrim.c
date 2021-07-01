/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:12:43 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:12:49 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new;
	int			i;
	size_t		x;
	size_t		y;

	i = 0;
	y = ft_strlen(s1) + (ft_strlen(s1) * 2);
	new = (char *)malloc(sizeof(*s1) * y);
	if (new == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	x = ft_strlen(s1);
	while (x && ft_strchr(set, s1[x]))
		x--;
	new = ft_substr((char *)s1, '\0', x + 1);
	return (new);
}
