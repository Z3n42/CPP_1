/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prugnnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:44:22 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/26 15:44:42 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int get_next_line(char **line)
{
	int		i;
	int		value;
	char	chr;
	char	*buff;

	buff = malloc(1024);
	if (!buff)
		return (-1);
	i = 0;
	value = read(0, &chr, 1);
	while (chr != '\n' && chr != '\0')
	{
		/* if (chr != '\n' && chr != '\0') */
			buff[i] = chr;
		i++;
		value = read(0, &chr, 1);
	}
	buff[i] = '\0';
	*line = buff;
	return (value);
}

int main(void)
{
	int		r;
	char	*line;
	line = NULL;
	while ((r = get_next_line(&line)) > 1)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
	/* system("leaks a.out"); */
}
