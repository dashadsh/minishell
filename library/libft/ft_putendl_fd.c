/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:25:10 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/30 19:43:09 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the string ’s’ to the given file descriptor
followed by a newline.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

/*
#include <stdio.h>

int main()
{
	ft_putendl_fd("print string and newline", 1);
	ft_putstr_fd("print string and no newline", 1);
	return(0);
}
*/