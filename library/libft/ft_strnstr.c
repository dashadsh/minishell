/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:46:04 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 10:05:16 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
locate a substring in a string

first occurrence of the null-terminated string needle in 
the null-terminated string haystack, where not more than len
characters are searched

If needle is an empty string, haystack is returned; 
if needle occurs nowhere in haystack, NULL is returned; 
otherwise a pointer to the first character of the first 
occurrence of needle is returned
*/

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle[0] == 0)
		return ((char *)str);
	while ((str[i] != 0) && ((i + needle_len) <= len))
	{
		if (ft_strncmp(str + i, needle, needle_len) == 0)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	printf("('XOxoXOxo','XO', 6)\t strnstr: %p\tft_strntsr: %p\n",
	strnstr("XOxoXOxo","XO", 6), ft_strnstr("XOxoXOxo","XO", 6));

	printf("('XOxoXOxo','xo', 3)\t strnstr: %p\tft_strntsr: %p\n",
	strnstr("XOxoXOxo","xo", 3), ft_strnstr("XOxoXOxo","xo", 3));
	return (0);
}
*/