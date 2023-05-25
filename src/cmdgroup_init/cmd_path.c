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

int	ft_isnested(char *s1)
{
	int		i;
	int		j;
	char	s2[10];

	j = 0;
	ft_strcpy(s2, "minishell");
	if (!s1 || !s1[0] || access(s1, X_OK))
		return (1);
	if (ft_strlen(s1) == 9)
		i = 0;
	else if (ft_strlen(s1) > 9)
		i = ft_strlen(s1) - 9;
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

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
	env = NULL;
	group = data->cmdgroup;
	env = pathfinder(data);
	if (env)
		path = ft_split(env->value, ':');
	while (group)
	{
		if (!ft_isnested(group->cmd[0]))
			ft_nested(data, group);
		else if (path)
			add_path(group, path);
		group = group->next;
	}
	ft_clarr(path);
}
