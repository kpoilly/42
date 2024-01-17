/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:58:55 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 14:30:27 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

void	philo_routine(t_global *global, t_philosopher *philo)
{
	while (philo->alive)
	{
		if (get_time_ms(philo->last_eat) >= global->time_die)
			ft_die(philo, global);
	}
}

// void	ft_eat(t_philosopher *philo, t_global *global)
// {
// 	//eating = mutex (lock puis unlock)
// 	//if prev et next eating, peut pas eat
// 	//celui qui a eat depuis le 
// 	//plus longtemps = prio (pas sur car ils ne se parlent pas)
// 	//if eat -> sleep juste apres
// 	//reset de la variable last_eat

// 	//mutex lock (philo->eating)
// 	//philo->eating = 1;
// 	//usleep(global->time_eat);
// 	//philo->eating = 0;
// 	//mutex unlock (philo->eating)
// 	//philo->last_eat = get_time_ms(global);
// }

// void	ft_sleep(t_philosopher *philo, t_global *global)
// {
// 	//philo->sleeping = 1;
// 	//usleep(global->time_sleep);
// 	//philo->sleeping = 0;
// }

// void	ft_think(t_philosopher *philo, t_global *global)
// {
// 	//philo->thinking= 1;
// 	//usleep(1);
// 	//philo->thinking = 0;
// }

void	ft_die(t_philosopher *philo, t_global *global)
{
	ft_printf(1, "%dms : Philo #%d died.\n", get_time_ms(global->start),
		philo->id);
	philo->alive = 0;
}
