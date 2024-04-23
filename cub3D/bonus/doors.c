/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:07:11 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/19 14:01:25 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

int	count_in_tab(char **tab, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	add_door(t_data *data, int mapy, int mapx, int id)
{
	data->doors[id].mapx = mapx;
	data->doors[id].mapy = mapy;
	data->doors[id].id = id;
	data->doors[id].open = 0;
	data->doors[id].status = 0;
	data->doors[id].img = data->door_tex;
	data->doors[id].img.timer = clock();
}

t_door	*nearest_door(t_data *data, int px, int py)
{
	int	i;

	i = 0;
	data->is_door = 0;
	while (i < data->nb_doors)
	{
		if (((data->doors[i].mapx == px + 1
					|| data->doors[i].mapx == px - 1
					|| data->doors[i].mapx == px)
				&& (data->doors[i].mapy == py + 1
					|| data->doors[i].mapy == py - 1
					|| data->doors[i].mapy == py)))
		{
			data->is_door = 1;
			if (data->doors[i].mapx == get_mapx(data->player.ax)
				&& data->doors[i].mapy == get_mapy(data->player.ay))
				return (&data->doors[i]);
		}
		i++;
	}
	return (NULL);
}

static void	anim_doors(t_data *data, int open)
{
	int		timer;

	if (!open)
		data->cur_door->open = 0;
	timer = ((long double)(clock() - data->cur_door->img.timer)
			/ CLOCKS_PER_SEC) * 1000;
	if (timer >= 50)
	{
		data->cur_door->img.timer = clock();
		if (open)
		{
			if (data->cur_door->img.lst->next)
				data->cur_door->img.lst = data->cur_door->img.lst->next;
			else
				data->cur_door->open = 1;
		}
		else
			if (data->cur_door->img.lst->prev)
				data->cur_door->img.lst = data->cur_door->img.lst->prev;
	}
}

void	doors(t_data *data)
{
	data->cur_door = nearest_door(data, get_mapx(data->player.x),
			get_mapy(data->player.y));
	if (!data->cur_door)
	{
		if (!data->is_door)
			close_all(data);
		return ;
	}
	if (data->open_door)
		data->cur_door->status = 1;
	if (data->cur_door->status)
		anim_doors(data, 1);
	else
		anim_doors(data, 0);
}
