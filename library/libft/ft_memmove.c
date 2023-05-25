/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:19:51 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/01/15 18:02:02 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Copy byte string

Function copies len bytes from string src to string dst. 
The two strings may overlap;

If (src < dst) copy from back to front, 
if (src > dst) use ft_memcpy.

Returns the original value of dst
*/

#include "libft.h"

/*
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
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	else if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	char dst[] = "12345"; // char *dst - bus error
	char src[] = "abcdefgah";
	size_t i = 3;

	printf("memmove: %p\tft_memmove: %p\n", memmove(dst, src, i), 
	ft_memmove(dst, src, i));

	char *origin = memmove(dst, src, i);
	printf("string after memmove: %s\n", origin);

	char *custom = ft_memmove(dst, src, i);
	printf("string after ft_memmove: %s\n", custom);
	return (0);
}
*/