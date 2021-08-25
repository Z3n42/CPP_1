/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_track_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 20:34:47 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/20 10:48:18 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_push_swap.h"

void	ft_get_tracks_5(t_p *p)
{
	int	i;
	int	div;

	ft_alloc_sorted(p);
	i = 0;
	if (p->a_size % 5 == 0)
		div = (p->a_size / 5);
	else
		div = (p->a_size / 5) + 1;
	while (i < 4)
	{
		p->track_100[i] = p->sorted[div * (i + 1)];
		i++;
	}
	p->track_100[4] = p->sorted[p->a_size - 1];
}

int	ft_check_next_5(t_p *p, int track)
{
	int	i;

	i = 0;
	while (i < p->a_size)
	{
		if (ft_atoi(p->a[i]) < p->track_100[track])
			return (1);
		i++;
	}
	return (0);
}

int	ft_search_next_5(t_p *p, int track)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = p->a_size;
	while (i < p->a_size)
	{
		if (ft_atoi(p->a[i]) < p->track_100[track])
			break ;
		i++;
	}
	while (j)
	{
		if (ft_atoi(p->a[j - 1]) < p->track_100[track])
			break ;
		j--;
		k++;
	}
	if (k < i)
		return (k);
	else
		return (i * -1);
}

int	ft_check_up_5(t_p *p, int track)
{
	if (ft_atoi(p->a[p->a_size - 1]) < p->track_100[track])
		return (1);
	return (0);
}
