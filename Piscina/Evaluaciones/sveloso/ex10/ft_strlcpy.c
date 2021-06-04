/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sveloso- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:40:45 by sveloso-          #+#    #+#             */
/*   Updated: 2021/04/29 20:36:15 by sveloso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	lng;
	unsigned int	pos;

	lng = 0;
	pos = 0;
	while (src[lng] != '\0')
		lng++;
	if (size != 0)
	{
		while (src[pos] != '\0' && pos < (size - 1))
		{
			dest[pos] = src[pos];
			pos++;
		}
		dest[pos] = '\0';
	}
	return (lng);
}
