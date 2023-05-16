/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 10:17:33 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/12/06 23:46:06 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* writes hex value in uppercase, returns the length */
int	ft_write_hex_upper(unsigned int n)
{
	unsigned int	digit;
	int				length;

	digit = 0;
	length = 0;
	if (n / 16)
		length += ft_write_hex_upper(n / 16);
	digit = n % 16;
	length += write(1, &"0123456789ABCDEF"[digit], 1);
	return (length);
}
