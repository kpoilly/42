/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:39:07 by lleciak           #+#    #+#             */
/*   Updated: 2024/03/25 09:35:29 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_d_i(long int nb, int *len, int fd)
{
	if (nb < 0)
	{
		nb *= -1;
		*len += ft_putchara('-', fd);
	}
	if (nb >= 10)
	{
		ft_putnbr_d_i(nb / 10, len, fd);
		ft_putnbr_d_i(nb % 10, len, fd);
	}
	else
	{
		*len += ft_putchara(nb + '0', fd);
	}
	return (*len);
}

int	ft_putnbr_u(unsigned int nb, int *len, int fd)
{
	if (nb >= 10)
	{
		ft_putnbr_u(nb / 10, len, fd);
		ft_putnbr_u(nb % 10, len, fd);
	}
	else
	{
		*len += ft_putchara(nb + '0', fd);
	}
	return (*len);
}

int	ft_nb_base(size_t nb, int *len, char *base, int fd)
{
	size_t	len_base;

	len_base = ft_strlen(base);
	if (nb >= len_base)
	{
		ft_nb_base(nb / len_base, len, base, fd);
		ft_nb_base(nb % len_base, len, base, fd);
	}
	else
	{
		*len += ft_putchara(base[nb], fd);
	}
	return (*len);
}

int	ftprint_ptr(void *ptr, int fd)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len += write(1, "0x", 2);
	ft_nb_base((size_t)ptr, &len, "0123456789abcdef", fd);
	return (len);
}
