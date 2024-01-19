/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/19 01:53:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

int	main(int argc, char **argv)
{
	int				i;
	t_global		global;

	if (argc < 5 || argc > 6 || !check_args(argv + 1))
		return (printf("Error.\nInvalid arguments.\n"), 1);
	get_args(argc, argv, &global);
	set_philo_list(argv, &global);
	gettimeofday(&global.start, NULL);
	printf("%ldms : Simulation begin.\n",
		get_time_ms(global.start));
	global.current = global.philo_list;
	pthread_create(&global.current->thread, NULL,
		philo_routine, (void *)&global);
	printf("Process for Philo #%d created.\n", global.current->id);
	global.current = global.current->next;
	i = 1;
	while (i < ft_atoi(argv[1]))
	{
		pthread_create(&global.current->thread, NULL, philo_routine, &global);
		global.current = global.current->next;
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		global.current = global.current->next;
		pthread_join(global.current->thread, NULL);
		i++;
	}
	printf("%ldms : Simulation ended.\n",
		get_time_ms(global.start));
	return (free_all(&global), 0);
}
