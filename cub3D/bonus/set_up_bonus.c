/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/09/17 19:26:45 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

//set the angle the player is looking for on spawn
static void	get_player_angle(char *c, t_data *data)
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
static void	map_size(t_data *data)
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
	data->lol.img = NULL;
	data->crocs.img = NULL;
	data->anim_ea.lst = NULL;
	data->anim_no.lst = NULL;
	data->anim_so.lst = NULL;
	data->anim_we.lst = NULL;
	data->door_tex.lst = NULL;
}

//set mini and micro maps values
void	set_up_mini(t_data *data)
{
	data->mini.sq_size = 20;
	data->mini.h = data->map_h * data->mini.sq_size;
	data->mini.w = data->map_w * data->mini.sq_size;
	data->mini.map.img = NULL;
	data->mini.player.img = NULL;
	data->mini.g_color = 0x080606;
	data->mini.w_color = 0x333633;
	data->mini.p_color = 0x04ff00;
	data->mini.x = ((float)SC_W / 2.0) - ((float)data->mini.w / 2.0);
	data->mini.y = ((float)SC_H / 2.0) - ((float)data->mini.h / 2.0);
	data->micro.sq_size = 25;
	data->micro.w = 9 * data->micro.sq_size;
	data->micro.h = 11 * data->micro.sq_size;
	data->crouch = 1;
	data->speed = 1;
}

//set diffrent things up
void	set_up(t_data *data)
{
	map_size(data);
	set_up_mini(data);
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
	data->mr_right = 0;
	data->mr_left = 0;
	data->open_map = 0;
	data->open_mmap = 0;
	data->open_lol = 0;
	data->open_door = 0;
	data->mouse.h = 0;
	data->mouse.sen = 1;
	data->nb_doors = -1;
	data->ray.side = 1;
	data->ray.mapx = -1;
	set_door_list(data);
}
