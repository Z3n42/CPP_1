/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:08:56 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/20 10:58:55 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_push_swap.h"

void	ft_free_p(t_p *p)
{
	ft_free(p->a, 1000);
	p->a = NULL;
	ft_free(p->b, 1000);
	p->b = NULL;
	if (p->sorted_size > 0)
		free(p->sorted);
}

void	ft_alloc(t_p *p)
{
	int	i;

	i = 0;
	p->a = ft_calloc(sizeof(char *), 1000);
	p->b = ft_calloc(sizeof(char *), 1000);
	while (i < 1000)
	{
		p->a[i] = ft_calloc(sizeof(char), 20);
		p->b[i] = ft_calloc(sizeof(char), 20);
		i++;
	}
}

void	ft_get_one_arg(t_p *p, char **argv)
{
	int		i;
	int		j;
	char	**arg;

	arg = ft_split(argv[1], ' ');
	p->a_size = ft_count_m(argv[1], ' ');
	p->b_size = 0;
	p->sorted_size = 0;
	j = ft_count_m(argv[1], ' ');
	i = 0;
	ft_alloc(p);
	while (i < p->a_size)
	{
		ft_memmove(p->a[j - 1], arg[i], ft_strlen(arg[i]));
		i++;
		j--;
	}
	ft_free(arg, ft_count_m(argv[1], ' '));
}

void	ft_get_args(t_p *p, char **argv, int argc)
{
	int	i;
	int	j;

	p->a_size = argc - 1;
	p->b_size = 0;
	p->sorted_size = 0;
	j = argc - 1;
	i = 0;
	ft_alloc(p);
	while (i < p->a_size)
	{
		ft_memmove(p->a[j - 1], argv[i + 1], ft_strlen(argv[i + 1]));
		i++;
		j--;
	}
}
