/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:21:45 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/04/14 11:23:31 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief appends the first n characters of the src string
/// to the end of the dest string.
/// dst must be large enough to accommodate the concatenated string.
/// If the src  is longer than n characters,
/// only the first n characters are appended.
///
/// Note: function does not add a terminating null character 
/// to the concatenated string, so the dst string must be null-terminated
/// before the concatenation. 
///
/// Care must be taken to ensure that the dest is properly initialized 
/// and sized to avoid buffer overflow errors.
void	ft_strncat(char *dest, char *src, int n)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
}
