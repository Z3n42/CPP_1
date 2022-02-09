/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:32:51 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/31 21:51:52 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_element(int *first, t_list *n_list, t_list **n_first, \
		void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*n_first;
	int		first;

	if (!lst || !f)
		return (NULL);
	first = 0;
	n_first = NULL;
	while (lst)
	{
		n_list = ft_lstnew(f(lst->content));
		if (first == 1)
			ft_lstadd_back(&n_first, n_list);
		if (ft_check_element(&first, n_list, &n_first, del))
			return (n_first);
		lst = lst->next;
	}
	return (n_first);
}

int	ft_check_element(int *first, t_list *n_list, t_list **n_first, \
		void (*del)(void *))
{
	if (*first == 0)
	{
		*first = 1;
		if (n_list == NULL)
		{
			del(n_list->content);
			return (1);
		}
		else
		{
			*n_first = n_list;
			return (0);
		}
	}
	else
	{
		if (n_list == NULL)
		{
			del(n_list->content);
			return (1);
		}
		else
			return (0);
	}
}
