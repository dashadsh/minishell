/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:37:09 by moduwole          #+#    #+#             */
/*   Updated: 2023/04/21 11:37:09 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	arrlen(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	ft_clarr(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*ft_strjoin2(char *s1, char *s2, char c)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!newstr)
		return (NULL);
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[i++] = c;
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	if (s1 && c == '\n')
		free(s1);
	return (newstr);
}
