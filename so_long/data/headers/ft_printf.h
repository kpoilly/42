/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:12:55 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/14 12:33:52 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "so_long.h"

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *input, ...);
int		ft_strlen(char *s);
int		ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_putstrlen(char *str);
int		ft_putptr(void *ptr);
void	ft_putnbr_base(size_t nb, char *base, int *len);
void	ft_putnbr_long(long int nb, int *len);
void	ft_putnbr_unsigned(unsigned int nb, int *len);

#endif