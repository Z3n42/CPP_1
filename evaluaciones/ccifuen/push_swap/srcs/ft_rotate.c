/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:16:28 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/19 20:16:28 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_push_swap.h"

void	ft_rotate_a(t_p *p)
{
	char	*temp;
	int		i;

	i = p->a_size;
	temp = p->a[i - 1];
	while (i > 1)
	{
		p->a[i - 1] = p->a[i - 2];
		i--;
	}
	p->a[0] = temp;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_p *p)
{
	char	*temp;
	int		i;

	i = p->b_size;
	temp = p->b[i - 1];
	while (i > 1)
	{
		p->b[i - 1] = p->b[i - 2];
		i--;
	}
	p->b[0] = temp;
	write(1, "rb\n", 3);
}

void	ft_rotate_r(t_p *p)
{
	char	*temp_a;
	char	*temp_b;
	int		i;

	i = p->a_size;
	temp_a = p->a[i - 1];
	while (i > 1)
	{
		p->a[i - 1] = p->a[i - 2];
		i--;
	}
	p->a[0] = temp_a;
	i = p->b_size;
	temp_b = p->b[i - 1];
	while (i > 1)
	{
		p->b[i - 1] = p->b[i - 2];
		i--;
	}
	p->b[0] = temp_b;
	write(1, "rr\n", 3);
}
