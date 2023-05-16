/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:25:50 by moduwole          #+#    #+#             */
/*   Updated: 2023/05/03 11:25:50 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_ins(t_ins **ptr)
{
	t_ins	*tmp;

	tmp = *ptr;
	while (tmp)
	{
		free(tmp->str);
		*ptr = tmp->next;
		free(tmp);
		tmp = *ptr;
	}
}

void	free_outs(t_outs **ptr)
{
	t_outs	*tmp;

	tmp = *ptr;
	while (tmp)
	{
		free(tmp->str);
		*ptr = tmp->next;
		free(tmp);
		tmp = *ptr;
	}
}

void	free_cmdgroup(t_data *data)
{
	t_cmdgroup	*tmp;

	tmp = data->cmdgroup;
	while (tmp)
	{
		if (tmp->cmd)
			ft_clarr(tmp->cmd);
		if (tmp->ins)
			free_ins(&tmp->ins);
		if (tmp->outs)
			free_outs(&tmp->outs);
		if (tmp->str)
			free(tmp->str);
		data->cmdgroup = tmp->next;
		free(tmp);
		tmp = data->cmdgroup;
	}
}

void	exit_free(t_data *data)
{
	t_envp	*env;

	env = data->env_lst;
	if (data->input)
		free(data->input);
	while (env)
	{
		free(env->key);
		free(env->value);
		data->env_lst = env->next;
		free(env);
		env = data->env_lst;
	}
	free(data);
	exit(1);
}

void	exec_free(t_data *data)
{
	unlink("here_doc.txt");
	free(data->input);
	free_token_lst(&data->token_lst);
	free_cmdgroup(data);
}
