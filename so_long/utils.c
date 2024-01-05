/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:25:30 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/05 13:44:31 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Recupere la coordonne du joueur (ou ennemy) dans la map
void	set_coord(t_global *global, t_ent *target)
{
	int	x;
	int	y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == target->chara)
			{
				target->x = x;
				target->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
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
