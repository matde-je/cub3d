/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:44:31 by acuva-nu          #+#    #+#             */
/*   Updated: 2024/04/06 14:21:28 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*-------------- HEADERS -----------------*/
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*-------------- STRUCTS -----------------*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*-------------- FUNCTIONS ----------------*/
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t len);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
void				*ft_calloc(size_t nmemb, size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
int					ft_wordcount(char const *s, char c);
char				*ft_strjoin(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);

/*-------------- ADDITIONAL FUNCTIONS ----------------*/

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

int					ft_wordcount1(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
/*-------------- BONUS FUNCTIONS ----------------*/
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

/*----------------------------- PRINTF---------------------*/
int					ft_c(int c);
int					ft_s(const char *str);
int					ft_di(int n);
int					ft_u(unsigned int n);
int					ft_hexing(unsigned long int n, char *b);
int					ft_x(unsigned int n, char c);
int					ft_p(unsigned int long n);
int					ft_printf(const char *fmt, ...);

#endif
