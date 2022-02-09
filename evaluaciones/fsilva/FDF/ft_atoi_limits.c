/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:57:05 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/07 20:08:16 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Same ft_atoi as in libft but:
 a) exits using error_exit() if the number is outside
 the integer limits or if it is malformed
 b) only allows spaces (no tabs, returns...')
 */
static void	ft_check_sign_atoi(char c, int *sign)
{
	sign[0] = 1;
	if (c == '-')
		sign[1] = -1;
}

static long int	ft_atoi_get_number(const char *str, int sign[2], \
				int base, size_t i)
{
	long int	num;

	num = 0;
	while (str[i] >= 48 && str[i] < 71)
	{
		num = num * base;
		num = num + (str[i] - 48);
		i++;
	}
	if (sign[1] == -1)
		num = num * -1;
	if (num < -2147483648 || num > 2147483647)
		error_exit(2);
	return (num);
}

static long int	ft_strtol(const char *str, int base)
{
	size_t		i;
	int			sign[2];

	i = 0;
	sign[0] = 0;
	sign[1] = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && sign[0] == 0)
		{
		}
		else if ((str[i] == '+' || str[i] == '-') && sign[0] == 0)
			ft_check_sign_atoi(str[i], sign);
		else if (str[i] >= 48 && str[i] < 71)
			return (ft_atoi_get_number(str, sign, base, i));
		else
			error_exit(2);
		i++;
	}
	error_exit(2);
	return (0);
}

int	ft_atoi_limits(const char *str, int base)
{
	int	result;

	result = (int)ft_strtol(str, base);
	return (result);
}
