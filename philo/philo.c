/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:28:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 14:54:48 by kpoilly          ###   ########.fr       */
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
	global.philo_list = ft_lstnew(0);
	global.philo_list->prev = NULL;
	i = 1;
	while (i < ft_atoi(argv[1]))
		ft_lstadd_back(&global.philo_list, ft_lstnew(i++));
	ft_lstiter(&global, &lst_setup);
	gettimeofday(&global.start, NULL);
	ft_printf(1, "%dms : Simulation begin.\n",
		get_time_ms(global.start));
	philo_routine(&global, global.philo_list);
	return (0);
}
