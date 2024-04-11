/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micromap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:30:42 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/10 15:53:19 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

void	draw_microray(t_data *data, float a)
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

void	draw_square(t_data *data)
{
	int	mapy;
	int	mapx;
	int	x;
	int	y;

	mapy = get_mapy(data->player.y) - 5;
	y = 0;
	while (mapy < 0)
	{
		mapy++;
		y++;
	}
	while (data->map[mapy] && y <= 11)
	{
		mapx = get_mapx(data->player.x) - 4;
		x = 0;
		while (mapx < 0)
		{
			mapx++;
			x++;
		}
		while (data->map[mapy][mapx] && x <= 9)
		{
			if (data->map[mapy][mapx] == '1')
				draw_microwall(data, x * data->micro.sq_size,
					y * data->micro.sq_size, data->mini.w_color);
			else if (data->map[mapy][mapx] != ' ')
				draw_microwall(data, x * data->micro.sq_size,
					y * data->micro.sq_size, data->mini.g_color);
			if (mapy == get_mapy(data->player.y)
				&& mapx == get_mapx(data->player.x))
				draw_microplayer(data, x * data->micro.sq_size,
					y * data->micro.sq_size, data->mini.p_color);
			x++;
			mapx++;
		}
		y++;
		mapy++;
	}
}

void	draw_micromap(t_data *data)
{
	draw_hand(data, data->micro.hand, "./utils/textures/TABLETTEV2.xpm");
	if (data->micro.map.img)
		mlx_destroy_image(data->mlx.ptr, data->micro.map.img);
	data->micro.map = load_img(data, data->micro.map,
			data->micro.w, data->micro.h);
	draw_square(data);
	draw_microray(data, data->player.a);
	put_img_to_img(data->bg, data->micro.map,
		(SC_W / 2) - (data->micro.w / 2) - 197, SC_H - data->micro.h - 78);
	draw_hand(data, data->micro.thumb, "./utils/textures/pouce.xpm");
}
