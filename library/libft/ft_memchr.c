/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:42:15 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 18:07:57 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
locate byte in byte string

Locates the first occurrence of c (converted to an unsigned char) 
in string s.

Returns a pointer to the byte located, or NULL if no such byte 
exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Goodbye, this cruel world!";
	printf("memchr: %p\t ft_memchr: %p\n", 
	memchr(str, 'd', 4), ft_memchr(str, 'd', 4));
	printf("memchr: %p\t\t ft_memchr: %p\n", 
	memchr(str, 'd', 3), ft_memchr(str, 'd', 3));
	printf("memchr: %p\t ft_memchr: %p\n", 
	memchr(str, 'G', 100), ft_memchr(str, 'G', 100));
	return (0);
}
*/