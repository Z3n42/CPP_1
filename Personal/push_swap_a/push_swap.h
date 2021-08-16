/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:09:07 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/06 13:13:08 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft_Pass/libft.h"
#include <stdio.h>

void 	ft_error(int args, int *c);
int		ft_mincheck(int args, int *c);
int		ft_checker(int argc, int *a);
int		ft_atoi_push(const char *str);
void	ft_swap_a(int *a);
void	ft_swap_b(int *b);
void	ft_swap_ss(int *a, int *b);
void	ft_push_a(int argc, int *a, int *b);
void	ft_push_b(int argc, int *a, int *b);
void	ft_rotate_a(int argc, int *a);
void	ft_rotate_b(int argc, int *b);
void	ft_rotate_rr(int argc, int *a, int *b);
void	ft_reverse_ra(int argc, int *a);
void	ft_reverse_rb(int argc, int *b);
void	ft_reverse_rr(int argc, int *a, int *b);
void	ft_three(int argc, int *a);
void	ft_five(int args, int *a, int *b);

#endif

