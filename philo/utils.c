/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:52:19 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/16 13:51:33 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	nb;

	nb = 0;
	i = 0;
	if (!ft_isdigit(nptr[i]))
		return (ft_printf(2, "Error.\nInvalid arguments.\n"), -1);
	while (ft_isdigit(nptr[i]))
		nb = (nb * 10) + (nptr[i++] - '0');
	return (nb);
}
