/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:44:59 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/15 10:45:02 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ft_jump_spcs(char *aux)
{
	while (*aux == ' ' || *aux == '\t' || *aux == '\r'
		|| *aux == '\f' || *aux == '\v' || *aux == '\n')
		aux++;
	return (aux);
}

int	ft_check_nb_max(unsigned long long result, int mult)
{
	unsigned long long	i;

	i = 2147483647;
	if (result > i)
	{
		if (mult == -1 && result != i++)
			result = 0;
		else
			result = 0;
	}
	return (result);
}

static void	ft_check_error(unsigned long long result, int mult, t_push *p)
{
	if (result > 2147483647 && mult == 1)
		ft_error(p);
}

int	ft_atoi_special(const char *str, t_push *p)
{
	char				*aux;
	int					mult;
	unsigned long long	result;

	mult = 1;
	aux = (char *)str;
	result = 0;
	aux = ft_jump_spcs(aux);
	if (*aux == '+' || *aux == '-')
	{
		if (*aux == '-')
			mult = -1;
		aux++;
	}
	while (*aux)
	{
		if (*aux < 48 || 57 < *aux)
			return (result * mult);
		else
			result = (result * 10) + (long long int)(*aux - '0');
		aux++;
	}
	ft_check_error(result, mult, p);
	result = ft_check_nb_max(result, mult);
	return (result * mult);
}
