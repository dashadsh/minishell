/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:24:34 by moduwole          #+#    #+#             */
/*   Updated: 2023/03/29 00:24:34 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	issmaller(char *str, char *str2)
{
	int	i;

	i = 0;
	if (!str2)
		return (1);
	while (str[i] && str2[i])
	{
		if (str[i] < str2[i])
			return (1);
		else if (str[i] > str2[i])
			return (0);
		i++;
	}
	if (str[i] && !str2[i])
		return (0);
	return (1);
}

t_envp	*set_min(t_data *data)
{
	t_envp	*tmp;

	tmp = data->env_lst;
	while (tmp)
	{
		if (!tmp->sorted)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	export_print(t_data *data)
{
	t_envp	*tmp;
	t_envp	*tmp2;
	t_envp	*min;

	tmp = data->env_lst;
	while (tmp)
	{
		tmp2 = data->env_lst;
		min = set_min(data);
		while (tmp2)
		{
			if (!issmaller(min->key, tmp2->key)
				&& !tmp2->sorted)
				min = tmp2;
			tmp2 = tmp2->next;
		}
		min->sorted = 1;
		printf("declare -X %s=", min->key);
		printf("\"%s\"\n", min->value);
		tmp = tmp->next;
	}
}

int	is_update(t_data *data, char *key, char *value)
{
	t_envp	*ptr;

	ptr = data->env_lst;
	while (ptr)
	{
		if (!ft_strncmp(ptr->key, key, ft_strlen(key))
			&& ft_strlen(ptr->key) == ft_strlen(key))
		{
			if (!(!ft_strncmp(ptr->value, value, ft_strlen(value))
					&& ft_strlen(ptr->value) == ft_strlen(value)))
			{
				free(ptr->value);
				ptr->value = ft_strdup(value);
			}
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}

int	export(t_data *data, char **var)
{
	char	**str;
	char	*ptr;
	char	*tmp;

	g_exit_status = 0;
	if (arrlen(var) == 1)
		return (export_print(data), reset(data), 1);
	ptr = ft_strchr(var[1], '=');
	if (!ptr)
		return (0);
	if (var[1][0] == '=' || var[1][0] == '?' || var[1][0] == '-')
	{
		g_exit_status = 1;
		return (printf("minishell: export: '%s': not a valid identifier\n",
				var[1]), 0);
	}
	tmp = ft_strdup2(var[1], ptr - var[1]);
	str = ft_split(var[1], '\0');
	if (!is_update(data, tmp, ptr + 1))
		envplist_handler(&data->env_lst, str);
	free(tmp);
	ft_clarr(str);
	return (1);
}
