/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmpmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:04:33 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/06 14:28:52 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int main () {
   char str1[15] = "A";
   char str2[15] = "a";
   int ret;
   int ret_;

   ret = memcmp(str1, str2, 5);
   ret_ = ft_memcmp(str1, str2, 5);

      printf("\nS1: %s\n", str1);
      printf("\nS2: %s\n", str2);
      printf("\nOriginal: %d\n", ret);
      printf("\nFT: %d\n", ret_);
}
