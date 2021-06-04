/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iechevar <iechevar@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:25:30 by iechevar          #+#    #+#             */
/*   Updated: 2021/05/06 09:42:38 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdio.h>

int	ft_strncmp (char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (i != n)
		return (s1[i] - s2[i]);
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
