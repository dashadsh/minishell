/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:34:57 by moduwole          #+#    #+#             */
/*   Updated: 2023/04/24 16:34:57 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	here_doc2(char *delimeter)
{
	char	*str;
	int		fd;

	sig_heredoc();
	fd = open("here_doc.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	str = readline(">");
	while (ft_strncmp(str, delimeter, ft_strlen(delimeter))
		|| ft_strlen(delimeter) != ft_strlen(str))
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
		str = readline(">");
	}
	free(str);
	close(fd);
	exit(1);
}

int	here_doc(char *delimeter)
{
	int		pid;
	int		chexit;

	chexit = 1;
	pid = fork();
	if (pid == 0)
	{
		here_doc2(delimeter);
	}
	else
	{
		sig_parent_heredoc2();
		waitpid(pid, &chexit, 0);
		if (WIFEXITED(chexit))
			return (1);
	}
	return (0);
}

void	outfile_handler(t_cmdgroup *group)
{
	t_outs	*outs;

	outs = group->outs;
	while (outs)
	{
		if (outs->append)
			group->outfile = open(outs->str, O_WRONLY | O_CREAT | O_APPEND,
					0777);
		else
			group->outfile = open(outs->str, O_WRONLY | O_CREAT | O_TRUNC,
					0777);
		if (group->outfile == -1)
		{
			printf("minishell: %s: %s\n", outs->str, strerror(errno));
			g_exit_status = 1;
			return ;
		}
		outs = outs->next;
	}
}

int	infile_handler(t_cmdgroup *group)
{
	t_ins	*ins;

	ins = group->ins;
	while (ins)
	{
		if (ins->heredoc)
		{
			if (!here_doc(ins->str))
				return (0);
			group->infile = open("here_doc.txt", O_RDONLY);
		}
		else
			group->infile = open(ins->str, O_RDONLY);
		if (group->infile == -1)
		{
			printf("minishell: %s: %s\n", ins->str, strerror(errno));
			g_exit_status = 1;
			return (1);
		}
		ins = ins->next;
	}
	return (1);
}

int	init_fds(t_data *data)
{
	t_cmdgroup	*group;

	group = data->cmdgroup;
	while (group)
	{
		group->outfile = 1;
		if (group->ins)
			if (!infile_handler(group))
				return (0);
		if (group->outs)
			outfile_handler(group);
		pipe(group->pipe);
		group = group->next;
	}
	return (1);
}
