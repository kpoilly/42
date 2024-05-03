/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:28:15 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/31 16:13:56 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	in_base(char c, int base)
{
	char	*base_min = "0123456789abcdef";
	char	*base_maj = "0123456789ABCDEF";
	int		i;

	i = 0;
	while (base_min[i] && i < base)
	{
		if (c == base_min[i] || c == base_maj[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	char	*base_min = "0123456789abcdef";
	char	*base_maj = "0123456789ABCDEF";
	int		i;
	int		j;
	int		sign = 1;
	int		nb = 0;

	if (!str || str_base > 16 || str_base <= 0)
		return (0);

	i = 0;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}

	while (str[i])
	{
		if (!in_base(str[i], str_base))
			return (0);
		j = 0;
		while (base_min[j] && j < str_base)
		{
			if (str[i] == base_min[j] || str[i] == base_maj[j])
			{
				nb = nb * str_base;
				nb += j;
			}
			j++;
		}
		i++;
	}

	return (nb * sign);
}

int main(int argc, char **argv)
{
	(void)argc;
	printf("nb: %s\nconvert: %d\n", argv[1],
		ft_atoi_base(argv[1], atoi(argv[2])));
}
