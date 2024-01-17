/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:36:00 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 15:14:38 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

void	set_philo_list(char **argv, t_global *global)
{
	int	i;

	global->philo_list = ft_lstnew(0);
	global->philo_list->prev = NULL;
	i = 1;
	while (i < ft_atoi(argv[1]))
		ft_lstadd_back(&global->philo_list, ft_lstnew(i++));
	ft_lstiter(global, &data_setup);
	set_lst_loop(global);
}

void	data_setup(t_global *global, t_philosopher *philo)
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
