/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:57:52 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/01 12:22:07 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str);

int	main(void)
{
	const char	*str;
	int			i;
	int			c;

	str = "hola";
	printf("Texto: %s", str);
	printf("\n");
	i = ft_strlen(str);
	printf("Total: %d", i);
	printf("\n");
	c = strlen(str);
	printf("Original: %d", c);
	printf("\n");
}
