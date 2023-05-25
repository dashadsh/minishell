/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:10:17 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/30 20:36:50 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
locate character in string

locates the first occurrence of c (converted to a char) 
in the string pointed to by s.
The terminating null character is considered to be part of the string;
therefore if c is ‘\0’, the functions locate the terminating ‘\0’.

Returns a pointer to the located character,
or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Goodbye, this cruel world!";
	printf("strchr: %p\t ft_strchr: %p\n", 
	strchr(str, 'd'), ft_strchr(str, 'd'));
	printf("strchr: %p\t\t ft_strchr: %p\n", 
	strchr(str, 'x'), ft_strchr(str, 'x'));
	printf("strchr: %p\t ft_strchr: %p\n", 
	strchr(str, 'G'), ft_strchr(str, 'G'));
	return (0);
}
*/

/* 
TO BE DISCUSSED: 
why implementation w/o i doesn't work?

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (0);
}
*/