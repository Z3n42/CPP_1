/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:08:21 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:08:22 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_white_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12
		|| str[i] == 13 || str[i] == 11)
		i++;
	return (i);
}

int	final_result (unsigned long long num, int np)
{
	unsigned long long	i;

	i = 9223372036854775807;
	if (num > i)
	{
		if (np == -1 && num != i++)
			num = 0;
		else
		{
			num = -1;
		}
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	unsigned long long	i;
	int					np;

	np = 1;
	i = is_white_space(str);
	num = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num = final_result(num, np);
	return ((int)(np * num));
}
