/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:43:36 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/08 07:27:18 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long int nb)
{
	int	len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_strrev(char *str)
{
	char	*revstr;
	int		i;
	int		j;

	i = ft_strlen(str);
	revstr = malloc((i + 1) * sizeof(char));
	if (!revstr)
		return (NULL);
	i--;
	j = 0;
	while (i >= 0)
		revstr[j++] = str[i--];
	return (revstr);
}

long int	grapillage(long int n, int *sign)
{
	*sign = 1;
	if (n < 0)
	{
		(*sign)++;
		n *= -1;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			sign;
	char		*str;
	int			i;

	nb = grapillage(n, &sign);
	str = malloc((ft_intlen(nb) + sign) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (!nb)
		str[i++] = '0';
	while (nb > 0)
	{
		str[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign == 2)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
