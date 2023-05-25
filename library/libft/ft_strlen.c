/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:57:18 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/04/22 00:31:15 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
find length of string
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char *str = "STRING";
	char *str2 = "";
	printf("strlen: %ld\t ft_strlen: %ld\n", strlen(str), ft_strlen(str));
	printf("strlen: %ld\t ft_strlen: %ld\n", strlen(str2), ft_strlen(str2));
	return (0);
}
*/