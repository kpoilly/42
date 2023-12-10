/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:35:01 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/10 18:47:29 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack **a)
{
	while (!issorted(a))
	{
		sa(a);
		if (!issorted(a))
			rra(a);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	while ((*a) && (*a)->value)
	{
		while (!*b || (*b && *a && (*b)->value < (*a)->value))
		{
			pb(b, a);
			debug_prntlst(*a, *b);
			if (ft_lstsize(*a) <= 3)
				{small_sort(a);
				debug_prntlst(*a, *b);
				break; }
		}
		while (*b && *a && (*b)->value > (*a)->value)
		{
			pa(a, b);
			sa(a);
			debug_prntlst(*a, *b);
		}
	}
	while (*b)
		pa(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**inputs;

	if (argc < 2)
		return (-1);
	inputs = get_input(argc, argv);
	a = setupstack(ft_tablen(inputs), inputs);
	b = NULL;
	if (!a)
		return (-1);
	if (issorted(&a))
		return (0);
	printf("STARTS:\n");
	debug_prntlst(a, b);
	if (ft_tablen(inputs) <= 3)
	{
		sa(&a);
		// small_sort(&a);
		printf("END:\n");
		debug_prntlst(a, b);
		return (0);
	}
	push_swap(&a, &b);
	printf("END:\n");
	debug_prntlst(a, b);
	// pb(&b, &a);
	// pb(&b, &a);
	// pb(&b, &a);
	// debug_prntlst(a, b);
	// rr(&b, &a);
	// debug_prntlst(a, b);
	// debug_prntlst(a, b);
	// sa(&a);
	// debug_prntlst(a, b);
	// pa(&a, &b);
	// pa(&a, &b);
	// pa(&a, &b);
	// debug_prntlst(a, b);
	// rrb(&b);
	// debug_prntlst(a, b);
	// rb(&b);
	// debug_prntlst(a, b);
	// ra(&a);
	// debug_prntlst(a, b);
	// free(a);
	// free(b);
	return (0);
}
