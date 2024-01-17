/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 15:40:41 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

int	main(int argc, char **argv)
{
	int				i;
	t_global		global;

	if (argc < 5 || argc > 6 || !check_args(argv + 1))
		return (ft_printf(2, "Error.\nInvalid arguments.\n"), 1);
	get_args(argc, argv, &global);
	set_philo_list(argv, &global);
	gettimeofday(&global.start, NULL);
	ft_printf(1, "%dms : Simulation begin.\n",
		get_time_ms(global.start));
	global.current = &global.philo_list;
	pthread_create(&global.current->thread, NULL, &philo_routine, &global);
	global.current = global.current->next;
	i = 1;
	while (i < ft_atoi(argv[1]))
		philo_routine(&global);
	return (0);
}
