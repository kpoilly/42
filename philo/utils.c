/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:52:19 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/19 13:08:08 by kpoilly          ###   ########.fr       */
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

int	check_nbeat(t_global *global, t_philosopher *philo)
{
	if (global->nb_eat && philo->nb_meals == global->nb_eat)
	{
		pthread_mutex_lock(&global->mutex);
		global->nb_full++;
		pthread_mutex_unlock(&global->mutex);
		philo->nb_meals++;
	}
	if (global->nb_eat && global->nb_full == global->nb_philo && global->active)
	{
		if (global->active)
			printf("%ldms : Every Philosophers ate enough.\n",
				get_time_ms(global->start));
		pthread_mutex_lock(&global->mutex);
		global->active = 0;
		pthread_mutex_unlock(&global->mutex);
		return (0);
	}
	return (1);
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

void	wait_process(t_global *global, int nb_process)
{
	int	i;

	pthread_join(global->current->thread, NULL);
	i = 1;
	while (i < nb_process)
	{
		global->current = global->current->next;
		pthread_join(global->current->thread, NULL);
		i++;
	}
}
