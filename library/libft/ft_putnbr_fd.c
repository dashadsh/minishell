/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:20:41 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/07/19 11:57:01 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the integer ’n’ to the given file
descriptor.
*/

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	casted_nb;

	casted_nb = nb;
	if (casted_nb < 0)
	{
		ft_putchar_fd('-', fd);
		casted_nb = -casted_nb;
	}
	if (casted_nb < 10)
		ft_putchar_fd(casted_nb + '0', fd);
	else
	{
		ft_putnbr_fd(casted_nb / 10, fd);
		ft_putnbr_fd(casted_nb % 10, fd);
	}
}

/*
void	putdecimal(int n)
{
	long			long_n;

	long_n = (long)n;
	if (long_n < 0)
	{
		write(1, "-", 1);
		long_n = -long_n;
	}
	if (long_n / 10)
		putdecimal(long_n / 10);
	long_n = long_n % 10 + '0'; // long_n %= 10 + '0';
	write(1, &long_n, 1);
}
*/

/*
int	main(void)
{
	ft_putnbr_fd(123, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
*/