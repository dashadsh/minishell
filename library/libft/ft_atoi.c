/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:07:07 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/05/25 18:08:13 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
convert ASCII string to integer

Converts the initial portion of the string 
pointed to by str to int representation.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + ((int)*str - '0');
		str++;
	}
	return (num * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("Test: 123\t\tatoi: %d\t\tft_atoi: %d\n", 
	atoi("123"), ft_atoi("123"));
	printf("Test: -2147483648\tatoi: %d\tft_atoi: %d\n", 
	atoi("-2147483648"), ft_atoi("-2147483648"));
	printf("Test: 0\t\t\tatoi: %d\t\t\tft_atoi: %d\n", 
	atoi("0"), ft_atoi("0"));
	printf("Test:  	-789\t\tatoi: %d\t\tft_atoi: %d\n", 
	atoi(" 	-789"), ft_atoi(" 	-789"));
	printf("Test: 	-+--789\t\tatoi: %d\t\t\tft_atoi: %d\n", 
	atoi(" 	-+--789"), ft_atoi(" 	-+--789"));
	return (0);
}
*/