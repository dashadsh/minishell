/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04expander.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:01:50 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/16 10:59:28 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process_expansion(char *token, t_data *data, t_idx *idx, char **exp)
{
	if (token[idx->i] == '$')
	{
		if (token[idx->i + 1] == '?')
			init_exit_status(exp, idx);
		else if (token[idx->i + 1] == '$')
			init_single_dollar(exp, idx);
		else if (ft_isalnum(token[idx->i + 1]) || token[idx->i + 1] == '_')
			init_env_var(exp, idx, token, data);
		else
			copy_token_char(exp, idx, token[idx->i++]);
	}
	else
		copy_token_char(exp, idx, token[idx->i++]);
}

char	*expand_token(char *token, t_data *data)
{
	char	*exp;
	t_idx	idx;

	exp = malloc(MAX_TOKEN_SIZE);
	if (!token)
	{
		printf("minishell: malloc failed in expander\n");
		g_exit_status = 13;
		return (NULL);
	}
	idx.i = 0;
	idx.j = 0;
	while (token[idx.i] != '\0')
	{
		process_expansion(token, data, &idx, &exp);
	}
	exp[idx.j] = '\0';
	return (exp);
}

void	expand_token_lst(t_data *data)
{
	t_token	*tmp;
	char	*expanded_string;

	tmp = data->token_lst;
	while (tmp != NULL)
	{
		if (tmp->type != HERE_DOC && tmp->quote_type != S_Q
			&& dollar_in_str(tmp->string))
		{
			expanded_string = expand_token(tmp->string, data);
			if (expanded_string != NULL)
			{
				free(tmp->string);
				tmp->string = expanded_string;
			}
		}
		tmp = tmp->next;
	}
}
