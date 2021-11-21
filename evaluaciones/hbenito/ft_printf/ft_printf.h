/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenito- <hbenito-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:33:32 by hbenito-          #+#    #+#             */
/*   Updated: 2021/11/19 11:26:32 by hbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_format(va_list arg, char src);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnum(int num);
int	ft_putunnum(unsigned int num);
int	ft_putexa(size_t exa, char c);

#endif
