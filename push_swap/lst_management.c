/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:09:59 by marvin            #+#    #+#             */
/*   Updated: 2023/12/03 23:09:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	new->prev = NULL;
	new->index = 0;
	*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

t_stack	*ft_lstdelelem(t_stack *elem)
{
	t_stack	*temp;

	temp = elem->next;
	if (elem->next)
		(elem->next)->prev = elem->prev;
	if (elem->prev)
		(elem->prev)->next = elem->next;
	return (temp);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*balai;

	if (!lst)
		return (NULL);
	balai = lst->next;
	if (!balai)
		return (lst);
	while (balai && balai->next)
		balai = balai->next;
	return (balai);
}
