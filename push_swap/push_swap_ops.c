/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:39:27 by marvin            #+#    #+#             */
/*   Updated: 2023/12/03 23:39:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	write(1, "sa\n", 3);
	*a = swap(a);
}

void	sb(t_stack **b)
{
	write(1, "sb\n", 3);
	*b = swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	sa(a);
	sb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	write(1, "pa\n", 3);
	temp = *b;
	if (*b)
	{
		*b = ft_lstdelelem(*b);
		ft_lstadd_front(a, temp);
		if ((*a)->next)
			((*a)->next)->prev = *a;
	}
	clear_index(a);
	clear_index(b);
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	write(1, "pb\n", 3);
	temp = *a;
	if (*a)
	{
		*a = ft_lstdelelem(*a);
		ft_lstadd_front(b, temp);
		if ((*b)->next)
			((*b)->next)->prev = *b;
	}
	clear_index(a);
	clear_index(b);
}
