#include "libft.h"

t_list	*ft_lstmap(t_list	*lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*next_old;
	t_list	*next_new;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	if (!new_list)
		return (NULL);
	next_new = new_list;
	next_old = lst->next;
	while (1)
	{
		if (next_old == NULL)
			break ;
		next_new->next = ft_lstnew((*f)(next_old->content));
		if (!next_new)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		next_new = next_new->next;
		next_old = next_old->next;
	}
	return (new_list);
}
