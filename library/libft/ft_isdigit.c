/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:08:04 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/24 23:41:03 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
decimal-digit character test
*/

int	ft_isdigit(int c)
{
	return ((c >= '0' ) && (c <= '9'));
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Test: 'a'\tOriginal: %d\tMy function: %d\n", 
	isdigit('a'), ft_isdigit('a'));
	printf("Test: '0'\tOriginal: %d\tMy function: %d\n", 
	isdigit('0'), ft_isdigit('0'));
	printf("Test: '\t'\tOriginal: %d\tMy function: %d\n", 
	isdigit('\t'), ft_isdigit('\t'));
	printf("Test: 256\tOriginal: %d\tMy function: %d\n", 
	isdigit(256), ft_isdigit(256));
	return (0);
}
*/