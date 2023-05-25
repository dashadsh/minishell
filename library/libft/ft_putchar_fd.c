/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:57:50 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 16:50:00 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Rather than automatically writing to the standard output, we
choose if we want the to use a file descriptor obtained from the open
system call, or we use 0, 1, or 2, to refer to the standard input, standard
output, or standard error, respectively.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <stdio.h>

int main()
{
	printf("65 to standard input 0 is:\n");
	ft_putchar_fd(65, 0);
	ft_putchar_fd('\n', 1);
	printf("66 to standard output 1 is:\n");
	ft_putchar_fd(66, 1);
	ft_putchar_fd('\n', 1);
	printf("'C' to standard output 1 is:\n");
	ft_putchar_fd('C', 1);
	ft_putchar_fd('\n', 1);
	printf("68 to standard error 2 is:\n");
	ft_putchar_fd(68, 2);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/