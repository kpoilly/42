/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:47:38 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/03 23:09:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}


int	checkerror(char *input)
{
	//duplicate
	if (ft_atoi(input) > 2147483647 || ft_atoi(input) < -2147483647)
	{
		write(2, "Error", 5);
		return (0);
	}
	while (*input)
	{
		if (*input <= '0' && *input >= '9')
		{
			write(2, "Error", 5);
			return (0);
		}
		input++;
	}
	return (1);
}

t_stack	*checkdup(t_stack *a)
{
	
}