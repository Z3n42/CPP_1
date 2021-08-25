/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:31:51 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:29:36 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1)
		return (0);
	i = 0;
	j = -1;
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == 0)
		return (0);
	while (++j < ft_strlen(s1))
	{
		ptr[i] = s1[j];
		i++;
	}
	j = -1;
	while (++j < ft_strlen(s2))
	{
		ptr[i] = s2[j];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
