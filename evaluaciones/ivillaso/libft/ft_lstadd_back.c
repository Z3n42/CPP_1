/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:09:07 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:09:17 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*temp;

	if (*lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
		return ;
	}
	*lst = new;
}
