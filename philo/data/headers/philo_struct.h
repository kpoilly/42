/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:04 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/18 19:03:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include "./philo.h"

typedef struct s_philosopher
{
	pthread_t				thread;
	int						id;
	int						alive;
	int						eating;
	int						sleeping;
	int						thinking;
	int						nb_meals;
	struct timeval			last_eat;
	struct s_philosopher	*prev;
	struct s_philosopher	*next;
}	t_philosopher;

typedef struct s_global
{
	struct timeval		start;
	pthread_mutex_t		mutex;
	int					active;
	int					nb_philo;
	int					nb_eat; //nb de fois que tous doivent manger pour gagner
	int					nb_full;//combien ont atteint ce nb eat
	long				time_die; //temps avant de mourrir de faim
	long				time_eat; //temps que ca prends de manger (usleep)
	long				time_sleep; //temps que ca prends de dormir (usleep)
	t_philosopher		*philo_list;
	t_philosopher		*current;
}	t_global;

#endif