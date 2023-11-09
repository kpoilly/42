/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:03:37 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/09 18:31:58 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdarg.h"

void	ft_printf(char *input, ...)
{
	va_list	args;
	int	i = 0;

	va_start(args, input);
	while (*input)
	{
		if (*input == '%' && *(input + 1))
		{
			if (*(input + 1) == 'c')
				ft_putchar_fd(va_arg(args, char), 1);
			if (*(input + 1) == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
			if (*(input + 1) == 'd')
				ft_putnbr_fd(va_arg(args, int), 1);
			input++;
		}
		else
			ft_putchar_fd(*input, 1);
		input++;
	}
	va_end(args);
}


int	main(void)
{
	ft_printf("%d%d%d", 445,995,6);
}
