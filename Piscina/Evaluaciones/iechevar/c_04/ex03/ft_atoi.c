/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iechevar <iechevar@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:10:10 by iechevar          #+#    #+#             */
/*   Updated: 2021/05/06 10:06:48 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_odd (int	i)
{
	if (i % 2 == 0)
		return (1);
	else
		return (-1);
}

int	ft_numeric (char str)
{
	if (str >= '0' && str <= '9')
		return (3);
	else if (str == '-')
		return (2);
	else if (str == ' ' || str == '+' || str == '\f')
		return (1);
	else if (str == '\n' || str == '\r' || str == '\t' || str == '\v')
		return (1);
	else
		return (4);
}

int	ft_atoi (char *str)
{
	int	i;
	int	count;
	int	num;

	i = 0;
	count = 0;
	num = 0;
	while (str[i] != 0 && ft_numeric (str[i]) <= 3)
	{
		if (ft_numeric (str[i]) == 2)
			count++;
		if (ft_numeric (str[i]) == 3)
		{
			num = num * 10 + (str[i] - 48);
		}
		i++;
	}
	return (num * ft_odd (count));
}



int	ft_atoi(char *str);

int	main(void)
{
	char	*str;

	str = "   ---+--+1234ab567";
	printf("%d", ft_atoi(str));
}
