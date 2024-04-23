/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micromap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:30:42 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/16 11:04:48 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

//draw a ray on the micro map
static void	draw_microray(t_data *data, float a)
{
	int		i;
	float	x;
	float	y;
	float	dix;
	float	diy;

	dix = cosf(a);
	diy = sinf(a);
	i = 0;
	x = (data->micro.w / 2);
	y = (data->micro.h / 2);
	while (i < 35)
	{
		put_pixel(data->micro.map, x, y, data->mini.p_color);
		x += dix;
		y += diy;
		i++;
	}
}

//draw the player's position on the micromap
void	draw_microplayer(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	x += (data->micro.sq_size / 2) / 2;
	y += (data->micro.sq_size / 2) / 2;
	i = 0;
	while (i < data->micro.sq_size / 2)
	{
		j = 0;
		while (j < data->micro.sq_size / 2)
		{
			if (!i || !j || i == data->micro.sq_size - 1
				|| j == data->micro.sq_size - 1)
				put_pixel(data->micro.map, x + j, y + i, data->mini.w_color);
			else
				put_pixel(data->micro.map, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

//draw a wall on the micromap
void	draw_microwall(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->micro.sq_size)
	{
		j = 0;
		while (j < data->micro.sq_size)
		{
			if (!i || !j || i == data->micro.sq_size - 1
				|| j == data->micro.sq_size - 1)
				put_pixel(data->micro.map, x + j, y + i, data->mini.w_color);
			else
				put_pixel(data->micro.map, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

//draw a square on the micromap
static void	draw_square(t_data *data, int mapy, int y)
{
	int	mapx;

	while (++mapy < 0)
		y++;
	while (data->map[mapy] && y <= 11)
	{
		mapx = get_mapx(data->player.x) - 5;
		data->micro.objx = 0;
		while (++mapx < 0)
			data->micro.objx++;
		while (data->map[mapy][mapx] && data->micro.objx <= 9)
		{
			draw_microthing(data, mapx, mapy, y);
			data->micro.objx++;
			mapx++;
		}
		y++;
		mapy++;
	}
}

//draw the whole micromap with every components
void	draw_micromap(t_data *data)
{
	if (data->micro.map.img)
		mlx_destroy_image(data->mlx.ptr, data->micro.map.img);
	data->micro.map = load_img(data, data->micro.map,
			data->micro.w, data->micro.h);
	draw_square(data, get_mapy(data->player.y) - 6, 0);
	draw_microray(data, data->player.a);
	put_img_to_img(data->bg, data->micro.map,
		(SC_W / 2) - (data->micro.w / 2) - 197, SC_H - data->micro.h - 78);
	put_img_to_img(data->bg, data->micro.hand, (SC_W / 2) - 500, SC_H - 535);
}
