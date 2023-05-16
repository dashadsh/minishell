/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:00:43 by moduwole          #+#    #+#             */
/*   Updated: 2023/04/25 15:00:43 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	in_handler(t_cmdgroup *group)
{
	if (group->prev && group->prev->outfile == 1
		&& group->infile == 0 && group->prev->cmd
		&& !isbuiltin(group))
	{
		close(group->prev->pipe[1]);
		dup2(group->prev->pipe[0], STDIN_FILENO);
		close(group->prev->pipe[0]);
	}
	if (group->infile > 0)
		dup2(group->infile, STDIN_FILENO);
}

void	out_handler(t_cmdgroup *group)
{
	if (!isbuiltin(group))
		close(group->pipe[0]);
	if (group->next && group->outfile == 1
		&& (access(group->cmd[0], X_OK) == 0 || isbuiltin(group)))
		dup2(group->pipe[1], STDOUT_FILENO);
	if (group->outfile > 1)
	{
		dup2(group->outfile, STDOUT_FILENO);
		close(group->outfile);
	}
	close(group->pipe[1]);
}

void	in_out_handler(t_cmdgroup *group)
{
	if (group->infile == -1 || group->outfile == -1
		|| !group->cmd || !group->cmd[0])
	{
		if (!isbuiltin(group))
			exit(1);
		return ;
	}
	out_handler(group);
	in_handler(group);
}

void	child_process(t_cmdgroup *group)
{
	if (!group->cmd)
		return ;
	group->pid = fork();
	if (group->pid == 0)
	{
		in_out_handler(group);
		if (execve(group->cmd[0], group->cmd, NULL) == -1)
			printf("minishell: %s: command not found\n", group->cmd[0]);
		exit(127);
	}
}

void	execute(t_data *data)
{
	t_cmdgroup	*group;
	int			stdin;
	int			stdout;

	group = data->cmdgroup;
	while (group)
	{
		sig_noninteractive();
		if (isbuiltin(group))
		{
			stdin = dup(STDIN_FILENO);
			stdout = dup(STDOUT_FILENO);
			in_out_handler(group);
			execbn(data, group);
		}
		else
			child_process(group);
		if (isbuiltin(group))
			ft_default(stdin, stdout);
		else
			pclose_pipes(group);
		group = group->next;
	}
	parent_wait(data->cmdgroup);
}
