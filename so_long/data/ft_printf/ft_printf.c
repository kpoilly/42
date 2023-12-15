/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:03:37 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/15 18:05:38 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list args, char c, int *len)
{
	if (c == 'c')
		*len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		*len += ft_putstrlen(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_long(va_arg(args, int), len);
	else if (c == 'p')
		*len += ft_putptr(va_arg(args, void *));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned long), len);
	else if (c == 'x')
		ft_putnbr_base((unsigned int)va_arg(args, int),
			"0123456789abcdef", len);
	else if (c == 'X')
		ft_putnbr_base((unsigned int)va_arg(args, int),
			"0123456789ABCDEF", len);
	else if (c == '%')
		*len += ft_putchar('%');
	return (*len);
}

int	ft_printf(const char *input, ...)
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
			ft_check_format(args, *(input + 1), &len);
			input++;
		}
		else
			len += ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (len);
}
