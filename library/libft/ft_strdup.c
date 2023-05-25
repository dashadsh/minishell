/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:00:32 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/01/15 18:04:14 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
save a copy of a string

Allocates sufficient memory for a copy of the string s1,
does the copy, and returns a pointer to it.  
The pointer may subsequently be used as an argument to the function free(3).
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

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = malloc(ft_strlen(s1) + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, (ft_strlen(s1) + 1));
	return (copy);
}

/*
#include <stdio.h>

int main()
{
	printf("%s\n", ft_strdup("goodbye this cruel word!"));
	return (0);
}
*/