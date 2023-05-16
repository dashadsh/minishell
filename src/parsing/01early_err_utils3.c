/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01early_err_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:04:19 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/04 15:04:21 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/// @brief function takes a string as input and 
/// returns the index of the first non-space character in the string.
/// @param str 
/// @return index of the first non-space character in the string.
int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

/// @brief  This function takes a string and a quote character as input and
/// returns the index of the first character after the end of the quoted string.
/// @param str 
/// @param quote 
/// @return the value of 'i' plus 1 to skip the closing quote character.
int	skip_quotes(char *str, char quote)
{
	int	i;

	i = 1;
	while (str[i] != quote)
		i++;
	return (i + 1);
}
