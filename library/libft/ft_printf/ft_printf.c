/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:56:30 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/12/06 23:45:44 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* c s d i u p x X % */

/*
detects the formatting flag, passes the value
to the corresponding function

returns sum of char
*/

/*
SIC! call-by reference (va_list *ap) is needed for ARM architecture,
otherwise call-by value (va_list ap) would be enough.

on ARM architecture when passing 'ap' to another function and using it again
there will be return back to first argument
*/

int	ft_format(char c, va_list *ap)
{
	int	sum;

	sum = 0;
	if (c == '%')
		sum += write(1, "%", 1);
	else if (c == 'c')
		sum += ft_write_char(va_arg(*ap, int));
	else if (c == 's')
		sum += ft_write_str(va_arg(*ap, char *));
	else if ((c == 'd') || (c == 'i'))
		sum += ft_write_nbr(va_arg(*ap, int));
	else if (c == 'u')
		sum += ft_write_unsigned_int(va_arg(*ap, unsigned int));
	else if (c == 'x')
		sum += ft_write_hex(va_arg(*ap, unsigned int));
	else if (c == 'X')
		sum += ft_write_hex_upper(va_arg(*ap, unsigned int));
	else if (c == 'p')
		sum += ft_write_ptr(va_arg(*ap, unsigned long int));
	return (sum);
}

/* 
reads all func. args
if % is encountered calles ft_format function to format output
else ptints chars of the string passed as 1st argument.
*/

/*
SIC! call-by reference (ft_format(*str, &ap)) is needed for ARM architecture,
otherwise call-by value (ap) would be enough.
*/

int	ft_printf(const char *str, ...)
{
	int		sum;
	va_list	ap;

	sum = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			sum += ft_format(*str, &ap);
		}
		else
			sum += ft_write_char(*str);
		str++;
	}
	va_end(ap);
	return (sum);
}

/*
int main()
{
	ft_printf("hello, %s", "bitcccches");
	ft_printf("hello, %s", "bitcccches");
}
*/