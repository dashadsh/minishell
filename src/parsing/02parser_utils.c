/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02parser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:04:33 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/10 12:17:35 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/// @brief removes consecutive quotes
/// of the same type (either single or double quotes) from it.
/// $''USER becomes $USER 
/// hi""bye becomes hibye
/// doesnt affect consecutive quotes inside other quotes:
/// "    '' " will remain unchanged
/// @param input
void	remove_consequtive_quotes(char *input)
{
	int	i;
	int	j;
	int	in_q;

	i = 0;
	j = 0;
	in_q = 0;
	while (input[i] != '\0')
	{
		if (!in_q && ((input[i] == '"' && input[i + 1] == '"')
				|| (input[i] == '\'' && input[i + 1] == '\'')))
			i += 2;
		else
		{
			if (input[i] == '"' || input[i] == '\'')
				in_q = !in_q;
			input[j] = input[i];
			i++;
			j++;
		}
	}
	input[j] = '\0';
}

void	free_token_lst(t_token **token_lst)
{
	t_token	*tmp;

	tmp = *token_lst;
	while (*token_lst != NULL)
	{
		if (tmp->string)
			free(tmp->string);
		tmp = tmp->next;
		free(*token_lst);
		*token_lst = tmp;
	}
}

// void	print_full_token_data(t_data *data)
// {
// 	t_token	*tmp;
// 	int		i;

// 	tmp = data->token_lst;
// 	i = 0;
// 	while (tmp)
// 	{
// 		printf("TOK %i:%s TOK_TYPE:%d\n",
// 			i, tmp->string, tmp->type);
// 		// printf("TOK %i:%s TOK_TYPE:%d QUOT:%d\n",
// 		// 	i, tmp->string, tmp->type, tmp->quote_type);
// 		i++;
// 		tmp = tmp->next;
// 	}
// }

// void	print_token_string(t_data *data)
// {
// 	t_token	*tmp;
// 	int		i;

// 	tmp = data->token_lst;
// 	i = 0;
// 	while (tmp)
// 	{
// 		printf("%s ", tmp->string);
// 		i++;
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// }
