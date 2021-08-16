/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:45:14 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/05 15:16:33 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <unistd.h>

void	ft_rotate_b(int argc, int *b)
{
	int	count;
	int swap;

	swap = b[0];
	count = 0;
	while(count < (argc - 1))
	{
		b[count] = b[count + 1];
		count++;
	}
	b[argc - 1] = swap;
	write(1, "rb\n", 3);
}
