/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:23:10 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/12 15:41:29 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft_int.h"

void	ft_putnbr(size_t nb, size_t base_t, char *base, size_t *z)
{
	if (nb < base_t)
	{
		write(1, &base[nb], 1);
		(*z)++;
	}
	else
	{
		ft_putnbr(nb / base_t, base_t, base, z);
		ft_putnbr(nb % base_t, base_t, base, z);
	}
}

void	ft_nbase(int nbr, char *base, size_t *z)
{
	size_t		i;
	size_t		j;
	long long	nb;

	nb = nbr;
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return ;
		while (base[j])
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
	if (nb < 0)
		(*z) += write(1, "-", 1);
	if (nb < 0)
			nb *= -1;
	ft_putnbr((size_t) nb, i, base, z);
}

void	ft_nbaseu(size_t nbr, char *base, size_t *z)
{
	size_t		i;
	size_t		j;
	size_t		nb;

	nb = nbr;
	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return ;
		while (base[j])
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
	ft_putnbr((size_t)nb, i, base, z);
}

void	ft_putstr(char *str, size_t *z)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		(*z) += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
		i++;
	write(1, str, i);
	(*z) += i;
}

void	ft_putchar(unsigned char c, size_t *z)
{
	write(1, &c, 1);
	(*z)++;
}
