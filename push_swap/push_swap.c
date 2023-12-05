/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:35:01 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/05 13:06:30 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	while ((*a) && (*a)->value)
	{
		//printf("\n [%d]", (*a)->value);
		while (!*b || (*b)->value < (*a)->value)
		{
			pb(b, a);
			debug_prntlst(*a, *b);
		}
		rb(b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (-1);
	a = setupstack(argc, argv);
	b = NULL;
	if (!a)
		return (-1);

	debug_prntlst(a, b);
	push_swap(&a, &b);
	debug_prntlst(a, b);
	// pb(&b, &a);
	// pb(&b, &a);
	// pb(&b, &a);
	// debug_prntlst(a, b);
	// rr(&b, &a);
	// debug_prntlst(a, b);
	// rrr(&a, &b);
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
