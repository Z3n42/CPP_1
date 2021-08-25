/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:35:39 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/20 12:22:32 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_push_swap.h"

void	ft_rev_rotate_a(t_p *p)
{
	char	*temp;
	int		i;

	i = 0;
	temp = p->a[i];
	while (i < p->a_size)
	{
		p->a[i] = p->a[i + 1];
		i++;
	}
	p->a[i - 1] = temp;
	write(1, "rra\n", 4);
}

void	ft_rev_rotate_b(t_p *p)
{
	char	*temp;
	int		i;

	i = 0;
	temp = p->b[i];
	while (i < p->b_size)
	{
		p->b[i] = p->b[i + 1];
		i++;
	}
	p->b[i - 1] = temp;
	write(1, "rrb\n", 4);
}

void	ft_rev_rotate_r(t_p *p)
{
	char	*temp_a;
	char	*temp_b;
	int		i;

	i = 0;
	temp_a = p->a[i];
	while (i < p->a_size)
	{
		p->a[i] = p->a[i + 1];
		i++;
	}
	if (i > 0)
		p->a[i - 1] = temp_a;
	i = 0;
	temp_b = p->b[i];
	while (i < p->b_size)
	{
		p->b[i] = p->b[i + 1];
		i++;
	}
	if (i > 0)
		p->b[i - 1] = temp_b;
	write(1, "rrr\n", 4);
}
