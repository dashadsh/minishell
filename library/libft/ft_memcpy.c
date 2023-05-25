/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:00:34 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/01 14:05:54 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Copy memory area

Copies n bytes from memory area src to memory area dst.
If dst and src overlap, behavior is undefined.
Applications in which dst and src might overlap should use 
memmove(3) instead.

Returns the original value of dst
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	char dst[] = "oooooooooo"; // char *dst - bus error
	char src[] = "XXXXXXXOOO";
	size_t i = 3;

	printf("memcpy: %p\tft_memcpy: %p\n", 
	memcpy(dst, src, i), ft_memcpy(dst, src, i));

	char *origin = memcpy(dst, src, i);
	printf("string after memcpy: %s\n", origin);

	char *custom = ft_memcpy(dst, src, i);
	printf("string after ft_memcpy: %s\n", custom);
	return (0);
}
*/