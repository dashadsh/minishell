/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:18:41 by moduwole          #+#    #+#             */
/*   Updated: 2023/04/21 08:18:41 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	insert_end_outs(t_token *token, t_cmdgroup *group)
{
	t_outs	*new;
	t_outs	*tmp;

	new = ft_calloc(sizeof(t_outs), 1);
	new->str = ft_strdup(token->string);
	new->append = 0;
	if (token->type == APP_RED)
		new->append = 1;
	new->next = NULL;
	if (group->outs == NULL)
	{
		group->outs = new;
		return ;
	}
	tmp = group->outs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	insert_end_ins(t_token *token, t_cmdgroup *group)
{
	t_ins	*new;
	t_ins	*tmp;

	new = ft_calloc(sizeof(t_ins), 1);
	new->str = ft_strdup(token->string);
	new->heredoc = 0;
	if (token->type == HERE_DOC)
		new->heredoc = 1;
	new->next = NULL;
	if (group->ins == NULL)
	{
		group->ins = new;
		return ;
	}
	tmp = group->ins;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_token	*add_group(t_data *data, t_token *token)
{
	t_token		*tok;
	t_cmdgroup	*tmp;
	t_cmdgroup	*group;

	tok = token;
	group = ft_calloc(sizeof(t_cmdgroup), 1);
	while (tok && tok->type != PIPE)
	{
		if (tok->type == WORD)
			group->str = ft_strjoin2(group->str, tok->string, '\n');
		else if (tok->type == IN_RED || tok->type == HERE_DOC)
			insert_end_ins(tok, group);
		else if (tok->type == OUT_RED || tok->type == APP_RED)
			insert_end_outs(tok, group);
		tok = tok->next;
	}
	group->cmd = ft_split(group->str, '\n');
	if (data->cmdgroup == NULL)
		return ((data->cmdgroup = group), tok);
	tmp = data->cmdgroup;
	while (tmp->next)
		tmp = tmp->next;
	group->prev = tmp;
	tmp->next = group;
	return (tok);
}

void	cmd_init(t_data *data)
{
	t_token	*token;

	token = data->token_lst;
	while (token)
	{
		token = add_group(data, token);
		if (token)
			token = token->next;
	}
}
