/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:35:42 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 16:30:14 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>

char	f(unsigned int i, char c) // prototyping inner f
{
	printf("inner function: i = %d char = %c\n", i, c);
	if ((c >= 'a' && c <= 'z'))
         return (c - ('a' - 'A'));
	i++;
	return (0);
}

int main()
{
	char str[15] = "capitalize";
	
	printf("%s\n", str);
	printf("%s\n", ft_strmapi(str, f));
	return 0;
}
*/