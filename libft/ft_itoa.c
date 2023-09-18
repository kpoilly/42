/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:54:48 by marvin            #+#    #+#             */
/*   Updated: 2023/09/12 18:54:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nb)
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
	i--;
	j = 0;
	while (i >= 0)
		revstr[j++] = str[i--];
	return (revstr);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*str;
	int		i;

	sign = 1;
	if (n < 0)
	{
		sign++;
		n *= -1;
	}
	str = malloc((ft_intlen(n) + sign) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (!n)
		str[i++] = '0';
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == 2)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
