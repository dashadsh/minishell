/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:37:55 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/06/30 11:13:21 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node.  The memory of
’next’ must not be freed.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{	
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

/*
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
*/
