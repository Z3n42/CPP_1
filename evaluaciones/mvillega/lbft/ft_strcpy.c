/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillega <mvillega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:22:43 by mvillega          #+#    #+#             */
/*   Updated: 2021/05/28 18:45:48 by mvillega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* tested: works fine. its an extra */
char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (*(src + count) != 0)
	{
		*(dest + count) = *(src + count);
		count++;
	}
	*(dest + count) = 0;
	return (dest);
}
