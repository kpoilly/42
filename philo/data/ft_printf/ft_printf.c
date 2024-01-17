/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:03:37 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 11:10:38 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(int fd, va_list args, char c, int *len)
{
	if (c == 'c')
		*len += ft_putchar(fd, va_arg(args, int));
	else if (c == 's')
		*len += ft_putstrlen(fd, va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_long(fd, va_arg(args, long), len);
	else if (c == 'p')
		*len += ft_putptr(fd, va_arg(args, void *));
	else if (c == 'u')
		ft_putnbr_unsigned(fd, va_arg(args, unsigned long), len);
	else if (c == 'x')
		ft_putnbr_base(fd, (unsigned int)va_arg(args, int),
			"0123456789abcdef", len);
	else if (c == 'X')
		ft_putnbr_base(fd, (unsigned int)va_arg(args, int),
			"0123456789ABCDEF", len);
	else if (c == '%')
		*len += ft_putchar(fd, '%');
	return (*len);
}

int	ft_printf(int fd, const char *input, ...)
{
	va_list	args;
	int		len;

	if (!input)
		return (0);
	len = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%' && *(input + 1))
		{
			ft_check_format(fd, args, *(input + 1), &len);
			input++;
		}
		else
			len += ft_putchar(fd, *input);
		input++;
	}
	va_end(args);
	return (len);
}
