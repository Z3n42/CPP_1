/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:36:11 by anagonza          #+#    #+#             */
/*   Updated: 2021/04/29 18:28:14 by anagonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{	
	unsigned int	count;
	unsigned int	pos;

	count = 0;
	while (dest[count] != '\0')
		count++;
	pos = count;
	count = 0;
	while (src[count] != '\0' && count < nb)
	{
		dest[pos] = src[count];
		pos++;
		count++;
	}
	dest[pos] = '\0';
	return (dest);
}
