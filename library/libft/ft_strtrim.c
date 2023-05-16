/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:43:31 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/30 16:04:15 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function allocates (with malloc())) and returns a copy of ’s1’ with the
characters specified in ’set’ removed from the beginning and the end of 
the string */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	str = ft_substr((char *)s1, 0, len + 1);
	return (str);
}

/*
#include <stdio.h>

int main()
{
	char *string = "ABCddddddABC";
	char *del = "ABC";
	char *string2 = "QWERTYqwertyEEEERRRRTTTT";
	char *del2 = "QWERTY";
	
	printf ("%s - %s = %s\n", 
	string, del, ft_strtrim(string, del));	
	printf ("%s - %s = %s\n",
	string2, del2, ft_strtrim(string2, del2));
	return (0);
}
*/