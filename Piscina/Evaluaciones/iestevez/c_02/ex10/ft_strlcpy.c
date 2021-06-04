/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:59:15 by iestevez          #+#    #+#             */
/*   Updated: 2021/05/03 17:39:38 by iestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_strcpy (char *dest, char *scr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (scr[i] != '\0')
		i++;
	if (size != 0)
	{
		while (scr[j] != '\0' && j < (size - 1))
		{
			dest[j] = scr[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (i);
}
