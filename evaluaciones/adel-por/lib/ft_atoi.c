/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:34:46 by adel-por          #+#    #+#             */
/*   Updated: 2021/07/12 18:09:07 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	cont;
	int	save;
	int	minus;

	cont = 0;
	save = 0;
	minus = 0;
	while ((str[cont] >= 9 && str[cont] <= 13) || str[cont] == 32)
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			minus++;
		cont++;
	}
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		save = (save * 10) + (str[cont] - 48);
		cont++;
	}
	if (minus == 1)
		return (save *= -1);
	return (save);
}
