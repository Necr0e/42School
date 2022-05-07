/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:30:50 by oseitama          #+#    #+#             */
/*   Updated: 2022/04/22 11:06:43 by oseitama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<string.h>
# include	<stdlib.h>
# include	<unistd.h>

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void	ft_bzero(void *src, size_t len);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
void	ft_strclr(char *str);
void	ft_striter(char *src, void (*f)(char *));
void	ft_striteri(char *src, void (*f)(unsigned int, char *));
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(const char *str);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putendl(const char *str);
void	ft_putendl_fd(const char *str, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void	ft_lstrev(t_list **alst);
void	*ft_memset(void *ptr, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memccpy(void *dest, const void *src, int c,	size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *ptr, int c, size_t len);
void	*ft_memalloc(size_t size);

int		ft_memcmp(const void *s1, const void *s2, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
int		ft_atoi(const char *ptr);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strequ(const char *s1, const char *s2);
int		ft_strnequ(const char *s1, const char *s2, size_t len);
int		ft_isspace(char c);
int		ft_wordlen(const char *src, char c);
int		ft_wordcount(const char *src, char c);

char	*ft_strdup(const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t len);
char	*ft_strchr(const char *src, int c);
char	*ft_strrchr(const char *src, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char	*haystack, const char *needle, size_t len);
char	*ft_strnew(size_t size);
char	*ft_strmap(const char *src, char (*f)(char));
char	*ft_strmapi(const char *src, char (*f)(unsigned int, char));
char	*ft_strsub(const char *src, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *src);
char	*ft_itoa(int n);
char	**ft_strsplit(const char *src, char c);

size_t	ft_strlen(const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_lstcount(t_list *lst);

t_list	*ft_lstnew(const void *content, size_t content_size);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif