/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillega <mvillega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:08:24 by mvillega          #+#    #+#             */
/*   Updated: 2021/06/04 19:28:34 by mvillega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* tested: working */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*rtrn;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	rtrn = malloc(sizeof(char) * total_len);
	if (!rtrn)
		return (0);
	ft_memmove(rtrn, s1, s1_len);
	ft_memmove(rtrn + s1_len, s2, s2_len);
	rtrn[total_len - 1] = '\0';
	return (rtrn);
}
