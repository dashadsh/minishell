/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:55:11 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/07/20 11:18:34 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.

Returns the new string.
NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		return (ft_strdup(s + start));
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s + start, len);
	copy[len] = '\0';
	return (copy);
}

/* MEM KO
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	if (s == NULL || ft_strlen(s) < start)
		return (ft_strdup(""));
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
*/

/*
#include <stdio.h>

int main()
{	
	char str[12] = "synthesizer";
	printf("\"%s\", after ft_substr - \"%s\"\n", str, ft_substr(str, 3, 3));
	return (0);	
}
*/