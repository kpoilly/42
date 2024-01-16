/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:31:11 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/16 11:37:54 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_long(int fd, long int nb, int *len)
{
	if (nb < 0)
	{
		nb *= -1;
		*len += ft_putchar(fd, '-');
	}
	if (nb > 9)
	{
		ft_putnbr_long(fd, nb / 10, len);
		ft_putnbr_long(fd, nb % 10, len);
	}
	else
		*len += ft_putchar(fd, (nb + '0'));
}

void	ft_putnbr_unsigned(int fd, unsigned int nb, int *len)
{
	if (nb > 9)
	{
		ft_putnbr_long(fd, nb / 10, len);
		ft_putnbr_long(fd, nb % 10, len);
	}
	else
		*len += ft_putchar(fd, (nb + '0'));
}

void	ft_putnbr_base(int fd, size_t nb, char *base, int *len)
{
	size_t	nbbase;

	nbbase = ft_strlen(base);
	if (nb >= nbbase)
	{
		ft_putnbr_base(fd, (nb / nbbase), base, len);
		ft_putnbr_base(fd, (nb % nbbase), base, len);
	}
	else
		*len += ft_putchar(fd, base[nb]);
}
