/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:04 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/16 13:59:35 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include "./philo.h"
# include <pthread.h>

typedef struct s_philosopher
{
	pthread_t				thread;
	int						id;
	int						alive;
	int						eating;
	int						sleeping;
	int						thinking;
	struct s_philosopher	*prev;
	struct s_philosopher	*next;
}	t_philosopher;

typedef struct s_global
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				ime_sleep;
	int				nb_eat;
	t_philosopher	*philo_list;
}	t_global;

#endif