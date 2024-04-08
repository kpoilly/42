/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:24:09 by lleciak           #+#    #+#             */
/*   Updated: 2024/03/25 09:35:24 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if(int *len, char c, va_list args, int fd)
{
	if (c == 'c')
		*len += ft_putchara(va_arg(args, int), fd);
	if (c == 's')
		*len += ft_putstr(va_arg(args, char *), fd);
	if (c == 'p')
		*len += ftprint_ptr(va_arg(args, void *), fd);
	if (c == 'd' || c == 'i')
		ft_putnbr_d_i((long int)va_arg(args, int), len, fd);
	if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), len, fd);
	if (c == 'x')
		ft_nb_base(va_arg(args, unsigned int), len, "0123456789abcdef", fd);
	if (c == 'X')
		ft_nb_base(va_arg(args, unsigned int), len, "0123456789ABCDEF", fd);
	if (c == '%')
		*len += ft_putchara('%', fd);
	return (*len);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_if(&len, format[i + 1], args, fd);
			i++;
		}
		else
			len += ft_putchara(format[i], fd);
		i++;
	}
	va_end (args);
	return (len);
}
