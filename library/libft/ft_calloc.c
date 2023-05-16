/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:50:24 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/01/15 17:59:38 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memory allocation

Allocates enough space for count objects that are size bytes of memory each.

Returns a pointer to the allocated memory. 
The allocated memory is filled with bytes of value zero.
function erases n bytes of memory starting at location pointed to by s.
*/

#include "libft.h"

/*
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}
*/

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*str;

	if (count >= 4294967295 || size >= 4294967295)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

/*
#include <stdio.h>

int	main(void)

{
	int	amount = 5;
	int *ptr = (int *)ft_calloc(amount, sizeof(int));
	int	i = 0;
	
	while (i < amount)
		printf("%d ", ptr[i++]);
	printf("\n");
	free(ptr);
	return (0);
}
*/

/*
#include <stdio.h>

int	main(void)
{
char *a = NULL;
unsigned int i;
unsigned int count;
unsigned int size;

count = 4000000000;
size = 2;
a = calloc(count, size);
i = -1;
printf("my:\n");
while (++i < count * size)
	printf("%c\n", a[i]);
i = -1;
return 0;
}
*/