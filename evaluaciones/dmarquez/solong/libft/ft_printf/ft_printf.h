/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 22:04:12 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 11:59:11 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# include "../libft.h"

//Basic
int		ft_printf(const char *print, ...);
int		ft_format(va_list	args, const char format);
//Put
int		ft_put_char(va_list	args);
int		ft_put_string(va_list	args);
int		ft_put_nbr(va_list	args);
int		ft_put_unsig(va_list	args);
int		ft_put_hex(va_list	args, const char format);
int		ft_put_ptr(va_list	args);
int		ft_put_ptr(va_list	args);
//Utils
int		ft_putstr(const	char *str);
char	*ft_uitoa(unsigned int n);
int		ft_nbr_len(unsigned	int nbr);
int		ft_hex_len(unsigned	int nbr);
int		ft_ptr_len(uintptr_t nbr);
void	ft_print_hexa(unsigned int nbr, const char format);
void	ft_print_ptr(uintptr_t nbr);

#endif
