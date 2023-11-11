/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:03:37 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/11 22:57:23 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(char *input, ...)
{
	va_list	args;

	va_start(args, input);
	while (*input)
	{
		if (*input == '%' && *(input + 1))
		{
			if (*(input + 1) == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (*(input + 1) == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (*(input + 1) == 'd' || *(input + 1) == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (*(input + 1) == 'p')
				ft_putptr(va_arg(args, void *));
			else if (*(input + 1) == 'u')
				ft_putnbr_fd((unsigned int)va_arg(args, int), 1);
			else if (*(input + 1) == 'x')
				ft_putnbr_base((unsigned int)va_arg(args, int),
					"0123456789abcdef");
			else if (*(input + 1) == 'X')
				ft_putnbr_base((unsigned int)va_arg(args, int),
					"0123456789ABCDEF");
			else if (*(input + 1) == '%')
				ft_putchar_fd('%', 1);
			input++;
		}
		else
			ft_putchar_fd(*input, 1);
		input++;
	}
	va_end(args);
}


/*int	main(void)
{
	int a = 42;
	int *ptr = &a;

	printf("vraie: %%\n");
	ft_printf("ft:    %%\n");
	printf("vraie: %x\n", a);
	ft_printf("ft:    %x\n", a);
	printf("vraie: %X\n", a);
	ft_printf("ft:    %X\n", a);
	printf("vraie: %p\n", ptr);
	ft_printf("ft:    %p\n", ptr);
	printf("vraie: %u\n", -a);
	ft_printf("ft:    %u\n", -a);
	printf("vraie:      %s%c  %% %p %d%c %x %s %X\n", "Adress mem", ':', ptr, a, ':', a, "ou", a);
	ft_printf("ft:         %s%c  %% %p %d%c %x %s %X\n", "Adress mem", ':', ptr, a, ':', a, "ou", a);
}*/
