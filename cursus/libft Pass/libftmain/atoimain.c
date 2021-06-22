/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:04:32 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/07 21:38:50 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*str_;

	str = "99999999999999999999999999";
	str_ = "99999999999999999999999999";
	printf("FT: \n%d\n", ft_atoi(str));
	printf("Original: \n%d\n", atoi(str_));
}
