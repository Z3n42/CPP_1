/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigitmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 21:13:16 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/01 21:41:10 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int c);

int	main(void)
{
	int	c;
	int	r;

	c = 1;
	r = ft_isdigit(c);
	printf("%d\n", r);
}
