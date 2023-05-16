/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:22:48 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/04/14 11:23:24 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief copies at most 'n' characters from the string pointed to by 'src'
/// to the memory area pointed to by 'dest'. 
/// If the length of 'src' is less than 'n', 
/// then the remaining characters of 'dest' are filled with null characters.
///
/// @param dest pointer to the memory area where the content is to be copied.
/// @param src pointer to the string which is to be copied.
/// @param n maximum number of characters to be copied from 'src'.
///
/// The function does not return a value.
/// 
/// This function does not check for null pointers.
/// It is the caller's responsibility to ensure that 
/// 'dest' and 'src' point to valid memory locations.
void	ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}
