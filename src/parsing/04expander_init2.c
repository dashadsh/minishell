/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04expander_init2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:01:38 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/16 09:57:39 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*find_envp_value(t_envp *env_lst, char *var_name)
{
	while (env_lst != NULL)
	{
		if (ft_strcmp(env_lst->key, var_name) == 0)
			return (env_lst->value);
		env_lst = env_lst->next;
	}
	return (NULL);
}

char	*create_var_from_token(char *token, t_idx *idx)
{
	char	*var;
	int		var_len;

	var = malloc(ft_strlen(token) + 1);
	if (!token)
	{
		printf("minishell: malloc failed in expander_init2\n");
		g_exit_status = 13;
		return (NULL);
	}
	var_len = 0;
	while (ft_isalnum(token[idx->i]) || token[idx->i] == '_')
	{
		var[var_len++] = token[idx->i];
		idx->i++;
	}
	if (var_len == 0)
	{
		free(var);
		return (NULL);
	}
	var[var_len] = '\0';
	return (var);
}

void	copy_env_var_value(char **new_ptr, t_idx *idx, char *env_var)
{
	ft_strcpy(&(*new_ptr)[idx->j], env_var);
	idx->j += ft_strlen(env_var);
}

void	init_env_var(char **new_ptr, t_idx *idx, char *token, t_data *data)
{
	char	*var;
	char	*env_var;

	idx->i++;
	var = create_var_from_token(token, idx);
	if (!var)
		return ;
	env_var = find_envp_value(data->env_lst, var);
	if (env_var != NULL)
		copy_env_var_value(new_ptr, idx, env_var);
	free(var);
}
