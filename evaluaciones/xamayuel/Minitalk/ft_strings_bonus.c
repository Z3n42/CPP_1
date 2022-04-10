/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:05:31 by xamayuel          #+#    #+#             */
/*   Updated: 2022/03/22 20:52:07 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/*
 * NAME: ft_strlen()
 * 
 * DESCRIPTION:
 * 		Compute the length of the string.
 * 
 * RETURN VALUE:
 * 		Number of characters that precede the NUL termination.
 * 
 * TIPS:
 * 		1. - *s++ !!
 */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

/*
 * NAME: ft_strlcpy()
 * 
 * DESCRIPTION:
 * 		Copies the src string to dst string. Take the full size of dst buffer
 * 		and guarantee NUL-termination.
 * 
 * RETURN VALUE:
 * 
 * 		Total length tried to create.
 * 
 * TIPS:
 * 		1. Copy while src or dstsize-1 is not found
 * 		2. dts[dstsize] = '\0' always!
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
 * NAME: ft_putchar_fd()
 * 
 * DESCRIPTION:
 * 		Writes the charcter 'c' in the file defined by the file descriptor fd
 * 
 * 
 * RETURN VALUE:
 *		Nothing.
 * 
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
 * NAME: ft_putstr_c()
 * 
 * DESCRIPTION:
 * 		Writes the string in the file defined by the file descriptor
 * 
 * RETURN VALUE:
 * 		Nothing.
 */

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
