/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 13:53:59 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/31 14:27:06 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	ft_swap_ss(int *a, int *b)
{
	int swap;
	
	swap = a[0];
	a[0] = a[1];
	a[1] = swap;
	swap = b[0];
	b[0] = b[1];
	b[1] = swap;
	write(1, "ss\n", 3);
}
