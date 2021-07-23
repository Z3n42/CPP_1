/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:55:52 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/23 19:32:30 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	/* char a[] = "Hola q tal"; */
	int ft;
	int or;
	/* a = 2; */

	ft = ft_printf("FTiginal :%p %p ", 0, 0);
	printf("FT int :%d\n", ft);
	or = printf("Original :%p %p ", 0, 0);
	printf("Or :%d", or);
}
