/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghurtado <ghurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:42:37 by ibartolo          #+#    #+#             */
/*   Updated: 2022/07/10 20:15:00 by ghurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_verify_args(int *nbrs, char *argv)
{
	int	i;
	int	k;

	i = -1;
	while (argv[++i] != '\0')
	{
		if (!('1' <= argv[i] && argv[i] <= '4'))
			if (i % 2 == 0)
				return (1);
	}
	if (i != 31)
		return (1);
	i = 0;
	k = 0;
	while (i % 2 == 0)
	{
		nbrs[k] = argv[i] - 48;
		i += 2;
		k++;
	}
	return (0);
}
