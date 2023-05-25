/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:25:12 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/04/14 11:27:56 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter.  The array must end
with a NULL pointer.
Return - the array of new strings resulting from the split.
NULL if the allocation fails.
*/

#include "libft.h"

/* NEW VERSION OF FT_SPLIT W/O USING EXTRA FUNCTIONS */
/* count words by checking if it's the last letter 
of the word (next = c or next = NULL) */
size_t	ft_word_counter(const char *s, char c)
{
	size_t	word_counter;

	if (!*s)
		return (0);
	word_counter = 0;
	while (*s)
	{
		if (*s != c && ((*(s + 1)) == c || (*(s + 1)) == '\0'))
			word_counter++;
		s++;
	}
	return (word_counter);
}

/*
1. count word length + allocate memory for it 
(incl NULL terminator)
2. copies chars from an original str to new placem return ptr to it
3. nothing is happening to orig. string  - 
we need to move among that using ft_split function
*/
char	*ft_write_words(const char *str, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
1. count words using ft_word_counter + allocate memory for that
*/
char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	words = ft_word_counter(s, c);
	splitted = malloc(sizeof(char *) * (words + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		splitted[i] = ft_write_words(s, c);
		while (*s && *s != c)
			s++;
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}

/*************************************************/
/*
size_t	ft_word_counter(const char *s, char c)
{
	size_t	word_counter;

	if (!*s)
		return (0);
	word_counter = 0;
	while (*s)
	{
		if (*s != c && ((*(s + 1)) == c || (*(s + 1)) == '\0'))
			word_counter++;
		s++;
	}
	return (word_counter);
}

size_t	ft_wordlen(const char *s, char c)
{
	size_t	wordlen;

	if (!ft_strchr(s, c))
		wordlen = ft_strlen(s);
	else
		wordlen = ft_strchr(s, c) - s;
	return (wordlen);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	i;

	if (!s)
		return (NULL);
	array = (char **)ft_calloc(ft_word_counter(s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			array[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!array[i])
				return (NULL);
		}
		s += ft_wordlen(s, c);
		i++;
	}
	return (array);
}
*/

/***************************************************/

/*
size_t	ft_word_counter(const char *s, char c)
{
	size_t	word_counter;

	if (!*s)
		return (0);
	word_counter = 0;
	while (*s)
	{
		if (*s != c && ((*(s + 1)) == c || (*(s + 1)) == '\0'))
			word_counter++;
		s++;
	}
	return (word_counter);
}

size_t	ft_wordlen(const char *s, char c)
{
	size_t	wordlen;

	if (!ft_strchr(s, c))
		wordlen = ft_strlen(s);
	else
		wordlen = ft_strchr(s, c) - s;
	return (wordlen);
}

void	ft_free(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

char	*ft_putword(char **array, const char *s, char c, int i)
{
	array[i] = ft_substr(s, 0, ft_wordlen(s, c));
	if (!array[i])
	{
		(ft_free(array));
		return (NULL);
	}
	return (array[i]);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	i;

	if (!s)
		return (NULL);
	array = (char **)ft_calloc(ft_word_counter(s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			ft_putword(array, s, c, i);
		s += ft_wordlen(s, c);
		i++;
	}
	return (array);
}
*/

/*
#include <stdio.h>

void	free_2d(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

int	main(void)
{
    char *str = "goodbye, this cruel world              ";
    char c = ' ';
	int i = 0;
    char **output;
	
    output = ft_split(str, c);
	printf("string \"%s\" after ft_split:\n", str);
    while (output[i])
        printf("%s\n", output[i++]);
	free_2d(output);
}
*/