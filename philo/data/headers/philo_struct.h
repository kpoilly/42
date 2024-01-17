/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:31:04 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 15:37:24 by kpoilly          ###   ########.fr       */
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
	struct timeval			last_eat;
	struct s_philosopher	*prev;
	struct s_philosopher	*next;
}	t_philosopher;

typedef struct s_global
{
	struct timeval		start;
	int					nb_philo;
	int					nb_eat; //nb de fois que tous doivent manger pour gagner
	long				time_die; //temps avant de mourrir de faim
	long				time_eat; //temps que ca prends de manger (usleep)
	long				time_sleep; //temps que ca prends de dormir (usleep)
	t_philosopher		*philo_list;
	t_philosopher		*current;
}	t_global;

#endif