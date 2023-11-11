/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:12:55 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/11 22:56:04 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "unistd.h"
# include "stdarg.h"

void	ft_putptr(void *ptr);
void	ft_putnbr_base(size_t nb, char *base);
void	ft_printf(char *input, ...);

#endif