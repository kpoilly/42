/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:57:04 by lleciak           #+#    #+#             */
/*   Updated: 2024/04/19 13:58:07 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

void	open_doors(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_doors)
	{
		if (data->doors[i].open)
			data->map[data->doors[i].mapy][data->doors[i].mapx] = '0';
		else
			data->map[data->doors[i].mapy][data->doors[i].mapx] = 'D';
		i++;
	}
}

void	close_all(t_data *data)
{
	int	i;
	int	timer;

	i = 0;
	while (i < data->nb_doors)
	{
		data->doors[i].open = 0;
		data->doors[i].status = 0;
		timer = ((long double)(clock() - data->doors[i].img.timer)
				/ CLOCKS_PER_SEC) * 1000;
		if (timer >= 50)
		{
			data->doors[i].img.timer = clock();
			if (data->doors[i].img.lst->prev)
				data->doors[i].img.lst = data->doors[i].img.lst->prev;
		}
		i++;
	}
}

t_door	*get_door(t_data *data, float x, float y)
{
	int	i;
	int	mapx;
	int	mapy;

	mapx = get_mapx(x);
	mapy = get_mapy(y);
	i = 0;
	while (i < data->nb_doors)
	{
		if (data->doors[i].mapx == mapx && data->doors[i].mapy == mapy)
			return (&data->doors[i]);
		i++;
	}
	return (NULL);
}

int	door_placement(char	**tab)
{
	int	y;
	int	x;

	y = 1;
	while (tab[y])
	{
		x = 1;
		while (tab[y][x] && tab[y + 1] && tab[y][x + 1])
		{
			if (tab[y][x] == 'D')
			{
				if (!((tab[y + 1][x] == '1' && tab[y - 1][x] == '1'
					&& tab[y][x + 1] == '0' && tab[y][x - 1] == '0')
					|| (tab[y][x + 1] == '1' && tab[y][x - 1] == '1'
					&& tab[y + 1][x] == '0' && tab[y - 1][x] == '0')))
					return (ft_printf(2, "Error.\nInvalid door.\n"), 0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	set_door_list(t_data *data)
{
	int	y;
	int	x;
	int	id;

	data->nb_doors = count_in_tab(data->map, 'D');
	data->doors = malloc((data->nb_doors) * sizeof(t_door));
	id = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'D' && id < data->nb_doors)
				add_door(data, y, x, id++);
			x++;
		}
		y++;
	}
}
