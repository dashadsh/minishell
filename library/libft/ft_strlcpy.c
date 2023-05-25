/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:25:24 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 00:14:27 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
size-bounded string copying

take the full size of the destination buffer
and guarantee NUL-termination if there is room. 
Note that room for the NUL should be included in dstsize.

copies up to dstsize - 1 characters from the string src to dst, 
NUL-terminating the result if dstsize is not 0.

return the total length of the string they tried to create - 
the length of src.
*/

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	char dst[] = "oooooooooo"; // char *dst - bus error
	char src[] = "XXXXXXXOOO";
	size_t n = 3;

	size_t origin = strlcpy(dst, src, n);
	size_t custom = ft_strlcpy(dst, src, n);
	printf("strlcpy: %lu\n", origin);
	printf("ft_strlcpy: %zu\n", custom);
	return (0);
}
*/