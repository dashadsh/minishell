/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:16:27 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/23 19:21:15 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_env_value(t_envp *lst, char *key, char *new_value)
{
	t_envp	*ptr;

	ptr = lst;
	while (ptr != NULL)
	{
		if (!ft_strcmp(ptr->key, key))
		{
			free(ptr->value);
			ptr->value = ft_strdup(new_value);
			return ;
		}
		ptr = ptr->next;
	}
}

char	*get_current_dir(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("getcwd");
		return (NULL);
	}
	return (pwd);
}

void	update_oldpwd(t_data *data)
{
	char	*old_pwd;

	old_pwd = get_current_dir();
	if (old_pwd)
	{
		update_env_value(data->env_lst, "OLDPWD", old_pwd);
		free(old_pwd);
	}
}

void	update_pwd(t_data *data)
{
	char	*new_pwd;

	new_pwd = get_current_dir();
	if (new_pwd)
	{
		update_env_value(data->env_lst, "PWD", new_pwd);
		free(new_pwd);
	}
}
