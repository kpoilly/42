/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:25:18 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/08 09:30:13 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

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

static int	set_color(t_data *data, t_ray *ray, float wall_h, int y_wall)
{
	float	case_x;
	float	case_y;

	case_x = get_unmapx(data, get_mapx(data, ray->x));
	case_y = get_unmapy(data, get_mapy(data, ray->y));
	if (floorf(ray->x) == roundf(case_x))
		return (set_x_color(data, data->ea, y_wall, wall_h));
	case_x += TILE_SIZE - 1.0;
	if (floorf(ray->x) == roundf(case_x))
		return (set_x_color(data, data->we, y_wall, wall_h));
	if (floorf(ray->y) == roundf(case_y))
		return (set_y_color(data, data->so, y_wall, wall_h));
	case_y += TILE_SIZE - 1.0;
	if (floorf(ray->y) == roundf(case_y))
		return (set_y_color(data, data->no, y_wall, wall_h));
	return (0xff0015);
}

void	draw_wall(t_data *data, t_ray ray, int nb_ray)
{
	float	wall_h;
	int		top;
	int		start;
	float	dis;
	int		color;

	dis = dist(data->player.x, data->player.y, ray.x, ray.y);
	if (dis <= 0)
		return ;
	wall_h = ((float)SC_H / dis) * ((float)TILE_SIZE);
	wall_h /= cos(ray.a - data->player.a);
	if (data->wine.line.img)
		mlx_destroy_image(data->mlx.ptr, data->wine.line.img);
	data->wine.line = load_img(data, data->wine.line, 1, wall_h);
	top = (SC_H / 2) - (wall_h / 2);
	start = 0;
	while (start < wall_h)
	{
		color = set_color(data, &(data->ray), wall_h, start);
		put_pixel(data->wine.line, 0, start++, color);
	}
	put_img_to_img(data->bg, data->wine.line, nb_ray, top);
}
