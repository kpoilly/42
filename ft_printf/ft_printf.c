/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:03:37 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/16 11:23:41 by kpoilly          ###   ########.fr       */
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

/* int	main(void)
{
	int a = -1;
	int *ptr = &a;

	printf("%s\n", 0);
	printf("vraie: %X\n", a);
	ft_printf("ft:    %X\n", a);

	printf("vr: %d\n", printf("%u", 9223372036854775807));
	printf("ft: %d\n", ft_printf("%u", 9223372036854775807));

	printf("vraie: %d\n", a);
	ft_printf("ft:    %d\n", a);
	printf("vraie: %%\n");
	ft_printf("ft:    %%\n");
	printf("vraie: %x\n", a);
	ft_printf("ft:    %x\n", a);
	printf("vraie: %X\n", a);
	ft_printf("ft:    %X\n", a);
	printf("vraie: %p\n", NULL);
	ft_printf("ft:    %p\n", NULL);

	printf("vraie: %u\n", a);
	ft_printf("ft:    %u\n", a);
	ft_printf("len: %d\n", printf("vraie:      %s%c  %% %p %d%c %x %s %X\n", "Adress mem", ':', ptr, a, ':', a, "ou", a));
	printf("len: %d\n", ft_printf("ft:         %s%c  %% %p %d%c %x %s %X\n", "Adress mem", ':', ptr, a, ':', a, "ou", a));
} */
