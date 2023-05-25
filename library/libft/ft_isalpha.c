/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:07:47 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/04/14 13:07:57 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
alphabetic character test

Tests for any character for which isupper(3) or islower(3) is true.
*/

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Test: 'a'\tOriginal: %d\tMy function: %d\n", 
	isalpha('a'), ft_isalpha('a'));
	printf("Test: '0'\tOriginal: %d\tMy function: %d\n", 
	isalpha('0'), ft_isalpha('0'));
	printf("Test: '\t'\tOriginal: %d\tMy function: %d\n", 
	isalpha('\t'), ft_isalpha('\t'));
	printf("Test: 256\tOriginal: %d\tMy function: %d\n", 
	isalpha(256), ft_isalpha(256));
	return (0);
}
*/