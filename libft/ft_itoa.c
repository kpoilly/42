/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:57:09 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/10 09:15:02 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long int nb)
{
	int	len;

	len = 1;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			sign;
	int			i;

	nb = n;
	sign = 1;
	if (nb < 0)
	{
		sign++;
		nb *= -1;
	}
	str = malloc((ft_intlen(nb) + sign) * sizeof(char));
	if (!str)
		return (NULL);
	i = ft_intlen(nb) + sign;
	str[i] = '\0';
	while (nb > 0)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign == 2)
		str[0] = '-';
	return (str);
}
