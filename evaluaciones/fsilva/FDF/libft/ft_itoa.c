/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:51:18 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/31 22:15:27 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_get_num_dig(long int num, size_t *num_dig);
static long int	ft_check_sign_itoa(int n, int *sign);
static void		ft_get_itoa(char *ptr, long int num, size_t num_dig);

char	*ft_itoa(int n)
{
	char		*ptr;
	size_t		num_dig;
	long int	num;
	int			sign;

	num_dig = 0;
	sign = 1;
	num = ft_check_sign_itoa(n, &sign);
	ft_get_num_dig(num, &num_dig);
	if (sign == -1)
		num_dig = num_dig + 1;
	ptr = (char *)malloc((size_t)num_dig + 1);
	if (ptr == NULL)
		return (NULL);
	ft_get_itoa(ptr, num, num_dig - 1);
	if (sign == -1)
		ptr[0] = '-';
	ptr[num_dig] = '\0';
	return (ptr);
}

static void	ft_get_itoa(char *ptr, long int num, size_t num_dig)
{
	if (num < 10)
	{
		ptr[num_dig] = num + 48;
	}
	else
	{
		ft_get_itoa(ptr, num / 10, num_dig - 1);
		ptr[num_dig] = (num % 10) + 48;
	}
}

static void	ft_get_num_dig(long int num, size_t *num_dig)
{
	if (num < 10)
	{
		*num_dig = *num_dig + 1;
	}
	else
	{
		*num_dig = *num_dig + 1;
		ft_get_num_dig(num / 10, num_dig);
	}
}

static long int	ft_check_sign_itoa(int n, int *sign)
{
	long int	num;

	num = (long int)n;
	if (num < 0)
	{
		*sign = -1;
		num = num * -1;
	}
	return (num);
}
