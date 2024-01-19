/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:58:55 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/19 01:53:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

void	*philo_routine(void *thing)
{
	t_global		*global;
	t_philosopher	*philo;

	global = (t_global *)thing;
	philo = global->current;
	printf("%ldms : Philo #%d woke up.\n", get_time_ms(global->start),
		philo->id);
	while (philo->alive && global->active)
	{
		if (get_time_ms(philo->last_eat) > global->time_die)
			return (ft_die(philo, global), NULL);
		if (!philo->prev->eating && !philo->next->eating)
		{
			philo->thinking = 0;
			ft_eat(philo, global);
			ft_sleep(philo, global);
		}
		else
			ft_think(philo, global);
		check_nbeat(global, philo);
		if (global->nb_eat && global->nb_full == global->nb_philo)
		{
			if (global->active)
				printf("%ldms : Every Philosophers ate enough.\n",
					get_time_ms(global->start));
			pthread_mutex_lock(&global->mutex);
			global->active = 0;
			pthread_mutex_unlock(&global->mutex);
			return (NULL);
		}
	}
	return (NULL);
}


void	ft_eat(t_philosopher *philo, t_global *global)
{
	//eating = mutex (lock puis unlock)
	//if prev et next eating, peut pas eat
	//celui qui a eat depuis le 
	//plus longtemps = prio (pas sur car ils ne se parlent pas)
	//if eat -> sleep juste apres
	//reset de la variable last_eat
	//mutex lock (philo->eating)
	printf("%ldms : Philo #%d has taken a fork.\n",
		get_time_ms(global->start), philo->id);
	pthread_mutex_lock(&global->mutex);
	philo->eating = 1;
	pthread_mutex_unlock(&global->mutex);
	printf("%ldms : Philo #%d is eating.\n", get_time_ms(global->start),
		philo->id);
	usleep(global->time_eat * 1000);
	pthread_mutex_lock(&global->mutex);
	philo->eating = 0;
	pthread_mutex_unlock(&global->mutex);
	if (philo->nb_meals < global->nb_eat)
		philo->nb_meals++;
	gettimeofday(&philo->last_eat, NULL);
}

void	ft_sleep(t_philosopher *philo, t_global *global)
{
	philo->sleeping = 1;
	printf("%ldms : Philo #%d is sleeping.\n", get_time_ms(global->start),
		philo->id);
	usleep(global->time_sleep * 1000);
	philo->sleeping = 0;
}

void	ft_think(t_philosopher *philo, t_global *global)
{
	if (!philo->thinking)
	{
		philo->thinking = 1;
		printf("%ldms : Philo #%d is thinking.\n", get_time_ms(global->start),
			philo->id);
	}
	usleep(1000);
}

void	ft_die(t_philosopher *philo, t_global *global)
{
	global->active = 0;
	printf("%ldms : Philo #%d died.\n", get_time_ms(global->start),
		philo->id);
	philo->alive = 0;
}
