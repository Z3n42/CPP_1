/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:46:37 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:51:27 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	pos;
	int	neg;
	int	result;

	pos = 0;
	neg = 1;
	result = 0;
	if (str[pos] == '\0')
		return (0);
	while (str[pos] == ' ' || (str[pos] >= 9 && str[pos] <= 13))
		pos++;
	while (str[pos] == '-' || str[pos] == '+')
	{
		if (str[pos] == '-')
			neg = neg * -1;
		if (str[pos + 1] == '-' || str[pos + 1] == '+')
			return (0);
		pos++;
	}
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		result = result * 10 + str[pos] - 48;
		pos++;
	}
	return (neg * result);
}
