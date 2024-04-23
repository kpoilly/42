/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:40:01 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/11 18:06:46 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

//draw the whole minimap with every components
void	draw_minimap(t_data *data)
{
	int	y;
	int	x;

	if (data->mini.map.img)
		mlx_destroy_image(data->mlx.ptr, data->mini.map.img);
	data->mini.map = load_img(data, data->mini.map, data->mini.w, data->mini.h);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_miniwall(data, x * data->mini.sq_size,
					y * data->mini.sq_size, data->mini.w_color);
			else if (data->map[y][x] == '0')
				draw_miniwall(data, x * data->mini.sq_size,
					y * data->mini.sq_size, data->mini.g_color);
			x++;
		}
		y++;
	}
	draw_player(data);
	put_img_to_img(data->bg, data->mini.map, (SC_W / 2) - (data->mini.w / 2),
		(SC_H / 2) - (data->mini.h / 2));
}
