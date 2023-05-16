/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:28:42 by moduwole          #+#    #+#             */
/*   Updated: 2023/04/23 13:28:42 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_envp	*pathfinder(t_data *data)
{
	t_envp	*env;

	env = data->env_lst;
	while (env && !(!ft_strncmp(env->key, "PATH", 4)
			&& ft_strlen(env->key) == 4))
			env = env->next;
	return (env);
}

void	add_path(t_cmdgroup *group, char **paths)
{
	int		i;
	char	**str;

	i = 0;
	if (!group->cmd || !group->cmd[0] || !access(group->cmd[0], X_OK)
		|| isbuiltin(group))
		return ;
	str = ft_calloc(arrlen(paths) + 1, sizeof(char *));
	while (paths[i])
	{
		if (paths[i][ft_strlen(paths[i]) - 1] != '/')
			str[i] = ft_strjoin2(paths[i], group->cmd[0], '/');
		else
			str[i] = ft_strjoin(paths[i], group->cmd[0]);
		if (access(str[i], X_OK) == 0)
		{
			free(group->cmd[0]);
			group->cmd[0] = ft_strdup(str[i]);
		}
		i++;
	}
	ft_clarr(str);
}

void	get_cmdpath(t_data *data)
{
	t_envp		*env;
	char		**path;
	t_cmdgroup	*group;

	path = NULL;
	group = data->cmdgroup;
	env = pathfinder(data);
	if (!env)
		return ;
	path = ft_split(env->value, ':');
	while (group)
	{
		add_path(group, path);
		group = group->next;
	}
	ft_clarr(path);
}
