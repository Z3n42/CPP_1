/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtimmainn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:14:59 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/11 19:46:39 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	main(void)
{
	const char	s1[] = "bbcaaaaaabaabcb";
	const char	set[] = "bc";
	char		*res;

	res = ft_strtrim(s1, set);
	printf("Resultado : %s\n", res);
}
