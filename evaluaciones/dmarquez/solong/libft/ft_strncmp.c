/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:46:25 by dmarquez          #+#    #+#             */
/*   Updated: 2021/05/31 14:37:57 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	pos;

	pos = 0;
	if (n == 0)
	{
		return (0);
	}
	while (((s1[pos] && s2[pos]) && (s1[pos] == s2[pos])) && pos < n - 1)
	{
		pos++;
	}
	return ((unsigned char)s1[pos] - (unsigned char)s2[pos]);
}
