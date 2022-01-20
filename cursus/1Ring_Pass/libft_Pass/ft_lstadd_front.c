/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:22:00 by ingonzal          #+#    #+#             */
/*   Updated: 2022/01/14 18:48:07 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_front(t_list **last, t_list *new)
{
	if (!last || !new)
		return (NULL);
	new->next = *last;
	*last = new;
	return (new);
}
