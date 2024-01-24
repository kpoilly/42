/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:58:55 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/24 19:03:29 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/philo_bonus.h"

void	*lt_eat(void *data)
{
	t_global		*global;
	t_philosopher	*philo;

	global = (t_global *)data;
	philo = global->current;
	while (philo->alive && global->active)
	{
		sem_wait(global->forks);
		if ((!philo->alive && !global->active)
			|| !ft_eat(philo, global) || !ft_sleep(philo, global))
			return (NULL);
	}
	return (NULL);
}

int	ft_eat(t_philosopher *philo, t_global *global)
{	
	if (global->active)
	{
		philo->thinking = 0;
		printf("%ldms : Philo #%d has taken a fork\n",
			get_time_ms(global->start), philo->id);
		philo->eating = 1;
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
	sem_post(global->forks);
	philo->eating = 0;
	return (check_nbeat(global, philo), 1);
}

int	ft_sleep(t_philosopher *philo, t_global *global)
{	
	if (global->active)
	{	
		philo->thinking = 0;
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
	philo->alive = 0;
	philo->eating = 0;
	philo->thinking = 0;
	philo->sleeping = 0;
	global->active = 0;
	pthread_mutex_unlock(&global->mutex);
	printf("%ldms : Philo #%d died\n", get_time_ms(global->start),
		philo->id);
	sem_close(global->forks);
}
