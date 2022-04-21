/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:05:18 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/11 13:41:46 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_elem = ft_lstlast(*lst);
	last_elem->next = new;
}

/* int	main(void)
{
	t_list *my_tlist = (t_list *)malloc(sizeof(t_list) * 5);
	char content[20] = "CONTENT.";
	t_list *linked_list_item1 = ft_lstnew((void *)content);
	char content2[20] = "CONTENT2.";
	t_list *linked_list_item2 = ft_lstnew((void *)content2);
	ft_lstadd_back(&my_tlist, linked_list_item1);
	ft_lstadd_back(&my_tlist, linked_list_item2);
	printf("The result is %s\n", (char *)my_tlist[0].content);
	printf("The result is %s\n", (char *)my_tlist[0].next->content);
	return 0;
}
 */