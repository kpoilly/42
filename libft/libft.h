/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:11:24 by marvin            #+#    #+#             */
/*   Updated: 2023/09/10 10:11:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int				ft_isalpha(char c);
int				ft_isdigit(char c);
int				ft_isalnum(char c);
int				ft_isascii(char c);
int				ft_isprint(char c);
int				ft_strlen(const char *str);
void			*ft_memset(void *mem, int oct, size_t n);
void			ft_bzero(void *mem, size_t n);
void			*ft_memcpy(void *dest, void *src, size_t n);
void			*ft_memmove(void *dest, void *src, size_t n);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
int				ft_toupper(char c);
int				ft_tolower(char c);
char			*ft_strchr(const char *str, char c);
char			*ft_strrchr(const char *str, char c);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
void			*ft_memchr(const void *mem, int c, size_t n);
int				memcmp(const void *mem1, const void *mem2, size_t n);
char			*ft_strnstr(char *big, char *little, size_t n);
int				ft_atoi(char *str);
void			*ft_calloc(size_t nelem, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif