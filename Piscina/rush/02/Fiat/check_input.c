/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:56:09 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/02 20:51:24 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Mediante esta funcio comprobamos si la cadena
 * contiene unicamente numeros
 */
int	ft_str_is_numeric(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 49 || str[i] > 57)
		{
			result = 1;
		}
		i++;
	}
	return (result);
}

unsigned int	ft_get_num(char *str)
{
	unsigned int	result;
	int				i;

	i = 0;
	while (*str)
	{
		i *= 10;
		i += (*str - '0');
		str++;
	}
	return (i);
}

char	*ft_check_buf(char *buf)
{
	char	*aux;
	int		i;

	i = 0;
	aux = buf;
	while (*aux != '\0')
	{
		if (*aux == '\n')
			i++;
		aux++;
	}
	if (buf > 0)
		write(1, &"Dictionary found", 16);
	else
		write(1, &"Dic Error", 9);
	return (buf);
}
