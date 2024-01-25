/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/24 19:17:21 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/philo_bonus.h"

void	*philo_routine(void *thing)
{
	t_global		*global;
	t_philosopher	*philo;

	global = (t_global *)thing;
	philo = get_philo(global);
	while (philo->alive && global->active)
	{
		if (get_time_ms(philo->last_eat) > global->time_die)
			return (ft_die(philo, global), NULL);
		if (!philo->thinking)
			ft_think(philo, global);
	}
	return (pthread_detach(philo->process), NULL);
}

int	main(int argc, char **argv)
{
	int				i;
	t_global		global;

	if (argc < 5 || argc > 6 || !check_args(argv + 1))
		return (write(2, "Error.\nInvalid arguments.\n", 26), 1);
	get_args(argc, argv, &global);
	set_philo_list(argv, &global);
	gettimeofday(&global.start, NULL);
	printf("%ldms : Simulation begin.\n",
		get_time_ms(global.start));
	global.current = global.philo_list;
	i = 0;
	while (i++ < ft_atoi(argv[1]))
	{
		global.can_go = 0;
		pthread_create(&global.current->thread, NULL, philo_routine, &global);
		while (!global.can_go)
			usleep(80);
		if (i < ft_atoi(argv[1]))
			global.current = global.current->next;
	}
	return (wait_process(&global, ft_atoi(argv[1])),
		printf("%ldms : Simulation ended.\n", get_time_ms(global.start)),
		free_all(&global), 0);
}
