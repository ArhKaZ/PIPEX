/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:13:29 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/16 12:30:51 by syluiset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define LOWER_BASE_16	"0123456789abcdef"
# define UPPER_BASE_16X	"0123456789ABCDEF"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_putchar_fd(char c, int fd);

char	**ft_split(char const *s, char c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_itoa(int n);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

int		ft_atoi(const char *nptr);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	ft_bzero(void *s, size_t n);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memset(void *pointer, int value, size_t count);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlen(const char *str);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *string, const char *find, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmenb, size_t size);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_list *lst);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_printf(const char *format, ...);

int		ft_putchar(int c);

int		ft_putstr(char *str);

void	ft_putnbr_10(int nb, int *nbdigit);

void	ft_putunbr_10(unsigned int nb, int *nbdigit);

void	ft_putpointer(size_t nb, int *nbdigit);

void	ft_putnbr_16_low(unsigned int nb, int *nbdigit);

void	ft_putnbr_16_up(unsigned int nb, int *nbdigit);

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
#endif
