/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:31:13 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/29 12:19:44 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft_int.h"

int	ft_match(const char *str, size_t i)
{
	if (str[i] == '%' && str[i + 1] && (str[i + 1] == 'c' || str[i + 1] == 's'
			|| str[i + 1] == 'p' || str[i + 1] == 'd' || str[i + 1] == 'i'
			|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%'
			|| str[i + 1] == 'u'))
		return (1);
	return (0);
}

static void	ft_nextvar(const char *str, size_t *i, size_t *z)
{
	while (str[*i])
	{
		if (ft_match(str, (*i)))
			return ;
		write(1, &str[*i], 1);
		(*z)++;
		(*i)++;
	}
}

static size_t	ft_which(va_list args, const char *s, size_t *i, size_t z)
{
	if (!s[(*i)])
		return (z);
	if (s[(*i)] && s[(*i)] == '%' && s[(*i) + 1] == 's')
		ft_putstr((va_arg(args, char *)), &z);
	else if (s[(*i)] && s[(*i)] == '%' && s[(*i) + 1] == 'c')
		ft_putchar((unsigned char)va_arg(args, int), &z);
	else if (s[(*i)] && s[(*i)] == '%' && (s[(*i) + 1] == 'd'
			|| s[(*i) + 1] == 'i'))
		ft_nbase(((int)va_arg(args, int)), "0123456789", &z);
	else if (s[(*i)] && s[(*i)] == '%' && (s[(*i) + 1] == 'u'))
		ft_nbaseu(((size_t)va_arg(args, unsigned int)), "0123456789", &z);
	else if (s[(*i)] && s[(*i)] == '%' && s[(*i) + 1] == 'x')
		ft_nbaseu((size_t)(va_arg(args, unsigned int)), "0123456789abcdef", &z);
	else if (s[(*i)] && s[(*i)] == '%' && s[(*i) + 1] == 'X')
		ft_nbaseu((size_t)(va_arg(args, unsigned int)), "0123456789ABCDEF", &z);
	else if (s[(*i)] && s[(*i)] == '%' && s[(*i) + 1] == 'p')
		ft_ptr((va_arg(args, void *)), &z);
	else if (s[(*i)] == '%' && s[(*i) + 1] == '%')
		z += write(1, "%", 1);
	(*i) += 2;
	return (z);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	z;
	size_t	i;

	i = 0;
	z = 0;
	va_start(args, str);
	while (str[i])
	{
		ft_nextvar(str, &i, &z);
		z = ft_which(args, str, &i, z);
	}
	va_end(args);
	return (z);
}
