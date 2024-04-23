/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/22 10:40:43 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//set the angle the player is looking for on spawn
void	get_player_angle(char *c, t_data *data)
{
	if (*c == 'N')
		data->player.a = (3 * PI) / 2;
	else if (*c == 'S')
		data->player.a = PI / 2;
	else if (*c == 'E')
		data->player.a = 2 * PI;
	else if (*c == 'W')
		data->player.a = PI;
	*c = '0';
}

//get values like player coord, size of map...
void	map_size(t_data *data)
{
	int	i;
	int	len;
	int	cmp;

	i = -1;
	cmp = 0;
	while (data->map[++i])
	{
		len = 0;
		while (data->map[i][len])
		{
			if (data->map[i][len] == 'N' || data->map[i][len] == 'S'
				|| data->map[i][len] == 'E' || data->map[i][len] == 'W')
			{
				data->player.mapx = len;
				data->player.mapy = i;
				get_player_angle(&data->map[i][len], data);
			}
			len++;
		}
		if (len > cmp)
			cmp = len;
	}
	data->map_h = i;
	data->map_w = cmp;
}

//set images
void	set_up_img(t_data *data)
{
	data->no_text = NULL;
	data->so_text = NULL;
	data->we_text = NULL;
	data->ea_text = NULL;
	data->map = NULL;
	data->ceiling_colors = NULL;
	data->floor_colors = NULL;
	data->no.img = NULL;
	data->so.img = NULL;
	data->we.img = NULL;
	data->ea.img = NULL;
	data->bg.img = NULL;
	data->mini.map.img = NULL;
	data->micro.map.img = NULL;
	data->micro.hand.img = NULL;
	data->mini.player.img = NULL;
	data->wine.line.img = NULL;
}

//set diffrent things up
void	set_up(t_data *data)
{
	map_size(data);
	data->player.x = get_unmapx(data->player.mapx) + (TILE_SIZE / 2);
	data->player.y = get_unmapy(data->player.mapy) + (TILE_SIZE / 2);
	data->player.dirx = cosf(data->player.a);
	data->player.diry = sinf(data->player.a);
	data->forward = 0;
	data->backward = 0;
	data->left = 0;
	data->right = 0;
	data->r_right = 0;
	data->r_left = 0;
	data->mouse.h = 0;
	data->ray.side = 1;
	data->ray.mapx = -1;
	data->open_mmap = 0;
}
