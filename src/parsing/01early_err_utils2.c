/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01early_err_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:04:08 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/04 15:04:17 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/// @brief checks if a '<' character in a given string 's'
/// is properly used as an input redirection operator. 
/// If not, it returns an error message and a value of -1. 
///
///Otherwise, it updates the value of 'i' and returns the new value.
/// @param s 
/// @param i 
/// @return 
int	redirection_err_s_in(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 1]) + 1;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{
		return (printf("minishell: token error: `<'\n"), -1);
	}
	return (*i);
}

/// @brief checks if a '>' character in a given string 's'
/// is properly used as an output redirection operator.
/// If not, it returns an error message and a value of -1.
///
/// Otherwise, it updates the value of 'i' and returns the new value.
/// @param s 
/// @param i 
/// @return 
int	redirection_err_s_out(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 1]) + 1;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{
		return (printf("minishell: token error: `>'\n"), -1);
	}
	return (*i);
}

/// @brief  checks if a '<<' sequence in a given string 's'
/// is properly used as an input redirection operator.
/// If not, it returns an error message and a value of -1.
///
/// Otherwise, it updates the value of 'i' and returns the new value.
/// @param s 
/// @param i 
/// @return 
int	redirection_err_d_in(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 2]) + 2;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{		
		return (printf("minishell: token error: `<<'\n"), -1);
	}
	return (*i);
}

/// @brief  checks if a '>>' sequence in a given string 's'
/// is properly used as an output redirection operator.
/// If not, it returns an error message and a value of -1.
///
/// Otherwise, it updates the value of 'i' and returns the new value.
/// @param s 
/// @param i 
/// @return 
int	redirection_err_d_out(char *s, int *i)
{
	*i += skip_spaces(&s[*i + 2]) + 2;
	if (s[*i] == '\0' || s[*i] == '|' || s[*i] == '>' || s[*i] == '<')
	{
		return (printf("minishell: token error: `>>'\n"), -1);
	}
	return (*i);
}
