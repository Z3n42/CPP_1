/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substrmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:30:43 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/10 19:23:54 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	const char		s[] = "Practicando malloc low lvl";
	unsigned int	start;
	size_t			len;
	char			*re;

	start = 11;
	len = 0;
	re = ft_substr(s, start, len);
	printf("Resultado: %s", re);
}
