/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:43:10 by anagonza          #+#    #+#             */
/*   Updated: 2021/04/29 18:27:01 by anagonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	count;
	int	pos;

	count = 0;
	while (dest[count] != '\0')
		count++;
	pos = count;
	count = 0;
	while (src[count] != '\0')
	{
		dest[pos] = src[count];
		pos++;
		count++;
	}
	dest[pos] = '\0';
	return (dest);
}
