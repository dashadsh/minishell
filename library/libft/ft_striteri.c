/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:51:40 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 18:12:18 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Applies the function ’f’ on each character of
the string passed as argument, passing its index
as first argument.  Each character is passed by
address to ’f’ to be modified if necessary.
*/
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	index = 0;
	if (!s || !f)
		return ;
	while (s[index])
	{
		f(index, s + index);
		index++;
	}
}

/*
#include <stdio.h>

void f(unsigned int i, char *str)
{
	printf("inner function: i = %d string = %s\n",
	i, str);
}

int main()
{
	char str[15] = "doesn't change";
	printf("The result %s:\n", str);
	ft_striteri(str, f);
	return 0;
}
*/

/*
f(index, s + index)
is the same as:
f(index, &s[index])
*/