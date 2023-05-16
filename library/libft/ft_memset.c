/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:08:17 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/30 14:51:07 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
fill a byte string with a byte value

Writes len bytes of value c (converted to an unsigned char) to the string b.

Returns its first argument
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

/*
#include <string.h>
#include <stdio.h>

int main (void)
{
	char str[11] = "nnnnnOOOOO"; // *str brings bzs error
	printf("memset: %s\tft_memset: %s\n", (char *)memset(str, 'X', 5), 
	(char *)ft_memset(str, 'X', 5));
	return(0);
}
*/