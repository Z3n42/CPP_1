/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joiglesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:51:40 by joiglesi          #+#    #+#             */
/*   Updated: 2021/05/05 10:08:49 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dst_size;

	i = 0;
	while (dest[i] != '\0')
		i++;
	dst_size = i;
	j = 0;
	while (src[j] != '\0' && i < size && size > 0)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	if (size != 0)
		dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (dst_size + i + 1);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(int argc, char *argv[])
{
	unsigned int	r;

	if (argc != 4)
		return (1);
	r = ft_strlcat(argv[1], argv[2], atoi(argv[3]));
	printf("Result: %s\nreturn = %u\n", argv[1], r);

	//printf("strlcat:\n");
	//r = strlcat(argv[1], argv[2], atoi(argv[3]));
	//printf("Result: %s\nreturn = %u\n", argv[1], r);
	return (0);
}
