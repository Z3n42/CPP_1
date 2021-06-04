/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rus02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:43:04 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/02 21:03:10 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "check_input.h"
#include "utilities.h"

struct s_dct
{
	int		num;
	char	*name;
};

char	*ft_get_dct_values(char *buffer, char *dict_name)
{
	int		fd;
	int		i;
	char	buf[1024];

	i = 0;
	fd = open(dict_name, O_RDONLY);
	if (fd == -1)
		ft_putstr("Error, dictionary not found\n");
	else
	{
		while (read(fd, buf, sizeof buf) > 0)
		{
		}	
		ft_check_buf(buf);
		buffer = buf;
	}
	return (buffer);
}

int	ft_get_and_set_values (char *argv, char *dict_name, char *buf, char *src)
{
	int	num;

	num = ft_get_num(argv);
	ft_set_dict_name(dict_name, src);
	ft_get_dct_values(buf, dict_name);
	return (num);
}

int	main(int argc, char *argv[])
{
	int				error;
	unsigned int	num;
	char			buf[1024];
	char			dict_name[50];

	error = 0;
	if (argc == 2)
	{
		error = ft_str_is_numeric(argv[1]);
		if (error == 0)
			num = ft_get_and_set_values(
					argv[1], dict_name, buf, "numbers.dict");
	}
	else if (argc == 3)
	{
		error = ft_str_is_numeric(argv[2]);
		if (error == 0)
			num = ft_get_and_set_values(argv[2], dict_name, buf, argv[1]);
	}
	else
		ft_show_error();
	if (error == 1)
		ft_show_error();
	return (0);
}
