/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:40:56 by cagonzal          #+#    #+#             */
/*   Updated: 2022/05/09 12:44:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/uio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	struct s_list	*prev;
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
int		ft_lstsize(t_list *lst);
int		ft_printf(const char *str, ...);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, unsigned int n);
int		ft_strend_cmp(char *name, char *end);
int		ft_chartable_linecount(char **table);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *));

char	*ft_itoa(int n);
char	*get_next_line(int fd);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_lstadd_after(t_list *prevlst, t_list *new);
void	ft_lstadd_front(t_list **head, t_list *new);
void	ft_lstadd_back(t_list **head, t_list *new);
void	ft_lstdelone(t_list **head, t_list *del);
void	ft_lstclear(t_list **head);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_free_chartable(char **table);
void	*ft_memset(void *dst, int c, int i);
void	*ft_memcpy(void *dst, const void *src, unsigned int n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, unsigned int len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif