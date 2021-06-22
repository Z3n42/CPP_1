/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isasciimain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:09:20 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/02 18:44:33 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isascii(int c);

int	main(void)
{
	int	c;
	int	r;

	c = 45;
	r = ft_isascii(c);
	printf("%d", r);
}
