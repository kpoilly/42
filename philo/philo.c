/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/19 14:44:59 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

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
	pthread_create(&global.current->thread, NULL,
		philo_routine, (void *)&global);
	usleep(80);
	i = 0;
	while (++i < ft_atoi(argv[1]))
	{
		global.current = global.current->next;
		pthread_create(&global.current->thread, NULL, philo_routine, &global);
		usleep(80);
	}
	return (wait_process(&global, ft_atoi(argv[1])),
		printf("%ldms : Simulation ended.\n", get_time_ms(global.start)),
		free_all(&global), 0);
}
