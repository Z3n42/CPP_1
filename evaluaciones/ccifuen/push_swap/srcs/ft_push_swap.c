/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:15:01 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/19 20:15:01 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_push_swap.h"

void	ft_push_a(t_p *p)
{
	char	*last_var;

	last_var = p->b[p->b_size - 1];
	p->b[p->b_size - 1] = 0;
	p->b_size--;
	p->a[p->a_size] = last_var;
	p->a_size++;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_p *p)
{
	char	*last_var;

	last_var = p->a[p->a_size - 1];
	p->a[p->a_size - 1] = 0;
	p->a_size--;
	free(p->b[p->b_size]);
	p->b[p->b_size] = last_var;
	p->b_size++;
	write(1, "pb\n", 3);
}

void	ft_swap_a(t_p *p)
{
	char	*temp;

	temp = p->a[p->a_size - 1];
	p->a[p->a_size - 1] = p->a[p->a_size - 2];
	p->a[p->a_size - 2] = temp;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_p *p)
{
	char	*temp;

	temp = p->b[p->b_size - 1];
	p->b[p->b_size - 1] = p->b[p->b_size - 2];
	p->b[p->b_size - 2] = temp;
	write(1, "sb\n", 3);
}

void	ft_swap_s(t_p *p)
{
	char	*temp_a;
	char	*temp_b;

	temp_a = p->a[p->a_size - 1];
	p->a[p->a_size - 1] = p->a[p->a_size - 2];
	p->a[p->a_size - 2] = temp_a;
	temp_b = p->b[p->b_size - 1];
	p->b[p->b_size - 1] = p->b[p->b_size - 2];
	p->b[p->b_size - 2] = temp_b;
	write(1, "ss\n", 3);
}
