/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:12:08 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/16 11:39:46 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putptr(int fd, void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		len += ft_putstrlen(fd, "(nil)");
	else
	{
		len += 2;
		ft_putstr(fd, "0x");
		ft_putnbr_base(fd, (size_t)ptr, "0123456789abcdef", &len);
	}
	return (len);
}
