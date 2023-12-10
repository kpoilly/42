/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:47:38 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/10 18:07:52 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_input(int argc, char **argv)
{
	if (argc >= 3)
		return (argv + 1);
	if (argc == 2 && ft_tablen(argv) == 2)
		return (ft_split(argv[1], ' '));
	return (NULL);
}

int	checkerror(char *input)
{
	if (ft_atoi(input) > 2147483647 || ft_atoi(input) < -2147483647)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (*input)
	{
		if (*input <= '0' && *input >= '9')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		input++;
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

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	rra(a);
	rrb(b);
}

void	debug_prntlst(t_stack *a, t_stack *b)
{
	t_stack	*i;
	t_stack	*j;

	i = a;
	j = b;
	printf("---------------\n");
	while (i || j)
	{
		if (i)
			printf("%d : %d", i->index, i->value);
		if (j)
		{
			if (!i)
				printf("     ");
			printf(" | %d : %d", j->index, j->value);
		}
		if (i)
			i = i->next;
		if (j)
			j = j->next;
		printf("\n");
	}
	printf("    _       _\n    a       b\n");
}
