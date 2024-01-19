/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:04 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/19 15:52:11 by kpoilly          ###   ########.fr       */
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
	int					nb_eat;
	int					nb_full;
	long				time_die;
	long				time_eat;
	long				time_sleep;
	t_philosopher		*philo_list;
	t_philosopher		*current;
	char				can_go;
}	t_global;

#endif