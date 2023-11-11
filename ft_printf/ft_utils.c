/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:12:08 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/11 22:56:21 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base((size_t)ptr, "0123456789abcdef");
}

void	ft_putnbr_base(size_t nb, char *base)
{
	size_t	nbbase;

	nbbase = ft_strlen(base);
	if (nb >= nbbase)
	{
		ft_putnbr_base((nb / nbbase), base);
		ft_putnbr_base((nb % nbbase), base);
	}
	else
		ft_putchar_fd(base[nb], 1);
}
