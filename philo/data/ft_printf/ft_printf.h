/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:12:55 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/16 11:51:30 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(int fd, const char *input, ...);
int		ft_strlen(const char *s);
int		ft_putchar(int fd, char c);
void	ft_putstr(int fd, char *s);
int		ft_putstrlen(int fd, char *str);
int		ft_putptr(int fd, void *ptr);
void	ft_putnbr_base(int fd, size_t nb, char *base, int *len);
void	ft_putnbr_long(int fd, long int nb, int *len);
void	ft_putnbr_unsigned(int fd, unsigned int nb, int *len);

#endif