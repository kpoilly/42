/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:47:38 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/13 17:51:20 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	nb = 0;
	while (ft_isdigit(nptr[i]))
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}
