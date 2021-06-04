/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuniz-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:22:58 by emuniz-m          #+#    #+#             */
/*   Updated: 2021/05/06 10:32:50 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (*s1 == '\0' || *s2 == '\0')
			break ;
		s1++;
		s2++;
		n--;
	}
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char			s1[6] = "Adioss";
	char			s2[6] = "Holaaa";
	int				comp;
	unsigned int	n;

	n = 4;
	comp = ft_strncmp(s1, s2, n);
	printf("comprobación: %d\n", comp);
}
