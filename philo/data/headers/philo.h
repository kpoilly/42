/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:27:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/16 15:05:51 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./philo_struct.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

//utils
int					ft_atoi(const char *nptr);
void				ft_freetab(t_philosopher **tab);

//list setup
void				lst_setup(t_philosopher *philo);
t_philosopher		*ft_lstnew(int nb);
t_philosopher		*ft_lstlast(t_philosopher *lst);
void				ft_lstadd_back(t_philosopher **lst, t_philosopher *new);
void				ft_lstiter(t_philosopher *lst, void (*f)(t_philosopher *));

#endif