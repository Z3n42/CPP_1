/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:13:23 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/05/03 12:42:38 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	f;

	i = 0;
	f = 0;
	while (src[f] != '\0')
		f++;
	if (size > 0)
	{	
		while (src != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (f);
}

#include <stdio.h>

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size);

int main(void)
{
    unsigned int    size;
    char            dest[] = "Adiooooosito";
    char            src[] = "Hola";

    size = 4;
    printf("Dest in: %s", src);
    printf("Scr in: %s", dest);
    ft_strlcpy(dest, src, size);
    printf("Dest out: %s", src);
    printf("Scr out: %s", dest);
}
