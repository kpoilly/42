/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:16:21 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/04 12:15:45 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack **a)
{
	t_stack	*temp;

	temp = (*a)->next;
	(*a)->index = temp->index;
	(*a)->next = temp->next;
	(*a)->prev = temp->prev;
	ft_lstadd_front(a, temp);
	return (*a);
}

void	clear_index(t_stack **stack)
{
	t_stack	*i;
	int		index;

	i = *stack;
	index = 0;
	while (i)
	{
		i->index = index++;
		i = i->next;
	}
}
