/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:10:53 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:33:21 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	dst = malloc((i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (j < i)
	{
		dst[j] = s1[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}
