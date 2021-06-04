/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:20:53 by ingonzal          #+#    #+#             */
/*   Updated: 2021/05/06 17:45:52 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

int		ft_check(char *str);
void	ft_archarge(char *str, char **tbl, int row);
void	ft_ardata(char *str, int col, int nrow);
void	ft_tbl_error(void);

#endif
