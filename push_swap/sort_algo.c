/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:29:33 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/30 15:30:02 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **a)
{
	while (!issorted(a))
	{
		if ((*a)->value > ((*a)->next)->value)
			sa(a);
		if (!issorted(a))
			rra(a);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	while ((*a) && (*a)->value)
	{
		if ((*a)->value > ((*a)->next)->value)
			sa(a);
		while (!*b || (*b && *a && (*b)->value < (*a)->value))
		{	
			if (*b && !(*b)->next && (*b)->value < (*a)->value && issorted(a))
				return (pa(a, b));
			pb(b, a);
			if (ft_lstsize(*a) <= 3)
			{
				small_sort(a);
				while ((*b && *a && (*b)->value < (*a)->value))
					pa(a, b);
			}
			if (issorted(a) && !*b)
				return ;
		}
		while (*b && *a && (*b)->value > (*a)->value)
		{
			pa(a, b);
			sa(a);
		}
		if (issorted(a) && !*b)
			return ;
	}
	while (*b)
		pa(a, b);
}