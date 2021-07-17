/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:08:02 by ikgonzal          #+#    #+#             */
/*   Updated: 2021/07/14 17:00:07 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	where;
	char	*new;

	if (!s1)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	where = ft_strlen(s1);
	while (ft_strchr(set, s1[where]) && where)
		where--;
	new = ft_substr((char *)s1, 0, where + 1);
	return (new);
}
