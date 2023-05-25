/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:20:50 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 18:13:08 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
locate last occurence of character c in string

The terminating null character is
considered to be part of the string; therefore if c is ‘\0’, 
the functions locate the terminating ‘\0’.

return a pointer to the located character, 
or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Goodbye, this cruel world!";
	printf("strrchr: %p\t ft_strrchr: %p\n", 
	strrchr(str, 'd'), ft_strrchr(str, 'd'));
	printf("strrchr: %p\t\t ft_strrchr: %p\n", 
	strrchr(str, 'x'), ft_strrchr(str, 'x'));
	printf("strrchr: %p\t ft_strrchr: %p\n", 
	strrchr(str, 'G'), ft_strrchr(str, 'G'));
	return (0);
}
*/