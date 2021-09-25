/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:48:14 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/15 10:47:09 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/srcs/ft_printf.h"

typedef struct s_push
{
	int	*a;
	int	*b;
	int	*aux;
	int	size_a;
	int	size_b;
}	t_push;

void	ft_some_args(t_push *p, int argc, char *argv[]);
void	ft_unique_args(t_push *p, int argc, char *argv[]);
void	ft_init_struct(t_push *p, int size);
//------------MOVES---------------
void	ft_rra(t_push *p);
void	ft_rrb(t_push *p);
void	ft_rrr(t_push *p);
void	ft_ra(t_push *p);
void	ft_rb(t_push *p);
void	ft_rr(t_push *p);
void	ft_pa(t_push *p);
void	ft_pb(t_push *p);
void	ft_ss(t_push *p);
void	ft_sb(t_push *p);
void	ft_sa(t_push *p);
//------------LAUNCH-MOVES---------------
void	ft_launch_sa(t_push *p);
void	ft_launch_sb(t_push *p);
void	ft_launc_ss(t_push *p);
void	ft_launch_ra(t_push *p);
void	ft_launch_rb(t_push *p);
void	ft_launch_rr(t_push *p);
void	ft_launch_rra(t_push *p);
void	ft_launch_rrb(t_push *p);
void	ft_launch_rrr(t_push *p);
void	ft_launch_pa(t_push *p);
void	ft_launch_pb(t_push *p);
//------------UTILS---------------
void	ft_swap(int *a, int *b);
int		*ft_get_order_stack(t_push *p);
//------------SOLUTIONS---------------
void	ft_create_solution(t_push *p);
void	ft_order_two_nums(t_push *p);
void	ft_order_three_nums(t_push *p);
void	ft_order_hundred_nums(t_push *p);
//-------------THREE------------------
void	ft_case_one(t_push *p);
void	ft_case_two(t_push *p);
void	ft_case_three(t_push *p);
void	ft_case_four(t_push *p);
void	ft_case_five(t_push *p);
//-------------FIVE------------------
void	ft_loop(t_push *p);
void	ft_case_five_nums(t_push *p);
void	ft_case_four_nums(t_push *p);
void	ft_order_five_nums(t_push *p);
//------------HUNDRED----------------
void	ft_order_stack_b(t_push *p);
void	ft_check_str_or_num(char *str);
int		ft_check_is_order(t_push *p);
void	ft_loop_a(t_push *p, int x, int size);
int		ft_check_up_moves(t_push *p, int max_value_in_chunk);
int		ft_check_down_moves(t_push *p, int max_value_in_chunk);
void	ft_case_up(int change_value, t_push *p);
void	ft_case_down(int change_value, t_push *p);
int		ft_atoi_special(const char *str, t_push *p);
void	ft_error(t_push *p);

#endif
