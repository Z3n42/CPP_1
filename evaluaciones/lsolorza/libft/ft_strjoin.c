/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:12:20 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:12:30 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(*s1 + *s2) * (ft_strlen(s1) + ft_strlen(s2)));
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		new[j] = s2[i];
		j++;
		i++;
	}
	new[j] = '\0';
	return (new);
}
