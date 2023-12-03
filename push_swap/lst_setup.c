/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:05:58 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/03 23:29:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	debug_prntlst(t_stack *lst)
{
	t_stack	*balai;

	balai = lst;
	while (balai)
	{
		printf("%d : %d\n", balai->index, balai->value);
		balai = balai->next;
	}
	printf("    _\n    a");
}

t_stack	*setupstack(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*current;
	t_stack	*follower;
	int		i;

	i = 0;
	a = ft_lstnew(ft_atoi(argv[i + 1]), i, NULL, NULL);
	current = a;
	i++;
	while (i < argc - 1)
	{
		if (!checkerror(argv[i + 1]))
			return (NULL);
		follower = ft_lstnew(ft_atoi(argv[i + 1]), i, current, NULL);
		current->next = follower;
		current = follower;
		follower = follower->next;
		i++;
	}
	return (checkdup(a));
}
