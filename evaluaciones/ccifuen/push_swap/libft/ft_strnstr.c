/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:00:38 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:29:36 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t l)
{
	size_t	i;
	int		j;
	int		a;

	i = -1;
	while (h[++i] && i < l)
	{
		j = -1;
		a = -2;
		while (n[++j] != 0)
		{
			a = 0;
			if (h[j + i] != n[j] || (i + j) >= l)
			{
				a = -1;
				break ;
			}
		}
		if (a == 0)
			return ((char *)&(h[i]));
	}
	if (a != -2 && ft_strlen(n) != 0)
		return (0);
	return ((char *)&(h[0]));
}
