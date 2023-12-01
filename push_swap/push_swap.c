/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:35:01 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/01 15:49:50 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *a)
{
	int	*b;


}

int	main(int argc, char **argv)
{
	int	*a;
	int	len;
	int	nb;
	int	i;

	if (argc < 2)
		return (-1);
	len = argc - 1;
	a = malloc (len * sizeof(int));
	i = 0;
	while (i < len)
	{
		if (!checkerror(argv[i + 1]))
			return (-1);
		nb = ft_atoi(argv[i + 1]);
		a[i++] = nb;
	}
	///
	i = 0;
	while (i < len)
		printf("%d\n", a[i++]);
	printf("_\na");
	free(a);
	return (0);
}
