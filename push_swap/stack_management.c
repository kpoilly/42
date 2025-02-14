/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:16:21 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/01 14:54:33 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	rra(a);
	rrb(b);
}

t_stack	*swap(t_stack **a)
{
	t_stack	*temp;

	temp = (*a)->next;
	if (temp->next)
		(temp->next)->prev = temp->prev;
	(*a)->index = temp->index;
	(*a)->next = temp->next;
	(*a)->prev = temp;
	ft_lstadd_front(a, temp);
	return (*a);
}

int	issorted(t_stack **a)
{
	t_stack	*i;

	i = *a;
	while (i && i->next)
	{
		if ((i->next)->value < i->value)
			return (0);
		i = i->next;
	}
	return (1);
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

void	set_order(t_stack *a)
{
	int		min;
	int		count;
	t_stack	*current;
	t_stack	*pars;

	current = a;
	while (current)
	{
		pars = a;
		count = 0;
		min = current->value;
		while (pars)
		{
			if (pars->value > min)
				count++;
			pars = pars->next;
		}
		current->order = ft_lstsize(a) - count - 1;
		current = current->next;
	}
}
