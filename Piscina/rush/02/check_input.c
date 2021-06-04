/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:56:09 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/01 13:40:12 by ingonzal         ###   ########.fr       */
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
	while (str[i] != '\0')
	{
		result = (result * 10) + str[i];
		i++;
	}
	return (result);
}
