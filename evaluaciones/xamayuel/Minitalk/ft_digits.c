/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:41:10 by xamayuel          #+#    #+#             */
/*   Updated: 2022/03/22 20:49:10 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putnbr_positive(int n, int fd);
static int	ft_check_over_long(int sign, unsigned long long int number);
/**
 * NAME: ft_atoi()
 * 
 * DESCRIPTION:
 * 		Converts the initial portion of the string to integer
 * 
 * RETURN VALUE:
 *		The int value (if exists) of converted string.
 *
 * TIPS:
 * 		1. - check spaces
 * 		2. - check + and -. If else if
 * 		3. - while number, *10 + number
 * 
 */

int	ft_atoi(const char *str)
{
	int						sign;
	unsigned long long int	number;
	int						count;

	count = 0;
	sign = 1;
	number = 0;
	while (str[count] == ' ' || str[count] == '\n' || str[count] == '\f' || \
			str[count] == '\t' || str[count] == '\v' || str[count] == '\r')
		count++;
	if (str[count] == '+')
		count++;
	else if (str[count] == '-')
	{
		sign = -1;
		count ++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		number = number * 10;
		number += str[count] - 48;
		count ++;
	}
	return (ft_check_over_long(sign, number));
}

static int	ft_check_over_long(int sign, unsigned long long int number)
{
	if (number >= 9223372036854775808ULL)
	{
		if (sign == 1)
			number = 1;
		else
			number = 0;
		sign = -sign;
	}	
	if (sign < 0)
		return (-number);
	else
		return (number);
}

/*
 * NAME: ft_isdigit()
 * 
 * DESCRIPTION:
 * 		Check for a digit character. No locale is considered.
 * 
 * RETURN VALUE:
 * 		Return nonzero if digit is alphabetic and zero if not.
 * 
 * TIPS:
 * 		1. - MAN ASCII
 */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

/*
 * NAME: ft_putnbr_fd()
 * 
 * DESCRIPTION:
 * 		Output the integer n to the file descriptor fd.
 * 
 * RETURN VALUE:
 * 		NOTHING
 * 
 * TIPS:
 * 		1. Be careful with MIN_INT
 * 		2. Convert negative values to positive ones.
 */

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		ft_putnbr_positive(n, fd);
	}
}

static void	ft_putnbr_positive(int n, int fd)
{
	int		i;
	char	out[11];

	i = 0;
	while (n > 9)
	{
		out[i] = 48 + (n % 10);
		n = n / 10;
		i++;
	}
	out[i] = 48 + n;
	while (i >= 0)
	{
		ft_putchar_fd(out[i], fd);
		i--;
	}
}
