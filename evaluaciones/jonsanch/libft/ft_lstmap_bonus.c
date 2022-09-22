/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonsanch <jonsanch@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:46:51 by jonsanch          #+#    #+#             */
/*   Updated: 2022/09/22 17:48:17 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*nxt;

	if (!lst || !f)
		return (NULL);
	curr = ft_lstnew(f(lst->content));
	if (!curr)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		nxt = ft_lstnew(f(lst->content));
		ft_lstadd_back(&curr, nxt);
		if (!nxt)
		{
			ft_lstclear(&curr, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (curr);
}
