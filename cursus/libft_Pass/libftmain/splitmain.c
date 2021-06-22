/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:35:57 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/16 20:06:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int main(void)
{
	const char s[] = "      split       this for   me  !       ";
	char	c;
	char	**tab;
	int		i = 0;
	c = ' ';

	tab = ft_split(s, c);
	while(tab[i])
	{	
		printf("string : %s\n", tab[i]);
		i++;
	}
}
