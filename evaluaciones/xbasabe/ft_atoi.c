/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:32:02 by xbasabe-          #+#    #+#             */
/*   Updated: 2021/06/16 10:38:25 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	unsigned long long	i;
	long int			negative;

	num = 0;
	negative = 1;
	i = 9223372036854775807;
	while (*str <= ' ' || *str == 127 )
		if (*str++ == '\e')
			return (0);
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			negative *= -1;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*(str++) - '0');
	if (num > i)
	{
		num = -1;
		if (negative == -1 && num != i++)
			num = 0;
	}
	return (num * negative);
}
