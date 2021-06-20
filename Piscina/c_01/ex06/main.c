/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:53:21 by ingonzal          #+#    #+#             */
/*   Updated: 2021/04/26 16:48:50 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str);

int	main (void)
{
	char	*str;
	int		i;

	str = "asdfghjkl";
	i = ft_strlen(str);
	printf("total %d", i);
}
