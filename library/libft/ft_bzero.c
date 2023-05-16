/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 14:54:55 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/30 12:52:05 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
write zeroes to a byte string

Writes n zeroed bytes to the string s.  
If n is zero, does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

/*
#include <stdio.h>
#include <strings.h>
 
int	main()
{
	char	origin[11] = "xxxxxOOOOO";
	char	custom[11] = "xxxxxOOOOO";
	
	bzero(origin, 2);
	ft_bzero(custom, 2);
	
	int i = 0;
	printf("ascii chars after bzero:\n");
	while (i < 11)
		printf("%d ", origin[i++]);
	printf("\n");
	
	i = 0;
	printf("ascii chars after ft_bzero:\n");
	while (i < 11)
		printf("%d ", custom[i++]);
	printf("\n");
	
	printf("remaining string after bzero:\n");
	printf("%s\n", origin + 2);
	
	printf("remaining string after ft_bzero:\n");
	printf("%s\n", custom + 2);
	return (0);
}
*/

/* 
in main() ("%s", str) doesn't show anything because
setting even just the first `char` in the array to 0
results in an empty string.
*/