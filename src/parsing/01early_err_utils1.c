/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01early_err_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:01:17 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/04 15:01:19 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/// @brief checks if the string contains only spaces.
int	spaces_err(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
		i++;
	if (input[i] == '\0')
		return (-1);
	return (0);
}

/// @brief checks for mismatched quotes in the input string.
int	quotes_err(char *s)
{
	int	dq_open;
	int	sq_open;
	int	i;

	i = 0;
	dq_open = 0;
	sq_open = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'' && !dq_open && !sq_open)
			sq_open = 1;
		else if (s[i] == '"' && !dq_open && !sq_open)
			dq_open = 1;
		else if (s[i] == '\'' && !dq_open && sq_open)
			sq_open = 0;
		else if (s[i] == '"' && dq_open && !sq_open)
			dq_open = 0;
		i++;
	}
	if (dq_open || sq_open)
		return (printf("minishell: unsupported open quotes\n"), -1);
	return (0);
}

/// @brief checks if there are any errors related to pipes in the input command.
int	pipes_err(char *input)
{
	int	i;

	i = 0;
	while (input[i] == ' ')
		i++;
	if (input[i] == '|')
		return (printf("minishell: token error: `|'\n"), -1);
	while (input[i] != '\0')
	{
		if (input[i] == '\'')
			i += skip_quotes(&input[i], '\'');
		else if (input[i] == '"')
			i += skip_quotes(&input[i], '"');
		else if (input[i] == '|')
		{
			i++;
			while (input[i] == ' ')
				i++;
			if (input[i] == '|' || input[i] == '\0')
				return (printf("minishell: token error: `|'\n"), -1);
		}
		else
			i++;
	}
	return (0);
}

/// @brief minishell supports limited amt of special chars outside quotes:
/// pipe, and redirections.
/// couldn't add # ‘ ´ here
/// @param input 
/// @return -1 on error
int	spec_char_err(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\'')
			i += skip_quotes(&input[i], '\'');
		else if (input[i] == '"')
			i += skip_quotes(&input[i], '"');
		else if (input[i] == ';' || input[i] == '&'
			|| input[i] == '\\' || input[i] == '*'
			|| input[i] == '~' || input[i] == '%'
			|| input[i] == '(' || input[i] == ')'
			|| input[i] == '[' || input[i] == ']'
			|| input[i] == '{' || input[i] == '}'
			|| input[i] == '^' || input[i] == '`')
		{
			return (printf("minishell: unsupported special char\n"), -1);
		}
		else
			i++;
	}
	return (0);
}

/// @brief minishell supports > >> < << only, 
/// no redirection on the end of input, 
/// no redirection before pipe
/// @param input 
/// @return -1 on error
int	redirection_err(char *input)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (input[i] != '\0' && value != -1)
	{
		if (input[i] == '\'')
			i += skip_quotes(&input[i], '\'');
		else if (input[i] == '"')
			i += skip_quotes(&input[i], '"');
		else if (input[i] == '<' && input[i + 1] != '<')
			value = redirection_err_s_in(input, &i);
		else if (input[i] == '>' && input[i + 1] != '>')
			value = redirection_err_s_out(input, &i);
		else if (input[i] == '<' && input[i + 1] == '<')
			value = redirection_err_d_in(input, &i);
		else if (input[i] == '>' && input[i + 1] == '>')
			value = redirection_err_d_out(input, &i);
		else
			i++;
	}
	if (value == -1)
		return (-1);
	return (0);
}
