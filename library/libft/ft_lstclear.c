/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:08:31 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/06/30 15:39:53 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Deletes and frees the given node and every
successor of that node, using the function ’del’
and free(3).
Finally, the pointer to the list must be set to
NULL.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*tale;

	if (!lst || !del)
		return ;
	tale = *lst;
	while (tale)
	{	
		head = tale;
		tale = tale->next;
		del(head->content);
		free(head);
	}
	*lst = NULL;
}

/*
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*value;

	while (*lst)
	{
		value = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = value;
	}
}
*/

/*
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*dn;

	dn = *lst;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		*lst = (*lst)->next;
		del(dn->content);
		free (dn);
		dn = *lst;
	}
	*lst = NULL;
}
*/

/*
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = temp;
	}
}
*/