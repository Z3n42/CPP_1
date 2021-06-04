/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:29:40 by jsmith            #+#    #+#             */
/*   Updated: 2021/06/02 19:19:24 by jsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*pnt;

	i = 0;
	while (s[i] != '\0')
		i++;
	pnt = malloc(sizeof(char) * i);
	if (!pnt)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		pnt[i] = s[i];
		i++;
	}
	pnt[i] = '\0';
	return (pnt);
}
