/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:45:37 by jperales          #+#    #+#             */
/*   Updated: 2021/08/31 13:21:27 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;

	mem = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!mem)
		return (0);
	return (ft_memcpy(mem, s1, ft_strlen(s1) + 1));
}
