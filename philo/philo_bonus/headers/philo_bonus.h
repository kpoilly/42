/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:27:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/24 17:28:38 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>
# include "./philo_struct_bonus.h"

//setup
void				get_args(int argc, char **argv, t_global *global);
void				data_setup(t_philosopher *philo);
t_philosopher		*get_philo(t_global *global);
int					check_nbeat(t_global *global, t_philosopher *philo);
void				end_simu(t_global *global);
void				free_all(t_global *global);
void				free_lst(t_global *global);

//utils
int					ft_atoi(const char *nptr);
void				ft_freetab(t_philosopher **tab);
int					check_args(char **argv);
long				get_time_ms(struct timeval start);
void				wait_process(t_global *global, int nb_process);

//list setup
void				set_philo_list(char **argv, t_global *global);
t_philosopher		*ft_lstnew(int nb);
t_philosopher		*ft_lstlast(t_philosopher *lst);
void				ft_lstadd_back(t_philosopher **lst, t_philosopher *new);
void				ft_lstiter(t_global *global, void (*f)(t_philosopher *));
void				set_lst_loop(t_global *global);

//actions
void				*philo_routine(void *thing);
int					ft_eat(t_philosopher *philo, t_global *global);
int					ft_sleep(t_philosopher *philo, t_global *global);
void				ft_think(t_philosopher *philo, t_global *global);
void				ft_die(t_philosopher *philo, t_global *global);
void				*lt_eat(void *data);

#endif