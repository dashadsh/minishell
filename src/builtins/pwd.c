/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:37:39 by moduwole          #+#    #+#             */
/*   Updated: 2023/04/05 13:37:39 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(void)
{
	char	*str;

	str = ft_calloc(1000, sizeof(char));
	printf("%s\n", getcwd(str, 500));
	free(str);
	g_exit_status = 0;
}
