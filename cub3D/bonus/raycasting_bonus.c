/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:36:48 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/22 09:03:52 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

static void	hit_obj(t_data *data, int mx, int my)
{
	if ((((int)(data->ray.y) == roundf(get_unmapy(my) + TILE_SIZE - 1.0))
		&& data->map[my][mx - 1] == '1' && data->map[my][mx + 1] == '1')
	|| (((int)(data->ray.x) == roundf(get_unmapy(mx) + TILE_SIZE - 1.0))
		&& data->map[my][mx - 1] != '1' && data->map[my][mx + 1] != '1'))
	{
		if (mx != data->ray.prevx || my != data->ray.prevy)
		{
			data->ray.obj++;
			data->ray.prevx = mx;
			data->ray.prevy = my;
		}
		if (data->ray.obj > 1)
			data->ray.hit = 2;
		if (data->ray.midx == -1 && data->ray.midy == -1)
		{
			data->ray.midx = data->ray.x;
			data->ray.midy = data->ray.y;
		}
	}
	if (!data->ray.hit)
	{
		data->ray.x += cosf(data->ray.a);
		data->ray.y += sinf(data->ray.a);
	}
}

//check if the ray hits a wall
void	check_hit(t_data *data, int mx, int my)
{
	if (mx >= 0 && mx < data->map_w && my >= 0 && my < data->map_h
		&& data->map[my][mx] && data->map[my][mx] == '1')
		data->ray.hit = 1;
	else if (mx >= 0 && mx < data->map_w && my >= 0 && my < data->map_h
		&& data->map[my][mx] && data->map[my][mx] == '0')
	{
		data->ray.x += cosf(data->ray.a);
		data->ray.y += sinf(data->ray.a);
	}
	else if (mx >= 0 && mx < data->map_w && my >= 0 && my < data->map_h
		&& data->map[my][mx] && data->map[my][mx] == 'D')
		hit_obj(data, mx, my);
	else
		data->ray.hit = 1;
}

//draw_ray(data, data->ray.a, data->ray.x, data->ray.y);
void	raycasting(t_data *data)
{
	data->ray.a = (data->player.a - ((FOV / 2) * DEG));
	data->ray.nb = 0;
	while (data->ray.nb < SC_W)
	{
		data->ray.x = data->player.x;
		data->ray.y = data->player.y;
		data->ray.hit = 0;
		data->ray.obj = 0;
		data->ray.midx = -1;
		data->ray.midy = -1;
		data->ray.prevx = -1;
		data->ray.prevy = -1;
		while (!data->ray.hit)
			check_hit(data, get_mapx(data->ray.x), get_mapy(data->ray.y));
		if (data->ray.nb == SC_W / 2)
		{
			data->player.ax = data->ray.midx;
			data->player.ay = data->ray.midy;
		}
		draw_wall(data);
		data->ray.a += ((float)FOV / (float)SC_W) * DEG;
		data->ray.nb++;
	}
}
