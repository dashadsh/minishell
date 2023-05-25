/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:18:19 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/12/06 23:46:25 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* writes unsigned int value, returns the length */
int	ft_write_unsigned_int(unsigned int n)
{
	long		long_n;
	int			length;

	long_n = (long)n;
	length = 0;
	if (long_n / 10)
		length += ft_write_unsigned_int(long_n / 10);
	long_n = long_n % 10 + '0';
	length += write(1, &long_n, 1);
	return (length);
}
