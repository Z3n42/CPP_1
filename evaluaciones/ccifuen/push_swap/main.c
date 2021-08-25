/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:18:31 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/20 10:44:46 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/ft_push_swap.h"

int	ft_check_sort(t_p *p)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (i < p->a_size - 1)
	{
		if (ft_atoi(p->a[i]) < ft_atoi(p->a[i + 1]))
		{
			r = 0;
			break ;
		}
		i++;
	}
	return (r);
}

int	ft_check_error(t_p *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->a_size)
	{
		if (!ft_all_digits(p->a[i]))
			return (1);
		if (ft_atoi(p->a[i]) < -2147483648 || ft_atoi(p->a[i]) > 2147483647)
			return (1);
		j = i + 1;
		while (j < p->a_size)
		{
			if (ft_atoi(p->a[i]) == ft_atoi(p->a[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_p	p;

	if (argc == 2)
		ft_get_one_arg(&p, argv);
	else
		ft_get_args(&p, argv, argc);
	if (ft_check_error(&p))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (p.a_size <= 3)
		ft_sort_3(&p);
	else if (p.a_size < 60)
		ft_sort_50(&p);
	else if (p.a_size < 200)
		ft_sort_100(&p);
	else
		ft_sort_500(&p);
	ft_back_to_a(&p);
	ft_free_p(&p);
}
