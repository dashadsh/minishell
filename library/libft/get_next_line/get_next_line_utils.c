/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:02:05 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/12/06 23:41:13 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_newline_found(char *s)
{
	size_t		i;

	if (s)
	{
		i = 0;
		while (s[i] && s[i] != '\n')
			i++;
		if (s[i] == '\n')
			return ((char *)s + i);
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}
