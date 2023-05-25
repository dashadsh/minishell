/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:08:27 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 00:45:50 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
upper case to lower case letter conversion

returns the corresponding lower-case letter if there is one;
otherwise, the argument is returned unchanged.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("test 'a' - ASCII 97\ttolower: %d\tft_tolower: %d\n", 
	tolower('a'), ft_tolower('a'));
	printf("test 'A' - ASCII 65\ttolower: %d\tft_tolower: %d\n", 
	tolower('A'), ft_tolower('A'));
	return (0);
}
*/