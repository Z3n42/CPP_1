/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:17:16 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/05 15:15:48 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

void	ft_rotate_a(int argc, int *a)
{
	int	count;
	int swap;

	swap = a[0];
	count = 0;
	while(count < (argc - 1))
	{
		a[count] = a[count + 1];
		count++;
	}
	a[argc - 1] = swap;
	write(1, "ra\n", 3);
}
