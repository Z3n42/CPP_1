/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:32:09 by ingonzal          #+#    #+#             */
/*   Updated: 2021/05/28 13:50:52 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putendl_fd(char *s, int fd);

int	main(void)
{
	int		fd;
	char	s[] = "Hello";

	fd = 1;
	ft_putendl_fd(s, fd);
}
