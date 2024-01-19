/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lst_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:03:34 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/18 19:16:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/philo.h"

t_philosopher	*ft_lstnew(int nb)
{
	t_philosopher	*elem;

	elem = malloc(sizeof(t_philosopher));
	if (!elem)
		return (NULL);
	elem->id = nb;
	elem->next = NULL;
	return (elem);
}

t_philosopher	*ft_lstlast(t_philosopher *lst)
{
	t_philosopher	*balai;

	if (!lst)
		return (NULL);
	balai = lst->next;
	if (!balai)
		return (lst);
	while (balai && balai->next)
		balai = balai->next;
	return (balai);
}

void	ft_lstadd_back(t_philosopher **lst, t_philosopher *new)
{
	t_philosopher	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
}

void	ft_lstiter(t_global *global, void (*f)(t_philosopher *))
{
	t_philosopher	*balai;

	balai = global->philo_list;
	while (balai)
	{
		f(balai);
		balai = balai->next;
	}
}

void	set_lst_loop(t_global *global)
{
	t_philosopher	*last;

	last = ft_lstlast(global->philo_list);
	global->philo_list->prev = last;
	last->next = global->philo_list;
}
