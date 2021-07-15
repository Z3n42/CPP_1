/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillega <mvillega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:08:48 by mvillega          #+#    #+#             */
/*   Updated: 2021/06/08 15:14:41 by mvillega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* tested: OK */
char	*ft_strdup(const char *s1)
{
	char	*rtrn;
	size_t	len;

	len = ft_strlen(s1) + 1;
	rtrn = malloc(sizeof(char) * len);
	if (!rtrn)
		return (0);
	rtrn = ft_memcpy(rtrn, s1, len);
	return (rtrn);
}
