/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:17:27 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:17:37 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*lstnew;

	lstnew = malloc(sizeof(t_list));
	if (lstnew == NULL)
		return (NULL);
	if (lstnew)
	{
		lstnew->content = content;
		lstnew->next = NULL;
	}
	return (lstnew);
}
