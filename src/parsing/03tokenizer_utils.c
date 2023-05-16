/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03tokenizer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:06:35 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/04 15:06:51 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	token_add_back(t_token **lst, t_token *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		token_last(*lst)->next = new;
}

t_token	*token_last(t_token *lst)
{
	t_token	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	remove_quotes(char *s)
{
	int	len;

	len = ft_strlen(s);
	if ((len >= 2 && s[0] == '"' && s[len - 1] == '"')
		|| (len >= 2 && s[0] == '\'' && s[len - 1] == '\''))
	{
		ft_memmove(s, s + 1, len - 2);
		s[len - 2] = '\0';
	}
}

/// @brief takes a string and an array of possible separators as input and
/// returns the idx of the 1st occurrence of any of the separators in the str.
/// @param str 
/// @param possible_sep 
/// @return idx of the first occurrence of any of the separators in the string.
int	find_end(char *str, char *possible_sep)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (possible_sep[j])
		{
			if (str[i] == possible_sep[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
