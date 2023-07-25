/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nested.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:29:21 by moduwole          #+#    #+#             */
/*   Updated: 2023/05/24 18:29:21 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_len(t_envp *env)
{
	int		i;
	t_envp	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	*ft_update(char *value)
{
	int	n;

	n = ft_atoi(value);
	n++;
	return (ft_itoa(n));
}

void	nested_error(t_cmdgroup *group)
{
	group->infile = -1;
	g_exit_status = 127;
	printf("minishell: %s: no such file or directory\n", group->cmd[1]);
}

int	ft_nested(t_data *data, t_cmdgroup	*group)
{
	t_envp	*env;
	char	**str;
	char	*tmp;
	int		i;

	if (arrlen(group->cmd) > 1)
		return (nested_error(group), 1);
	env = data->env_lst;
	str = ft_calloc(sizeof(char *), env_len(env) + 3);
	str[0] = ft_strdup(group->cmd[0]);
	str[1] = ft_strdup("nested");
	i = 2;
	while (env)
	{
		if (!ft_strncmp(env->key, "SHLVL", 5))
		{
			tmp = ft_update(env->value);
			str[i++] = ft_strjoin2(env->key, tmp, '=');
			free(tmp);
		}
		else
			str[i++] = ft_strjoin2(env->key, env->value, '=');
		env = env->next;
	}
	return (ft_clarr(group->cmd), group->cmd = str, 1);
}
