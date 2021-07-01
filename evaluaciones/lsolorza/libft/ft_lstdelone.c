/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:19:15 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:19:24 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list	*lst, void (*del)(void	*))
{
	if (del == NULL)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
