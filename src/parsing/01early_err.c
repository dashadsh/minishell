/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01early_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:04:29 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/10 12:16:35 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/// @brief checks if there are any errors in the input string 
/// before executing any commands. 
/// 
/// It calls other functions to check for various types of errors
/// such as spaces, quotes, pipes, special characters, and redirection. 
/// If any of these functions return an error code of -1,
/// the function returns -1.
/// Otherwise, it returns 0 to indicate that there are no errors.
/// @param data 
/// @return -1 on error
int	early_err(t_data *data)
{
	char	*input;

	input = data->input;
	if ((ft_strlen(data->input) == 0))
		return (-1);
	else if (spaces_err(input) == -1)
		return (-1);
	else if ((quotes_err(input) == -1)
		|| (pipes_err(input) == -1)
		|| (spec_char_err(input) == -1)
		|| (redirection_err(input) == -1))
		return (-1);
	return (0);
}
