/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:35:01 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/12 09:29:00 by kpoilly          ###   ########.fr       */
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

// void	push_swap(t_stack **a, t_stack **b)
// {
// 	int	len;
// 	int	bit;

// 	len = ft_lstsize(*a);
// 	bit = 1;
// 	while (!issorted(a))
// 	{
// 		while (*a)
// 		{
// 			if ((*a))
// 		}
// 	}
// }

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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;
	char	**inputs;

	if (argc < 2)
		return (-1);
	inputs = get_input(argc, argv);
	len = ft_tablen(inputs);
	if (!inputs)
		return (0);
	a = setupstack(len, inputs);
	b = NULL;
	//ft_free(inputs);
	if (!a)
		return (-1);
	// printf("STARTS:\n");
	// debug_prntlst(a, b);
	if (len <= 3 && !issorted(&a))
	{
		small_sort(&a);
		// printf("END:\n");
		// debug_prntlst(a, b);
		return (0);
	}
	if (!issorted(&a))
		push_swap(&a, &b);
	// printf("END:\n");
	// debug_prntlst(a, b);
	if (a)
		free(a);
	if (b)
		free(b);
	return (0);
}
