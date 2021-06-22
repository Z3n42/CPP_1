/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprintmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:48:11 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/02 19:04:05 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int c);

int	main(void)
{
	int	c;
	int	r;

	c = '(';
	r = ft_isprint(c);
	printf("%d", r);
}
