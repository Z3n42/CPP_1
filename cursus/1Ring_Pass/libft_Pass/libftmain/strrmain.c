/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:19:04 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/01 19:11:19 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strrchr(const char *str, int c);

int	main(void)
{
	printf("%s\n", "ft_strrchr:");
	printf("---------------------");
	printf("\n");
	printf("%s\n", "Está:");
	printf("%s\n", ft_strrchr("abcdeabcde", 'a'));
	printf("%s\n", "No está:");
	printf("%s\n", ft_strrchr("abcdeabcde", 'x'));
	printf("%s\n", "Vacio:");
	printf("%s\n", ft_strrchr("abcdeabcde", '\0'));
	printf("%s\n", "Está al principio:");
	printf("%s\n", ft_strrchr("abbbbbbbb", 'a'));
	printf("*********************");
	printf("\n");
	printf("%s\n", "Original:");
	printf("---------------------");
	printf("\n");
	printf("%s\n", "Está:");
	printf("%s\n", strrchr("abcdeabcde", 'a'));
	printf("%s\n", "No está:");
	printf("%s\n", strrchr("abcdeabcde", 'x'));
	printf("%s\n", "Vacio:");
	printf("%s\n", strrchr("abcdeabcde", '\0'));
	printf("%s\n", "Está al principio:");
	printf("%s\n", strrchr("abbbbbbbb", 'a'));
}
