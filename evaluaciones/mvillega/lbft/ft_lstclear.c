#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		ft_lstdelone(*lst, del);
		*lst = (*lst)->next;
	}
}
