/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:05:58 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/04 18:15:54 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_stack **a)
{
	t_stack	*balai;

	balai = *a;
	while (balai)
	{
		if (balai->next && (balai->next)->value < balai->value)
			return (0);
		balai = balai->next;
	}
	return (1);
}

t_stack	*ft_lstnew(int value, int index, void *prev, void *next)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->index = index;
	elem->prev = prev;
	elem->next = next;
	return (elem);
}

t_stack	*setupstack(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*current;
	t_stack	*follower;
	int		i;

	i = 0;
	a = ft_lstnew(ft_atoi(argv[i + 1]), i, NULL, NULL);
	current = a;
	i++;
	while (i < argc - 1)
	{
		if (!checkerror(argv[i + 1]))
			return (NULL);
		follower = ft_lstnew(ft_atoi(argv[i + 1]), i, current, NULL);
		current->next = follower;
		current = follower;
		follower = follower->next;
		i++;
	}
	if (!checkdup(a))
	{
		write(2, "Error", 5);
		return (NULL);
	}
	return (a);
}
