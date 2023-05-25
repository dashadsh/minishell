/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:08:32 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 00:43:09 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lower case to upper case letter conversion

returns the corresponding upper-case letter if there is one;
otherwise, the argument is returned unchanged.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("test 'a' - ASCII 97\ttoupper: %d\tft_toupper: %d\n", 
	toupper('a'), ft_toupper('a'));
	printf("test 'A' - ASCII 65\ttoupper: %d\tft_toupper: %d\n", 
	toupper('A'), ft_toupper('A'));
	return (0);
}
*/