/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:10:57 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:10:58 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(*dst) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	while (s1[x])
	{
		dst[x] = s1[x];
		x++;
	}
	while (s2[y])
	{
		dst[x] = s2[y];
		x++;
		y++;
	}
	dst[x] = '\0';
	return (dst);
}
