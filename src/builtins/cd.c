/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:46:13 by moduwole          #+#    #+#             */
/*   Updated: 2023/04/05 12:46:13 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd_home(t_data *data)
{
	t_envp	*ptr;

	ptr = data->env_lst;
	while (ptr && !(!ft_strncmp(ptr->key, "HOME", 4)
			&& ft_strlen(ptr->key) == 4))
		ptr = ptr->next;
	if (!ptr || chdir(ptr->value))
	{
		if (!ptr)
			printf("minishell: cd: HOME not set\n");
		else
			printf("minishell: cd: %s: %s\n", ptr->value, strerror(errno));
		g_exit_status = 1;
	}
	else
		g_exit_status = 0;
}

void	ft_cd(t_data *data, char **str)
{
	g_exit_status = 0;
	if (arrlen(str) > 2)
	{
		printf("minishell: cd: too many arguments\n");
		g_exit_status = 1;
	}
	else if (arrlen(str) == 1)
		cd_home(data);
	else if (chdir(str[1]))
	{
		printf("minishell: cd: %s: %s\n", str[1], strerror(errno));
		g_exit_status = 1;
	}
}
