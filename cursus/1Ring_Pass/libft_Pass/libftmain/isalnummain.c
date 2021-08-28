/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnummain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:45:23 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/02 18:06:04 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int	ft_isalnum(int c);

int	main(void)
{
	int	c;
	int	r;

	c = 'a';
	r = ft_isalnum(c);
	printf("%d", r);
}
