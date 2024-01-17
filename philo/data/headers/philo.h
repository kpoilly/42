/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:27:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/17 15:40:05 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "./philo_struct.h"

//setup
void				get_args(int argc, char **argv, t_global *global);
void				data_setup(t_global *global, t_philosopher *philo);

//utils
int					ft_atoi(const char *nptr);
void				ft_freetab(t_philosopher **tab);
int					check_args(char **argv);
long				get_time_ms(struct timeval start);

//list setup
void				set_philo_list(char **argv, t_global *global);
t_philosopher		*ft_lstnew(int nb);
t_philosopher		*ft_lstlast(t_philosopher *lst);
void				ft_lstadd_back(t_philosopher **lst, t_philosopher *new);
void				ft_lstiter(t_global *global,
						void (*f)(t_global *, t_philosopher *));
void				set_lst_loop(t_global *global);

//actions
void				philo_routine(t_global *global);
void				ft_eat(t_philosopher *philo, t_global *global);
void				ft_sleep(t_philosopher *philo, t_global *global);
void				ft_think(t_philosopher *philo, t_global *global);
void				ft_die(t_philosopher *philo, t_global *global);

#endif