/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joiglesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:37:12 by joiglesi          #+#    #+#             */
/*   Updated: 2021/05/05 10:04:46 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	if (s1[i] > s2[i])
		return (s1[i] - s2[i]);
	if (s1[i] < s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

#include  <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

int main(void)
{
    char            s1[6] = "Adioss";
    char            s2[6] = "Holaaa";
    int             comp;
    unsigned int    n;

    n = 4;
    comp = ft_strncmp(s1, s2, n);
    printf("comprobación: %d\n", comp);
}
