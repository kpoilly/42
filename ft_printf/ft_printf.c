/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:03:37 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/12 16:38:31 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (*(input + 1) == 'c')
				len += ft_putchar(va_arg(args, int));
			else if (*(input + 1) == 's')
				len += ft_putstrlen(va_arg(args, char *));
			else if (*(input + 1) == 'd' || *(input + 1) == 'i')
				ft_putnbr_long(va_arg(args, int), &len);
			else if (*(input + 1) == 'p')
				len += ft_putptr(va_arg(args, void *));
			else if (*(input + 1) == 'u')
				ft_putnbr_long(va_arg(args, unsigned long), &len);
			else if (*(input + 1) == 'x')
				ft_putnbr_base((unsigned int)va_arg(args, int),
					"0123456789abcdef", &len);
			else if (*(input + 1) == 'X')
				ft_putnbr_base((unsigned int)va_arg(args, int),
					"0123456789ABCDEF", &len);
			else if (*(input + 1) == '%')
				len += ft_putchar('%');
			input++;
		}
		else
			len += ft_putchar(*input);
		input++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	int a = -42;
	int *ptr = &a;


	printf("vraie: %d\n", a);
	ft_printf("ft:    %d\n", a);
	/* printf("vraie: %%\n");
	ft_printf("ft:    %%\n");
	printf("vraie: %x\n", a);
	ft_printf("ft:    %x\n", a);
	printf("vraie: %X\n", a);
	ft_printf("ft:    %X\n", a);
	printf("vraie: %p\n", ptr);
	ft_printf("ft:    %p\n", ptr); */

	printf("vraie: %u\n", a);
	ft_printf("ft:    %u\n", a);
	ft_printf("len: %d\n", printf("vraie:      %s%c  %% %p %d%c %x %s %X\n", "Adress mem", ':', ptr, a, ':', a, "ou", a));
	printf("len: %d\n", ft_printf("ft:         %s%c  %% %p %d%c %x %s %X\n", "Adress mem", ':', ptr, a, ':', a, "ou", a));
}
