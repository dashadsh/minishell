/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbuiltin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:24:55 by moduwole          #+#    #+#             */
/*   Updated: 2023/04/28 15:24:55 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	isbuiltin(t_cmdgroup *group)
{
	char	**str;

	if (!group->cmd || !group->cmd[0])
		return (0);
	str = group->cmd;
	if (!ft_strncmp(str[0], "echo", 4) && ft_strlen(str[0]) == 4)
		return (1);
	if (!ft_strncmp(str[0], "cd", 2) && ft_strlen(str[0]) == 2)
		return (1);
	if (!ft_strncmp(str[0], "pwd", 3) && ft_strlen(str[0]) == 3)
		return (1);
	if (!ft_strncmp(str[0], "export", 6) && ft_strlen(str[0]) == 6)
		return (1);
	if (!ft_strncmp(str[0], "unset", 5) && ft_strlen(str[0]) == 5)
		return (1);
	if (!ft_strncmp(str[0], "env", 3) && ft_strlen(str[0]) == 3)
		return (1);
	return (0);
}

void	execbn(t_data *data, t_cmdgroup *group)
{
	char	**str;

	if (group->infile == -1 || group->outfile == -1)
		return ;
	str = group->cmd;
	if (!ft_strncmp(str[0], "echo", 4) && ft_strlen(str[0]) == 4)
		ft_echo(str);
	if (!ft_strncmp(str[0], "cd", 2) && ft_strlen(str[0]) == 2)
		ft_cd(data, str);
	if (!ft_strncmp(str[0], "pwd", 3) && ft_strlen(str[0]) == 3)
		ft_pwd();
	if (!ft_strncmp(str[0], "export", 6) && ft_strlen(str[0]) == 6)
		export(data, str);
	if (!ft_strncmp(str[0], "unset", 5) && ft_strlen(str[0]) == 5)
		ft_unset(data, str);
	if (!ft_strncmp(str[0], "env", 3) && ft_strlen(str[0]) == 3)
		ft_env(data, str);
}

void	reset(t_data *data)
{
	t_envp	*ptr;

	ptr = data->env_lst;
	while (ptr)
	{
		ptr->sorted = 0;
		ptr = ptr->next;
	}
}
