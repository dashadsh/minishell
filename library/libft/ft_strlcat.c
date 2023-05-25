/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:06:53 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 01:48:23 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
size-bounded string concatenation

take the full size of the destination buffer and guarantee NUL-
termination if there is room.  Note that room for the NUL 
should be included in dstsize.

appends string src to the end of dst.  It will append at most dstsize -
strlen(dst) - 1 characters.  
It will then NUL-terminate, unless dstsize is 0 or 
the original dst string was longer than dstsize.

If the src and dst strings overlap, the behavior is undefined.

RETURNS the total length of the string tried to create,
that means the initial length of dst plus the length of src
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;

	i = 0;
	dstlen = (ft_strlen(dst));
	if (size <= dstlen)
		return (ft_strlen(src) + size);
	while (src[i] && dstlen + i + 1 < size)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (ft_strlen(src) + dstlen);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
    char	dst[9] = "moog";
	char	src[] = "music";
    size_t n = 2;
	//size_t origin = strlcpy(dst, src, n);
	//size_t custom = ft_strlcpy(dst, src, n);
	printf("strlcat: %lu\n", strlcat(dst, src, n));
	printf("ft_strlcat: %zu\n", ft_strlcat(dst, src, n));
	printf("%s", dst);
}
*/