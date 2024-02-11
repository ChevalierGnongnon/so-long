/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:38:22 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/11 10:26:23 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h> 

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_str_stop(char *s, char c);
void	ft_push_left(char *cont);
int		ft_oldline(char **line, size_t nbchar);
int		ft_fill(char *buff, char **line, size_t nbchar);
char	*get_next_line(int fd);
int		ft_char(char c);
int		ft_decimal(int n);
int		ft_getsize(int n);
int		ft_getusize2(unsigned int n);
int		ft_hexaup(unsigned int n);
int		ft_hexalow(unsigned int n);
int		ft_getlsize(unsigned long long add);
int		ft_hexa_add(unsigned long long add);
int		ft_pointer(unsigned long long add);
int		ft_get_format(const char *s, size_t i, va_list args);
int		ft_printf(const char *s, ...);
int		ft_string(char *s);
void	ft_putnbr_unsigned(unsigned int n);
int		ft_getusize(unsigned int n);
int		ft_unsigned(unsigned int n);
int		ft_hexa_up(unsigned int n);
int		ft_hexa_low(unsigned int n);
void	ft_push_left(char *cont);
int		ft_old_line(char **line, size_t nbchar);
int		ft_fill(char *buff, char **line, size_t nbchar);
t_list	*ft_lstnew(void *content);

#endif