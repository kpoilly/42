/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:06:45 by lleciak           #+#    #+#             */
/*   Updated: 2024/03/06 13:14:11 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int			ft_printf(int fd, const char *format, ...);
int			ft_putnbr_u(unsigned int nb, int *len, int fd);
int			ft_putchara(char c, int fd);
int			ft_putstr(char *str, int fd);
int			print_null(int fd);
int			ft_nb_base(size_t nb, int *len, char *base, int fd);
int			ftprint_ptr(void *ptr, int fd);
int			ft_putnbr_d_i(long int nb, int *len, int fd);
int			ft_strlen(const char *s);

#endif