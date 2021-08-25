/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchrmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:12:43 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/06 13:14:03 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main () 
{
   const char str[] = "http://www.tutorialspoint.com";
   const char str_[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   const char ch_ = '.';
   char *ret;
   char *ret_;

   ret = memchr(str, ch, strlen(str));
   ret_ = ft_memchr(str_, ch_, strlen(str_));

   printf("In original string after |%c| is - |%s|\n", ch, ret);
   printf("In FT string after |%c| is - |%s|\n", ch_, ret_);

   return(0);
}
