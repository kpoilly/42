/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:41:16 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/31 16:44:49 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *a, int target)
{
	t_stack	*current;

	current = a;
	while (current)
	{
		if (current->order == target)
			return (current->index);
		current = current->next;
	}
	return (-1);
}

int	get_nbbits(t_stack *a)
{
	t_stack	*current;
	int		nbbits;

	current = a;
	nbbits = 0;
	while (current && current->order != ft_lstsize(a) - 1)
		current = current->next;
	while (current->order >> nbbits != 0)
		nbbits++;
	return (nbbits);
}
