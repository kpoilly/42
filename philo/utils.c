/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:52:19 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 14:24:22 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

long	get_time_ms(struct timeval start)
{	
	struct timeval	current;
	time_t			ret;

	gettimeofday(&current, NULL);
	ret = current.tv_sec - start.tv_sec;
	ret = ((ret * 1000000) + (current.tv_usec - start.tv_usec)) / 1000;
	return (ret);
}

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
		return (-1);
	while (ft_isdigit(nptr[i]))
		nb = (nb * 10) + (nptr[i++] - '0');
	return (nb);
}
