/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:11:48 by ccifuent          #+#    #+#             */
/*   Updated: 2021/06/10 19:15:37 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_tmp;
	t_list	*lst_new;

	if (!lst)
		return (0);
	lst_tmp = ft_lstnew(f(lst->content));
	if (!lst_tmp)
		return (0);
	lst = lst->next;
	while (lst)
	{
		lst_new = ft_lstnew(f(lst->content));
		if (!lst_new)
		{
			ft_lstclear(&lst_tmp, del);
			return (0);
		}
		ft_lstadd_back(&lst_tmp, lst_new);
		lst = lst->next;
	}
	return (lst_tmp);
}
