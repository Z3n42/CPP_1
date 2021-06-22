/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:12:54 by ingonzal          #+#    #+#             */
/*   Updated: 2021/05/28 13:23:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putstr_fd(char *s, int fd);

int	main(void)
{
	int		fd;
	char	s[] = "Hello";

	fd = 1;
	ft_putstr_fd(s, fd);
}
