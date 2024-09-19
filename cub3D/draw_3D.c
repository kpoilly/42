/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:25:18 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/01 09:39:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//calculate the right pixel coord in the texture file (vert walls)
static int	set_x_color(t_data *data, t_img texture, int y_wall, float wall_h)
{
	data->ray.texx = (int)data->ray.y % (TILE_SIZE);
	data->ray.texx = ((float)data->ray.texx / (float)TILE_SIZE) * texture.w;
	data->ray.texy = (y_wall / wall_h) * texture.h;
	if (data->ray.texx < 0)
		data->ray.texx = 0;
	if (data->ray.texx > texture.w)
		data->ray.texx = texture.w;
	if (data->ray.texy < 0)
		data->ray.texy = 0;
	if (data->ray.texy > texture.h)
		data->ray.texy = texture.h;
	return (get_pixel(texture, data->ray.texx, data->ray.texy));
}

//calculate the right pixel coord in the texture file (hor walls)
static int	set_y_color(t_data *data, t_img texture, int y_wall, float wall_h)
{
	data->ray.texx = (int)data->ray.x % TILE_SIZE;
	data->ray.texx = ((float)data->ray.texx / (float)TILE_SIZE) * texture.w;
	data->ray.texy = (y_wall / wall_h) * texture.h;
	if (data->ray.texx < 0)
		data->ray.texx = 0;
	if (data->ray.texx > texture.w)
		data->ray.texx = texture.w;
	if (data->ray.texy < 0)
		data->ray.texy = 0;
	if (data->ray.texy > texture.h)
		data->ray.texy = texture.h;
	return (get_pixel(texture, data->ray.texx, data->ray.texy));
}

//check weither we see north, south, east or west face to get the right texture
static int	set_color(t_data *data, t_ray *ray, float wall_h, int y_wall)
{
	float	case_x;
	float	case_y;

	case_x = get_unmapx(get_mapx(ray->x));
	case_y = get_unmapy(get_mapy(ray->y));
	if (!ray->side && ray->mapx == get_mapx(ray->x))
	{
		if ((int)(ray->x) == roundf(case_x))
			return (set_x_color(data, data->ea, y_wall, wall_h));
		if ((int)(ray->x) == roundf(case_x + TILE_SIZE - 1.0))
			return (set_x_color(data, data->we, y_wall, wall_h));
	}
	ray->side = 1;
	if ((int)(ray->y) == roundf(case_y))
		return (set_y_color(data, data->so, y_wall, wall_h));
	if ((int)(ray->y) == roundf(case_y + TILE_SIZE - 1.0))
		return (set_y_color(data, data->no, y_wall, wall_h));
	ray->side = 0;
	ray->mapx = get_mapx(ray->x);
	if ((int)(ray->x) == roundf(case_x))
		return (set_x_color(data, data->ea, y_wall, wall_h));
	if ((int)(ray->x) == roundf(case_x + TILE_SIZE - 1.0))
		return (set_x_color(data, data->we, y_wall, wall_h));
	return (0xff0015);
}

//draw pixel column's height the right color (in texture file) pixel by pixel
static void	draw_col(t_data *data, float pixstart, float height, float top)
{
	int	i;
	int	color;

	data->wine.line = load_img(data, data->wine.line, 1, height);
	i = 0;
	while (i < height)
	{
		color = set_color(data, &(data->ray), data->ray.wall_h, pixstart++);
		put_pixel(data->wine.line, 0, i++, color);
	}
	put_img_to_img(data->bg, data->wine.line, data->ray.nb, top);
}

//get ray dist to set pixel column's height
void	draw_wall(t_data *data)
{
	float	top;
	float	dis;

	dis = dist(data->player.x, data->player.y, data->ray.x, data->ray.y);
	dis *= cos(data->ray.a - data->player.a);
	if (dis <= 0)
		return ;
	data->ray.wall_h = ((float)SC_H / dis) * ((float)TILE_SIZE + 15.0);
	if (data->wine.line.img)
		mlx_destroy_image(data->mlx.ptr, data->wine.line.img);
	top = ((float)SC_H / 2.0) - (data->ray.wall_h / 2.0);
	if (top < 0)
		draw_col(data, fabsf(top), SC_H, 0);
	else
		draw_col(data, 0, data->ray.wall_h, top);
}
