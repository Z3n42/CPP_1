/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:25:39 by ecorreia          #+#    #+#             */
/*   Updated: 2021/10/11 19:49:11 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);

int	ft_char(va_list vars);
int	ft_string(va_list vars);
int	ft_integer(va_list vars);
int	ft_hexadecimal(va_list vars, int mayus);
int	ft_pointer(va_list vars);
int	ft_unsigned(va_list args);

int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	tam(long n);

#endif
