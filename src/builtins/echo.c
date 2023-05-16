/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:46:30 by moduwole          #+#    #+#             */
/*   Updated: 2023/04/03 16:46:30 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(char **s)
{
	int		i;
	char	**str;

	i = 0;
	if (arrlen(s) == 1)
	{
		printf("\n");
		g_exit_status = 0;
		return ;
	}
	str = &s[1];
	if (str)
	{
		if (!ft_strncmp(str[i], "-n", 2) && ft_strlen(str[i]) == 2)
			str = &str[1];
		while (str[i])
		{
			printf("%s", str[i++]);
			if (str[i])
				printf(" ");
		}
	}
	if (!(!ft_strncmp(s[1], "-n", 2) && ft_strlen(s[1]) == 2))
		printf("\n");
	g_exit_status = 0;
}
