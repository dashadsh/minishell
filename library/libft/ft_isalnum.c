/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:07:38 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 18:08:34 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
alphanumeric character test

Tests for any character for which isalpha(3) or isdigit(3) is true
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c)) || (ft_isdigit(c)));
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Test: 'a'\tOriginal: %d\tMy function: %d\n", 
	isalnum('a'), ft_isalnum('a'));
	printf("Test: 'z'\tOriginal: %d\tMy function: %d\n", 
	isalnum('z'), ft_isalnum('z'));
	printf("Test: '0'\tOriginal: %d\tMy function: %d\n", 
	isalnum('0'), ft_isalnum('0'));
	printf("Test: '\t'\tOriginal: %d\tMy function: %d\n", 
	isalnum('\t'), ft_isalnum('\t'));
	printf("Test: -1\tOriginal: %d\tMy function: %d\n", 
	isalnum(-1), ft_isalnum(-1));
	printf("Test: 256\tOriginal: %d\tMy function: %d\n", 
	isalnum(256), ft_isalnum(256));
	return (0);
}
*/