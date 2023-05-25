/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:13:39 by moduwole          #+#    #+#             */
/*   Updated: 2023/05/23 18:13:39 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exit_n(char *str)
{
	int	n;

	n = ft_atoi(str);
	if (n > 255)
		n %= 256;
	else if (n < 0)
	n += 256;
	return (n);
}

int	ft_exit(t_data *data, t_cmdgroup *group, char **str)
{
	if (group->prev || group->next)
		return (1);
	printf("exit\n");
	if (arrlen(str) == 1)
		return (g_exit_status = 0, exit_free(data), 1);
	if (arrlen(str) > 1)
	{
		if (!((str[1][0] >= '0' && str[1][0] <= '9') || str[1][0] == '-'))
		{
			printf("minishell: exit: %s: numeric argument required\n", str[1]);
			return (g_exit_status = 2, exit_free(data), 1);
		}
		else if (arrlen(str) > 2)
		{
			printf("minishell: exit: too many arguments\n");
			return (g_exit_status = 1, exit_free(data), 1);
		}
		else
			return (g_exit_status = exit_n(str[1]), exit_free(data), 1);
	}	
	return (1);
}
