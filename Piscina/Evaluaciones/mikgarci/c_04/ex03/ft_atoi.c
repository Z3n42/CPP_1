/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:18:56 by mikgarci          #+#    #+#             */
/*   Updated: 2021/05/06 20:11:35 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *s)
{
	int	cont;
	int	i;
	int	a;
	int	neg;

	cont = 0;
	i = 0;
	while (s[i] == ' ' || (s[1] >= 9 && s[1] <= 13))
		i++;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			cont++;
		i++;
	}
	neg = 1;
	if ((cont % 2) != 0)
		neg = -1;
	a = 0;
	while ('0' <= s[i] && s[i] <= '9')
	{
		a = (s[i] - '0') + (10 * a);
		i++;
	}
	return (a * neg);
}

int	ft_atoi(char *str);

int	main(void)
{
	char	*str;

	str = "   ---+--+1234ab567";
	printf("%d", ft_atoi(str));
}
