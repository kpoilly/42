/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:40:32 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/11 18:06:30 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

//draw the raycasting's ray (not used)
void	draw_ray(t_data *data, float a, float endx, float endy)
{
	int		i;
	float	x;
	float	y;
	float	dix;
	float	diy;

	dix = cosf(a);
	diy = sinf(a);
	i = 0;
	x = data->player.x;
	y = data->player.y;
	while (((((int)x - data->mini.x) / TILE_SIZE)
			!= (((int)endx - data->mini.x) / TILE_SIZE)
			|| (((int)y - data->mini.y) / TILE_SIZE)
			!= (((int)endy - data->mini.y) / TILE_SIZE))
		&& i < 800)
	{
		put_pixel(data->bg, (int)x, (int)y, 0x3e4bbd);
		x += dix;
		y += diy;
		i++;
	}
}

//draw a ray on the minimap
void	draw_miniray(t_data *data, float a)
{
	int		i;
	float	x;
	float	y;
	float	dix;
	float	diy;

	dix = cosf(a);
	diy = sinf(a);
	i = 0;
	x = (data->player.x / TILE_SIZE) * data->mini.sq_size;
	y = (data->player.y / TILE_SIZE) * data->mini.sq_size;
	while (i < 45)
	{
		put_pixel(data->mini.map, x, y, data->mini.p_color);
		x += dix;
		y += diy;
		i++;
	}
}

//draw the player's position on the minimap
void	draw_player(t_data *data)
{
	int		i;
	int		j;
	int		px;
	int		py;

	if (data->mini.player.img)
		mlx_destroy_image(data->mlx.ptr, data->mini.player.img);
	data->mini.player = load_img(data, data->mini.player,
			data->mini.sq_size / 2, data->mini.sq_size / 2);
	i = -1;
	while (i++ < data->mini.sq_size / 2)
	{
		j = -1;
		while (j++ < data->mini.sq_size / 2)
			put_pixel(data->mini.player, j, i, data->mini.p_color);
	}
	px = (data->player.x / TILE_SIZE) * data->mini.sq_size;
	py = (data->player.y / TILE_SIZE) * data->mini.sq_size;
	put_img_to_img(data->mini.map, data->mini.player,
		px - ((data->mini.sq_size / 2) / 2),
		py - ((data->mini.sq_size / 2) / 2));
	draw_miniray(data, data->player.a - ((FOV / 2) * DEG));
	draw_miniray(data, data->player.a + ((FOV / 2) * DEG));
}

//draw a wall on the minimap
void	draw_miniwall(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mini.sq_size)
	{
		j = 0;
		while (j < data->mini.sq_size)
		{
			if (!i || !j || i == data->mini.sq_size - 1
				|| j == data->mini.sq_size - 1)
				put_pixel(data->mini.map, x + j, y + i, data->mini.w_color);
			else
				put_pixel(data->mini.map, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
