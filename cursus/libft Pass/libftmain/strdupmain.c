/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdupmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:10:50 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/09 20:16:03 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(void)
{
	char str[] = "hola me llamo lukass";
	char *res;
	
	res = ft_strdup(str);
	printf("%s", res);
}
