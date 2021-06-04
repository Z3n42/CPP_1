/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liturreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:50:30 by liturreg          #+#    #+#             */
/*   Updated: 2021/05/03 14:35:23 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
		if (*s1++ == '\0')
			break ;
		n--;
	}
	return (0);
}

#include  <stdio.h>

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
