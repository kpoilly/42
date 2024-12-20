/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:05:58 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/01 15:02:18 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
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

t_stack	*setupstack(int argc, char **inputs)
{
	t_stack	*a;
	t_stack	*current;
	t_stack	*follower;
	int		i;

	i = 0;
	if (!checkerror(inputs[i]))
		return (NULL);
	a = ft_lstnew(ft_atoi(inputs[i]), i, NULL, NULL);
	current = a;
	i++;
	while (i < argc)
	{
		if (!checkerror(inputs[i]))
			return (free_list(&a), NULL);
		follower = ft_lstnew(ft_atoi(inputs[i]), i, current, NULL);
		current->next = follower;
		current = follower;
		follower = follower->next;
		i++;
	}
	if (!checkdup(a))
		return (free_list(&a), write(2, "Error\n", 6), NULL);
	set_order(a);
	return (a);
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*i;
	int		size;

	if (!lst)
		return (0);
	i = lst->next;
	size = 1;
	while (i)
	{
		size++;
		i = i->next;
	}
	return (size);
}

void	free_list(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
