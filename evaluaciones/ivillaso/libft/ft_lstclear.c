/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:09:22 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:09:23 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	if (!del || !lst || !*lst)
		return ;
	while (*lst && lst)
	{
		ft_lstdelone(*lst, del);
		*lst = (*lst)->next;
	}	
}
