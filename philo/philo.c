/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 09:00:35 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

void	lst_setup(t_global *global, t_philosopher *philo)
{
	philo->alive = 1;
	philo->eating = 0;
	philo->thinking = 1;
	philo->sleeping = 0;
	philo->thread = 0;
	philo->last_eat = get_time_ms(global->start.tv_usec);
}

int	main(int argc, char **argv)
{
	int				i;
	t_global		global;

	if (argc < 5 || !check_args(argv + 1))
		return (ft_printf(2, "Error.\nInvalid arguments.\n"), 1);
	global.philo_list = ft_lstnew(0);
	global.philo_list->prev = NULL;
	i = 1;
	while (i < ft_atoi(argv[1]))
		ft_lstadd_back(&global.philo_list, ft_lstnew(i++));
	ft_lstiter(&global, &lst_setup);
	gettimeofday(&global.start, NULL);
	ft_printf(1, "%d : Debut de la simulation.\n",
		get_time_ms(global.start.tv_usec));
	philo_routine(&global, global.philo_list);
	return (0);
}
