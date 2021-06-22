/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalphamain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:38:45 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/01 21:42:59 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_isalpha(int c);

int	main(void)
{
	int	c;
	int	r;

	c = 'a';
	r = isalpha(c);
	printf("%d", r);
}
