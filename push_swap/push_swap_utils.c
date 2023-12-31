/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:47:38 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/31 18:16:21 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_order(t_stack *a)
{
	int		min;
	int		count;
	t_stack	*current;
	t_stack	*pars;

	current = a;
	while (current)
	{
		pars = a;
		count = 0;
		min = current->value;
		while (pars)
		{
			if (pars->value > min)
				count++;
			pars = pars->next;
		}
		current->order = ft_lstsize(a) - count - 1;
		current = current->next;
	}
}

char	**get_input(int argc, char **argv, int *to_free)
{
	*to_free = 0;
	if (argc >= 3)
		return (argv + 1);
	if (argc == 2)
	{
		*to_free = 1;
		return (ft_split(argv[1], ' '));
	}
	return (NULL);
}

int	checkerror(char *input)
{
	int	i;

	if (ft_atoi(input) > 2147483647 || ft_atoi(input) < -2147483647)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (input[i])
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
		{
			if (input[i] != '-')
				return (write(2, "Error\n", 6), 0);
			else if (input[i] == '-'
				&& ((i && input[i - 1] != ' ') || !input[i + 1]))
				return (write(2, "Error\n", 6), 0);
		}
		i++;
	}
	return (1);
}

int	checkdup(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;

	i = a;
	while (i)
	{
		j = a;
		while (j)
		{
			if (j->value == i->value && j != i)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

// void	debug_prntlst(t_stack *a, t_stack *b)
// {
// 	t_stack	*i;
// 	t_stack	*j;

// 	i = a;
// 	j = b;
// 	printf("---------------\n");
// 	while (i || j)
// 	{
// 		if (i)
// 		{
// 			printf("%d : %d", i->order, i->value);
// 			// if (i->prev)
// 			// 	printf(" // prev: %d", (i->prev)->value);
// 		}
// 		if (j)
// 		{
// 			if (!i)
// 				printf("     ");
// 			printf(" | %d : %d", j->order, j->value);
// 		}
// 		if (i)
// 			i = i->next;
// 		if (j)
// 			j = j->next;
// 		printf("\n");
// 	}
// 	printf("    _       _\n    a       b\n");
// }