/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03tokenizer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:06:54 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/04 15:06:56 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokenizer(t_token **token_lst, char *input)
{
	t_token	*token;
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
			token = init_in_quotes(&input[i], &i, input[i]);
		else if (input[i] == '|' || input[i] == ' ')
			token = init_pipe_or_sep(&input[i], &i, input[i]);
		else if ((input[i] == '>' && input[i + 1] != '>') || \
				(input[i] == '<' && input[i + 1] != '<'))
			token = init_single_redirection(input, &i, input[i]);
		else if ((input[i] == '<' && input[i + 1] == '<') || \
				(input[i] == '>' && input[i + 1] == '>'))
			token = init_double_redirection(input, &i, input[i]);
		else
			token = init_word(input, &i);
		token_add_back(token_lst, token);
	}
}
