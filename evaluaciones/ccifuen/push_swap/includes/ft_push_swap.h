/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:57:11 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/20 11:12:59 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_p
{
	char	**a;
	char	**b;
	int		*sorted;
	int		a_size;
	int		b_size;
	int		sorted_size;
	int		sum;
	int		track_60[3];
	int		track_100[5];
	int		track_250[8];
	int		track_500[11];
	int		min_a;
	int		max_a;
	int		max_b;
}			t_p;

void	ft_push_a(t_p *p);
void	ft_push_b(t_p *p);
void	ft_swap_a(t_p *p);
void	ft_swap_b(t_p *p);
void	ft_swap_s(t_p *p);
void	ft_rotate_a(t_p *p);
void	ft_rotate_b(t_p *p);
void	ft_rotate_r(t_p *p);
void	ft_rev_rotate_a(t_p *p);
void	ft_rev_rotate_b(t_p *p);
void	ft_rev_rotate_r(t_p *p);
void	ft_print_stacks(t_p *p);
void	ft_print_stacks_yeah(t_p *p);
int		ft_check_sort(t_p *p);
void	ft_get_min_a(t_p *p);
int		ft_search_next_min(t_p *p);
int		ft_check_min_a(t_p *p);
void	ft_sort_50(t_p *p);
void	ft_get_max_b(t_p *p);
int		ft_search_n_m_b(t_p *p);
int		ft_check_max_b(t_p *p);
void	ft_sort_100(t_p *p);
void	ft_get_tracks_5(t_p *p);
int		ft_check_next_5(t_p *p, int track);
int		ft_search_next_5(t_p *p, int track);
int		ft_check_up_5(t_p *p, int track);
void	ft_alloc_sorted(t_p *p);
void	ft_push_b_500(t_p *p);
void	ft_sort_500(t_p *p);
void	ft_get_tracks_11(t_p *p);
int		ft_check_next_11(t_p *p, int track);
int		ft_search_next_11(t_p *p, int track);
int		ft_check_up_11(t_p *p, int track);
void	ft_sort_3(t_p *p);
void	ft_back_to_a(t_p *p);
void	ft_free_p(t_p *p);
void	ft_alloc(t_p *p);
void	ft_alloc_sorted(t_p *p);
void	ft_get_one_arg(t_p *p, char **argv);
void	ft_get_args(t_p *p, char **argv, int argc);

#endif
