/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:07:54 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/24 23:52:13 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
test for ASCII character

tests for an ASCII character, which is any character 
between 0 and octal 0177 inclusive.
*/

int	ft_isascii(int c)
{
	return ((c >= 0) && (c <= 127));
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Test: 'a'\tOriginal: %d\tMy function: %d\n", 
	isascii('a'), ft_isascii('a'));
	printf("Test: 'z'\tOriginal: %d\tMy function: %d\n", 
	isascii('z'), ft_isascii('z'));
	printf("Test: '0'\tOriginal: %d\tMy function: %d\n", 
	isascii('0'), ft_isascii('0'));
	printf("Test: '\t'\tOriginal: %d\tMy function: %d\n", 
	isascii('\t'), ft_isascii('\t'));
	printf("Test: -1\tOriginal: %d\tMy function: %d\n", 
	isascii(-1), ft_isascii(-1));
	printf("Test: 256\tOriginal: %d\tMy function: %d\n", 
	isascii(256), ft_isascii(256));
	return (0);
}
*/