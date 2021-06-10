/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:19:29 by ccifuent          #+#    #+#             */
/*   Updated: 2021/06/08 12:38:43 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(s1) + 1;
	ptr = malloc(len);
	if (ptr == 0)
		return (0);
	while (++i < len)
		ptr[i] = s1[i];
	ptr[i] = 0;
	return (ptr);
}
