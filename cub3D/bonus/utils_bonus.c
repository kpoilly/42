/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:18:26 by lleciak           #+#    #+#             */
/*   Updated: 2024/04/18 12:35:00 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	if (!src)
		return (NULL);
	if (n < 0)
		n = ft_strlen(src);
	dest = malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
		str[i++] = '\0';
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	total;

	total = nmemb * size;
	if (nmemb && total / nmemb != size)
		return (NULL);
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, nmemb * size);
	return (array);
}

static int	ft_intlen(long int nb)
{
	int	len;

	if (!nb)
		return (1);
	len = 0;
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
	str = ft_calloc((ft_intlen(nb) + sign), sizeof(char));
	if (!str)
		return (NULL);
	i = ft_intlen(nb) + sign - 1;
	str[0] = '0';
	while (nb > 0)
	{
		str[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign == 2)
		str[0] = '-';
	return (str);
}
