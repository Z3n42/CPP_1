/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzeromain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:11:37 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/04 17:43:31 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    char str1[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore bzero(): %s\n", str);
    printf("\nBefore ft_bzero(): %s\n", str1);
    bzero(str + 8, 4 * sizeof(char));
    ft_bzero(str1 + 8, 4 * sizeof(char));
    printf("\nAfter bzero(): %s\n", str);
    printf("\nAfter ft_bzero(): %s\n", str1);
    return (0);
	/*	size_t	n;
	char 	s[] = "abcde";

	n = 3;
	printf("FT : %d\n", ft_bzero(s, n));
	printf("FT : %s\n", bzero(s, n));*/
}

