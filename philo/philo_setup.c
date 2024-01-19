/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:36:00 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/19 16:06:08 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

t_philosopher	*get_philo(t_global *global)
{
	t_philosopher	*philo;

	pthread_mutex_lock(&global->mutex);
	philo = global->current;
	global->can_go = 1;
	pthread_mutex_unlock(&global->mutex);
	printf("%ldms : Philo #%d woke up\n", get_time_ms(global->start),
		philo->id);
	return (philo);
}

void	set_philo_list(char **argv, t_global *global)
{
	int	i;

	global->philo_list = ft_lstnew(0);
	global->philo_list->prev = NULL;
	i = 1;
	while (i < ft_atoi(argv[1]))
		ft_lstadd_back(&global->philo_list, ft_lstnew(i++));
	ft_lstiter(global, &data_setup);
	if (ft_atoi(argv[1]) > 1)
		set_lst_loop(global);
	else
	{
		global->philo_list->prev = NULL;
		global->philo_list->next = NULL;
	}
}

void	data_setup(t_philosopher *philo)
{
	philo->alive = 1;
	philo->eating = 0;
	philo->thinking = 0;
	philo->sleeping = 0;
	philo->nb_meals = 0;
	philo->thread = 0;
	gettimeofday(&philo->last_eat, NULL);
}

void	get_args(int argc, char **argv, t_global *global)
{
	if (argc == 5)
		global->nb_eat = 0;
	else
		global->nb_eat = ft_atoi(argv[5]);
	global->nb_philo = ft_atoi(argv[1]);
	global->time_die = ft_atoi(argv[2]);
	global->time_eat = ft_atoi(argv[3]);
	global->time_sleep = ft_atoi(argv[4]);
	global->nb_full = 0;
	global->active = 1;
	pthread_mutex_init(&global->mutex, NULL);
}
