/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 13:27:14 by kpoilly          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int				i;
	t_global		global;

	if (argc < 5 || !check_args(argv + 1))
		return (ft_printf(2, "Error.\nInvalid arguments.\n"), 1);
	global.time_die = ft_atoi(argv[2]);
	global.philo_list = ft_lstnew(0);
	global.philo_list->prev = NULL;
	i = 1;
	while (i < ft_atoi(argv[1]))
		ft_lstadd_back(&global.philo_list, ft_lstnew(i++));
	gettimeofday(&global.start, NULL);
	ft_printf(1, "start : %d\n", global.start.tv_sec);
	ft_lstiter(&global, &lst_setup);
	ft_printf(1, "%d : Debut de la simulation.\n",
		get_time_ms(global.start));
	philo_routine(&global, global.philo_list);
	return (0);
}
