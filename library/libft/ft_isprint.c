/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:08:10 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/24 23:41:15 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
printing character test (space character inclusive)
*/

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("Test: 'a'\tisprint(: %d\tft_isprint: %d\n", 
	isprint('a'), ft_isprint('a'));
	printf("Test: '0'\tisprint(: %d\tft_isprint: %d\n", 
	isprint('0'), ft_isprint('0'));
	printf("Test: '\t'\tisprint(: %d\tft_isprint: %d\n", 
	isprint('\t'), ft_isprint('\t'));
	printf("Test: -1\tisprint(: %d\tft_isprint: %d\n", 
	isprint(-1), ft_isprint(-1));
	printf("Test: 256\tisprint(: %d\tft_isprint: %d\n", 
	isprint(256), ft_isprint(256));
	return (0);
}
*/