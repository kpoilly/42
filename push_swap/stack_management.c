/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:16:21 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/03 23:40:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack **a)
{
	t_stack	*temp;

	temp = (*a)->next;
	(*a)->next = temp->next;
	ft_lstadd_front(a, temp);
	return (*a);
}
