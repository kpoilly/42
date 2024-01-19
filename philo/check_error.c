/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:04:42 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/19 16:05:48 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

void	free_lst(t_global *global)
{
	t_philosopher	*lst;
	t_philosopher	*tmp;
	int				i;

	if (!global->philo_list)
		return ;
	lst = global->philo_list;
	i = 0;
	while (i < global->nb_philo)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
		i++;
	}
	global->philo_list = NULL;
}

void	free_all(t_global *global)
{
	free_lst(global);
	pthread_mutex_destroy(&global->mutex);
}

int	check_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		if (ft_atoi((argv[i++])) < 0)
			return (0);
	if (ft_atoi(argv[0]) <= 0)
		return (0);
	return (1);
}
