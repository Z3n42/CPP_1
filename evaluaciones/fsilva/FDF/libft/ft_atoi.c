/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:57:05 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/31 22:09:54 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_strtol(const char *str, int base);
static int		ft_isspace(int c);
static long int	ft_atoi_get_number(const char *str, int sign[2], \
				int base, size_t i);
static void		ft_check_sign_atoi(char c, int *sign);

int	ft_atoi(const char *str)
{
	int	result;

	result = (int)ft_strtol(str, 10);
	return (result);
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
		if (ft_isspace((int)str[i]) && sign[0] == 0)
		{
		}
		else if ((str[i] == '+' || str[i] == '-') && sign[0] == 0)
			ft_check_sign_atoi(str[i], sign);
		else if (str[i] >= 48 && str[i] < 58)
			return (ft_atoi_get_number(str, sign, base, i));
		else
			return (0);
		i++;
	}
	return (0);
}

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
	while (str[i] >= 48 && str[i] < 58)
	{
		num = num * base;
		num = num + (str[i] - 48);
		i++;
	}
	if (sign[1] == -1)
		num = num * -1;
	return (num);
}

static int	ft_isspace(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if ((uc >= 9 && uc < 14) || uc == 32)
		return (1);
	return (0);
}
