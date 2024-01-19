/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:58:55 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/19 15:19:20 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

void	*philo_routine(void *thing)
{
	t_global		*global;
	t_philosopher	*philo;

	global = (t_global *)thing;
	pthread_mutex_lock(&global->mutex);
	philo = global->current;
	pthread_mutex_unlock(&global->mutex);
	printf("%ldms : Philo #%d woke up\n", get_time_ms(global->start),
		philo->id);
	while (philo->alive && global->active)
	{
		if (get_time_ms(philo->last_eat) > global->time_die)
			return (ft_die(philo, global), NULL);
		if (philo->prev && !philo->prev->eating
			&& philo->next && !philo->next->eating)
		{
			philo->thinking = 0;
			if (!ft_eat(philo, global) || !ft_sleep(philo, global))
				return (NULL);
		}
		ft_think(philo, global);
	}
	return (NULL);
}

int	ft_eat(t_philosopher *philo, t_global *global)
{	
	if (global->active)
	{
		printf("%ldms : Philo #%d has taken a fork\n",
			get_time_ms(global->start), philo->id);
		pthread_mutex_lock(&global->mutex);
		philo->eating = 1;
		pthread_mutex_unlock(&global->mutex);
		gettimeofday(&philo->last_eat, NULL);
		printf("%ldms : Philo #%d is eating\n", get_time_ms(global->start),
			philo->id);
		if (global->time_eat > global->time_die)
			return (usleep((global->time_die) * 1000),
				ft_die(philo, global), 0);
		usleep(global->time_eat * 1000);
		printf("%ldms : Philo #%d put down a fork\n",
			get_time_ms(global->start), philo->id);
		if (philo->nb_meals < global->nb_eat)
			philo->nb_meals++;
	}
	pthread_mutex_lock(&global->mutex);
	philo->eating = 0;
	pthread_mutex_unlock(&global->mutex);
	return (check_nbeat(global, philo), 1);
}

int	ft_sleep(t_philosopher *philo, t_global *global)
{	
	if (global->active)
	{	
		philo->sleeping = 1;
		printf("%ldms : Philo #%d is sleeping\n", get_time_ms(global->start),
			philo->id);
		if (global->time_eat + global->time_sleep > global->time_die)
			return (usleep((global->time_die - global->time_eat)
					* 1000), ft_die(philo, global), 0);
		usleep(global->time_sleep * 1000);
		philo->sleeping = 0;
	}
	return (1);
}

void	ft_think(t_philosopher *philo, t_global *global)
{
	if (!philo->thinking)
	{
		philo->thinking = 1;
		printf("%ldms : Philo #%d is thinking\n",
			get_time_ms(global->start), philo->id);
	}
}

void	ft_die(t_philosopher *philo, t_global *global)
{
	pthread_mutex_lock(&global->mutex);
	philo->eating = 0;
	philo->thinking = 0;
	philo->sleeping = 0;
	global->active = 0;
	pthread_mutex_unlock(&global->mutex);
	printf("%ldms : Philo #%d died\n", get_time_ms(global->start),
		philo->id);
	philo->alive = 0;
}
