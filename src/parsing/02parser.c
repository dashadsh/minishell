/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:00:16 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/10 11:44:14 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parser(t_data *data)
{
	remove_consequtive_quotes(data->input);
	tokenizer(&data->token_lst, data->input);
	expand_token_lst(data);
}
