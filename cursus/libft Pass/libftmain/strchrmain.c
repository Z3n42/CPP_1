/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchrmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:05:46 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/06 19:51:44 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strchr(const char *str, int c);

int	main(void)
{
	printf("%s\n", "ft_strchr:");
	printf("---------------------");
	printf("\n");
	printf("%s\n", "Está:");
	printf("%s\n", ft_strchr("abcdeabcde", 'd'));
	printf("%s\n", "No está:");
	printf("%s\n", ft_strchr("abcdeabcde", 'x'));
	printf("%s\n", "Vacio:");
	printf("%s\n", ft_strchr("abcdeabcde", '\0'));
	printf("%s\n", "Está al principio:");
	printf("%s\n", ft_strchr("abbbbbbbb", 'a'));
	printf("*********************");
	printf("\n");
	printf("%s\n", "Original:");
	printf("---------------------");
	printf("\n");
	printf("%s\n", "Está:");
	printf("%s\n", strchr("abcdeabcde", 'd'));
	printf("%s\n", "No está:");
	printf("%s\n", strchr("abcdeabcde", 'x'));
	printf("%s\n", "Vacio:");
	printf("%s\n", strchr("abcdeabcde", '\0'));
	printf("%s\n", "Está al principio:");
	printf("%s\n", strchr("abbbbbbbb", 'a'));
}

