/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:56:36 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/30 14:20:55 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Iterates the list ’lst’ and applies the function
’f’ on the content of each node.  Creates a new
list resulting of the successive applications of
the function ’f’.  The ’del’ function is used to
delete the content of a node if needed.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new;
	t_list	*lstiteri;

	newlst = NULL;
	lstiteri = lst;
	while (lstiteri)
	{
		new = ft_lstnew(f(lstiteri->content));
		if (!new)
		{
			ft_lstclear(&newlst, del);
			return (newlst);
		}
		ft_lstadd_back(&newlst, new);
		lstiteri = lstiteri -> next;
	}
	return (newlst);
}
