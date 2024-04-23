/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:36:48 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/16 08:30:07 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//check if the ray hits a wall
void	check_hit(t_data *data, t_ray ray)
{
	int	mx;
	int	my;

	mx = get_mapx(ray.x);
	my = get_mapy(ray.y);
	if (mx >= 0 && mx < data->map_w && my >= 0 && my < data->map_h
		&& data->map[my][mx] && data->map[my][mx] == '1')
		data->ray.hit = 1;
	else if (mx >= 0 && mx < data->map_w && my >= 0 && my < data->map_h
		&& data->map[my][mx] && data->map[my][mx] == '0')
	{
		data->ray.x += cosf(data->ray.a);
		data->ray.y += sinf(data->ray.a);
	}
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
		while (data->ray.hit != 1)
			check_hit(data, data->ray);
		draw_wall(data);
		data->ray.a += ((float)FOV / (float)SC_W) * DEG;
		data->ray.nb++;
	}
}
