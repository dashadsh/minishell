/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04expander_init1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:01:38 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/10 11:50:20 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_exit_status(char **new_ptr, t_idx *idx)
{
	char	*exit_status;

	exit_status = get_exit_status();
	ft_strcpy(&(*new_ptr)[idx->j], exit_status);
	idx->j += ft_strlen(exit_status);
	free(exit_status);
	idx->i += 2;
}

/// @brief function replaces PID expansion => displays $ instead of $$
/// @param new_ptr 
/// @param idx 
void	init_single_dollar(char **new_ptr, t_idx *idx)
{
	(*new_ptr)[(idx->j)++] = '$';
	idx->i += 2;
}

void	copy_token_char(char **new_ptr, t_idx *idx, char c)
{
	(*new_ptr)[(idx->j)++] = c;
}
