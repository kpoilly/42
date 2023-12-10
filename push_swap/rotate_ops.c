/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:23:05 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/10 18:46:13 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*temp;

	write(1, "ra\n", 3);
	temp = *a;
	if (*a)
	{
		*a = ft_lstdelelem(*a);
		ft_lstadd_back(a, temp);
	}
	clear_index(a);
}

void	rb(t_stack **b)
{
	t_stack	*temp;

	write(1, "rb\n", 3);
	temp = *b;
	if (*b)
	{
		*b = ft_lstdelelem(*b);
		ft_lstadd_back(b, temp);
	}
	clear_index(b);
}

void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	ra(a);
	rb(b);
}

void	rra(t_stack **a)
{
	t_stack	*temp;

	write(1, "rra\n", 4);
	temp = ft_lstlast(*a);
	if (*a)
	{
		ft_lstdelelem(ft_lstlast(*a));
		ft_lstadd_front(a, temp);
		if ((*a)->next)
			((*a)->next)->prev = *a;
	}
	clear_index(a);
}

void	rrb(t_stack **b)
{
	t_stack	*temp;

	write(1, "rrb\n", 4);
	temp = ft_lstlast(*b);
	if (*b)
	{
		ft_lstdelelem(ft_lstlast(*b));
		ft_lstadd_front(b, temp);
		if ((*b)->next)
			((*b)->next)->prev = *b;
	}
	clear_index(b);
}
