/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:19:57 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:20:03 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list	*lst, void (*f)(void	*))
{
	if (f == NULL)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}	
}
