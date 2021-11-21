/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlibano- <nlibano-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:50:03 by nlibano-          #+#    #+#             */
/*   Updated: 2021/11/09 17:50:03 by nlibano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;
	t_list	*elem;

	if (lst || f || del)
	{
		res = NULL;
		while (lst)
		{
			elem = lst->next;
			new = ft_lstnew((*f)(lst->content));
			if (!new)
			{
				ft_lstclear(&res, del);
				return (NULL);
			}
			ft_lstadd_back(&res, new);
			lst = elem;
		}
		return (res);
	}
	return (NULL);
}
