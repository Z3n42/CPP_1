/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:38:07 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/15 09:50:17 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int	*ft_get_order_stack(t_push *p)
{
	int	i;
	int	j;
	int	*aux;

	aux = (int *) malloc(sizeof(int) * (p->size_a));
	i = 0;
	while (i < p->size_a)
	{
		aux[i] = p->a[i];
		i++;
	}
	i = 0;
	while (i < p->size_a)
	{
		j = i + 1;
		while (j < p->size_a)
		{
			if (aux[i] > aux[j])
				ft_swap(&aux[i], &aux[j]);
			j++;
		}
		i++;
	}
	return (aux);
}

int	ft_check_is_order(t_push *p)
{
	int	i;
	int	j;

	i = 0;
	if (p->size_a == 1)
		return (1);
	while (i < p->size_a - 1)
	{
		j = i + 1;
		if (p->a[i] > p->a[j])
			return (1);
		i++;
	}
	return (0);
}
