/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:29:33 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/31 18:14:30 by kpoilly          ###   ########.fr       */
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

void	medium_sort(t_stack **a, t_stack **b)
{
	int	target;
	int	target_index;

	target = 0;
	while ((!issorted(a) && *b) || target == 0)
	{
		target_index = get_index(*a, target);
		while ((*a)->order != target)
		{
			if (target_index <= (ft_lstsize(*a) / 2))
				ra(a);
			else
				rra(a);
		}
		pb(b, a);
		if (ft_lstsize(*a) == 3)
			small_sort(a);
		target++;
		if (issorted(a))
			while (*b)
				pa(a, b);
	}
}

void	radix(t_stack **a, t_stack **b)
{
	int	size_a;
	int	nbbits;
	int	bit_check;
	int	i;

	size_a = ft_lstsize(*a);
	nbbits = get_nbbits(*a);
	bit_check = 0;
	while (bit_check < nbbits)
	{
		i = 0;
		while (i < size_a)
		{
			if ((((*a)->order >> bit_check) & 1) == 0)
				pb(b, a);
			else
				ra(a);
			i++;
		}
		while (*b)
			pa(a, b);
		bit_check++;
	}
}

// void	push_swap(t_stack **a, t_stack **b)
// {
// 	int	target;
// 	int	target_index;

// 	target = 0;
// 	target_index = get_index(*a, target);
// 	while ((!issorted(a) && *b) || target == 0)
// 	{
// 		while ((*a)->order != target)
// 		{
// 			if (target_index <= (ft_lstsize(*a) / 2))
// 				ra(a);
// 			else
// 				rra(a);
// 		}
// 		if (issorted(a))
// 		{
// 			while (*b)
// 				pa(a, b);
// 			break ;
// 		}
// 		pb(b, a);
// 		target++;
// 		target_index = get_index(*a, target);
// 		if (ft_lstsize(*a) == 1)
// 		{
// 			while (*b)
// 				pa(a, b);
// 			break ;
// 		}
// 	}
// }
