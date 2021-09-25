/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:37:33 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/19 13:02:23 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_get_size(char *argv)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (argv[i] != '\0' || argv[i + 1] != '\0')
	{
		if (argv[i] == 32)
			size++;
		i++;
	}
	if (size == 0)
		return (0);
	return (size + 1);
}

static void	ft_free_tmp(char **tmp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	ft_check_str_or_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_printf("sale por aqui\n");
			ft_printf("ERROR\n");
			exit(1);
		}
		i++;
	}
}

void	ft_unique_args(t_push *p, int argc, char *argv[])
{
	int		i;
	int		tmp_size;
	char	**tmp;

	i = 0;
	if (argc != 2)
	{	
		ft_check_str_or_num(argv[1]);
		exit(1);
	}
	tmp_size = ft_get_size(argv[1]);
	ft_init_struct(p, tmp_size);
	tmp = ft_split(argv[1], ' ');
	while (tmp[i] != NULL)
	{
		p->a[i] = ft_atoi_special(tmp[i], p);
		p->aux[i] = ft_atoi_special(tmp[i], p);
		if (p->a[i] == 0)
			ft_check_str_or_num(tmp[i]);
		i++;
	}
	ft_free_tmp(tmp, tmp_size);
}
