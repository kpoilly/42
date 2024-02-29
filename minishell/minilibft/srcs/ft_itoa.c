/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:56:57 by jdoukhan          #+#    #+#             */
/*   Updated: 2023/11/13 10:48:23 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long int num)
{
	int	len;

	if (!num)
		return (1);
	len = 0;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static void	ft_more(char *tab, int i)
{
	tab[0] = 48;
	tab[i] = 0;
}

char	*ft_itoa(int n)
{
	char		*tab;
	int			i;
	long int	num;
	int			sign;

	sign = 0;
	num = (long int) n;
	if (num < 0)
	{
		num *= -1;
		sign++;
	}
	tab = ft_calloc(ft_numlen(num) + sign + 1, sizeof (char));
	if (!tab)
		return (NULL);
	i = ft_numlen(num) + sign;
	ft_more(tab, i);
	while (num > 0)
	{
		tab[--i] = num % 10 + 48;
		num /= 10;
	}
	if (sign == 1)
		tab[0] = '-';
	return (tab);
}
