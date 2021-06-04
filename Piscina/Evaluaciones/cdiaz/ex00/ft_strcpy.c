/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:41:42 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/05/03 12:35:03 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	dest[] = "Adio";
	char	src[5] = "Hola";

	printf("Dest in: %s", src);
	printf("Scr in: %s", dest);
	ft_strcpy(dest, src);
	printf("Dest out: %s", src);
	printf("Scr out: %s", dest);
}
