/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:50:52 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:52:53 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list	*iter;

	if (!lst || !*lst || !del)
		return ;
	while (lst && *lst)
	{
		iter = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = iter;
	}
}
