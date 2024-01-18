/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:52:19 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/18 17:36:05 by marvin           ###   ########.fr       */
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

void	check_nbeat(t_global *global, t_philosopher *philo)
{
	if (philo->nb_meals == global->nb_eat)
	{
		global->nb_full++;
		philo->nb_meals++;
		printf("%ldms : Every Philosophers ate enough.\n",
			get_time_ms(global->start));
	}
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
