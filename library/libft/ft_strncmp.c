/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:08:22 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 18:12:50 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
compare  lexicographically the null-terminated strings s1 and s2 strings

return an integer greater than, equal to, or less than 0, according as the
string s1 is greater than, equal to, or less than the string s2.  
The comparison is done using unsigned characters, 
so that ‘\200’ is greater than ‘\0’
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

/*
#include <stdio.h>
#include <string.h>

int main ()
{
	printf("test: (ABCD, ABDD, 3)\tstrncmp: %d\t, ft_strncmp: %d\n", 
	strncmp("ABCD", "ABDD", 3), ft_strncmp("ABCD", "ABDD", 3));
	printf("test: (ABCD, ABCY, 3)\tstrncmp: %d\t, ft_strncmp: %d\n", 
	strncmp("ABCD", "ABCY", 3), ft_strncmp("ABCD", "ABCY", 3));
	printf("test: (ABDD, ABCD, 3)\tstrncmp: %d\t, ft_strncmp: %d\n", 
	strncmp("ABDD", "ABCD", 3), ft_strncmp("ABDD", "ABCD", 3));
	return (0);
}
*/

/*
return ((unsigned char)s1[i] - (unsigned char)s2[i]); 
- the same
*/