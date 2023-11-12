/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:12:08 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/12 13:24:40 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstrlen(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_putptr(void *ptr)
{
	int	len;

	len = 2;
	ft_putstr_fd("0x", 1);
	ft_putnbr_base((size_t)ptr, "0123456789abcdef", &len);
	return (len);
}

void	ft_putnbr_base(size_t nb, char *base, int *len)
{
	size_t	nbbase;

	nbbase = ft_strlen(base);
	if (nb >= nbbase)
	{
		ft_putnbr_base((nb / nbbase), base, len);
		ft_putnbr_base((nb % nbbase), base, len);
	}
	else
		*len += ft_putchar(base[nb]);
}

void	ft_putnbr_long(long int nb, int *len)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr_long(nb / 10, len);
		ft_putnbr_long(nb % 10, len);
	}
	else
		*len += ft_putchar((nb + '0'));
}
