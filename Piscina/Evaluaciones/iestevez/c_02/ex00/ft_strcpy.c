/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:50:52 by iestevez          #+#    #+#             */
/*   Updated: 2021/05/02 13:50:59 by iestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *scr)
{
	int	i;

	i = 0;
	while (dest[i] != '\0')
	{
		dest[i] = scr[i];
		i++;
	}
	scr[i] = '\0';
	return (dest);
}
