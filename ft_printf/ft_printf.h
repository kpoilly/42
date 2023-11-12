/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:12:55 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/12 13:22:10 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "unistd.h"
# include "stdarg.h"

int		ft_printf(char *input, ...);
int		ft_putchar(char c);
int		ft_putstrlen(char *str);
int		ft_putptr(void *ptr);
void	ft_putnbr_base(size_t nb, char *base, int *len);
void	ft_putnbr_long(long int nb, int *len);

#endif