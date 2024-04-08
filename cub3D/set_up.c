/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/05 13:33:50 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

void	get_player_angle(char c, t_data *data)
{
	if (c == 'N')
		data->player.a = (3 * PI) / 2;
	else if (c == 'S')
		data->player.a = PI / 2;
	else if (c == 'E')
		data->player.a = 2 * PI;
	else if (c == 'W')
		data->player.a = PI;
}

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
				get_player_angle(data->map[i][len], data);
			}
			len++;
		}
		if (len > cmp)
			cmp = len;
	}
	data->map_h = i;
	data->map_w = cmp;
}

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
	data->wine.line.img = NULL;
}

void	set_up(t_data *data)
{
	data->mini.sq_size = TILE_SIZE;
	map_size(data);
	data->mini.h = data->map_h * data->mini.sq_size;
	data->mini.w = data->map_w * data->mini.sq_size;
	set_up_mini(data);
	data->player.x = get_unmapx(data, data->player.mapx);
	data->player.y = get_unmapy(data, data->player.mapy);
	data->player.dirx = cosf(data->player.a);
	data->player.diry = sinf(data->player.a);
	data->forward = 0;
	data->backward = 0;
	data->left = 0;
	data->right = 0;
	data->r_right = 0;
	data->r_left = 0;
	data->ray.mapx = -1;
	data->ray.mapy = -1;
}

void	set_up_mini(t_data *data)
{
	data->mini.map.img = NULL;
	data->mini.player.img = NULL;
	data->mini.g_color = 0x080606;
	data->mini.w_color = 0x333633;
	data->mini.p_color = 0x04ff00;
	data->mini.x = ((float)SC_W / 2.0) - ((float)data->mini.w / 2.0);
	data->mini.y = ((float)SC_H / 2.0) - ((float)data->mini.h / 2.0);
	data->open_map = 0;
}
