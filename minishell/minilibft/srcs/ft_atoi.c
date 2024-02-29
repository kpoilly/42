/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:04:18 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/17 14:52:22 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Classic Atoi no malloc
int	ft_atoi(const char *nptr)
{
	int	number;
	int	i;
	int	sign;

	i = 0;
	number = 0;
	sign = 1;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
	{
		i++;
		sign *= -1;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
		number = number * 10 + (nptr[i++] - 48);
	return (number * sign);
}
