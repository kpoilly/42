/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:36:00 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 14:50:55 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

void	lst_setup(t_global *global, t_philosopher *philo)
{
	(void)global;
	philo->alive = 1;
	philo->eating = 0;
	philo->thinking = 1;
	philo->sleeping = 0;
	philo->thread = 0;
	gettimeofday(&philo->last_eat, NULL);
}

void	get_args(int argc, char **argv, t_global *global)
{
	if (argc == 5)
		global->nb_eat = 0;
	else
		global->nb_eat = ft_atoi(argv[5]);
	global->time_die = ft_atoi(argv[2]);
}