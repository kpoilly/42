/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:35:01 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/01 14:52:53 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	sort(t_stack **a, t_stack **b, int len)
{
	if (len <= 3)
		return (small_sort(a), 0);
	else if (len <= 5)
		return (medium_sort(a, b), 0);
	else
		return (radix(a, b), 0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		to_free;
	int		len;
	char	**inputs;

	if (argc < 2 || (argc == 2 && !ft_strlen(argv[1])))
		return (-1);
	inputs = get_input(argc, argv, &to_free);
	if (!inputs || !*inputs)
		return (-1);
	len = ft_tablen(inputs);
	a = setupstack(len, inputs);
	b = NULL;
	if (to_free)
		ft_free(inputs);
	if (!a)
		return (-1);
	if (!issorted(&a))
		sort(&a, &b, len);
	free_list(&a);
	free_list(&b);
	return (0);
}
