/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:40:35 by moduwole          #+#    #+#             */
/*   Updated: 2023/04/05 14:40:35 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unset_free(t_envp *ptr)
{
	free(ptr->key);
	free(ptr->value);
	free(ptr);
}

int	check(char **key)
{
	if (key[1][0] == '=' || key[1][0] == '?' || key[1][0] == '-')
	{
		g_exit_status = 1;
		printf("-minishell: unset: '%s': not a valid identifier\n", key[1]);
		return (0);
	}
	return (1);
}

int	ft_unset(t_data *data, char **key)
{
	t_envp	*ptr;
	t_envp	*ptr2;

	ptr = data->env_lst;
	g_exit_status = 0;
	if (!check(key))
		return (0);
	if (!ft_strncmp(ptr->key, key[1], ft_strlen(key[1]))
		&& ft_strlen(ptr->key) == ft_strlen(key[1]))
	{
		data->env_lst = ptr->next;
		return (unset_free(ptr), 1);
	}
	while (ptr->next)
	{
		ptr2 = ptr->next;
		if (!ft_strncmp(ptr2->key, key[1], ft_strlen(key[1]))
			&& ft_strlen(ptr2->key) == ft_strlen(key[1]))
		{
			ptr->next = ptr2->next;
			return (unset_free(ptr2), 1);
		}
		ptr = ptr->next;
	}
	return (1);
}
