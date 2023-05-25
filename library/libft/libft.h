/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:22:41 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/04/14 11:51:44 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//==================GNL========================//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//==================GNL=END====================//

# include <string.h>
/* library for read, write, close, (lseek) */
# include <unistd.h>
/* library for malloc*/
# include <stdlib.h>
/* library for printf*/
# include <stdio.h> 
/* library for open*/
# include <fcntl.h>
/* library for ft_printf*/
# include <stdarg.h>

//==================LIBFT=FUNC=======================//
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size);
char			**ft_split(const char *s, char c);
char			*ft_itoa(int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
void			ft_strncat(char *dest, char *src, int n);
void			ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnstr(const char *str, const char *needle, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strcpy(char *dest, const char *src);
//==================LIBFT=FUNC=END======================//

//==================LIBFT=FUNC=BONUS======================//
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void*));
int				ft_lstsize(t_list *lst);
//==================LIBFT=FUNC=BONUS=END=====================//

//==================GNL=FUNC=======================//
size_t			gnl_strlen(const char *s);
char			*gnl_newline_found(char *s);
char			*gnl_strjoin(char *s1, char *s2);

char			*reader(int fd, char *hold);
char			*cleaner(char *hold);
char			*garbage_collector(char *hold);
char			*get_next_line(int fd);
//==================GNL=FUNC=END====================//

//===============FT_PRINTF=FUNC====================//
int				ft_write_char(char c);
int				ft_write_str(char *str);
int				ft_write_nbr(int n);
int				ft_write_unsigned_int(unsigned int n);
int				ft_write_ptr(unsigned long int n);
int				ft_write_hex(unsigned int n);
int				ft_write_hex_upper(unsigned int n);

int				format(va_list *ap, char c);

int				ft_printf(const char *s, ...);
//===============FT_PRINTF=FUNC=END===================//
#endif