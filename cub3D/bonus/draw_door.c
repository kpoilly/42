/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:14:33 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/01 09:53:14 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

static int	get_color(t_data *data, t_img texture, int y_wall, float obj_h)
{
	if (data->ray.side)
		data->ray.texx = (int)data->ray.midy % TILE_SIZE;
	else
		data->ray.texx = (int)data->ray.midx % TILE_SIZE;
	data->ray.texx = ((float)data->ray.texx / (float)TILE_SIZE) * texture.w;
	if (!data->ray.side)
		data->ray.texx = texture.w - data->ray.texx - 1;
	data->ray.texy = (y_wall / obj_h) * texture.h;
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
static int	set_color(t_data *data, t_ray *ray, float obj_h, int y_wall)
{
	int		case_x;
	int		case_y;
	int		color;
	t_door	*door;

	case_x = get_mapx(ray->midx);
	case_y = get_mapy(ray->midy);
	data->ray.side = 1;
	color = 0xff0015;
	if ((int)(ray->midy) == roundf(get_unmapy(case_y))
	|| (int)(ray->midy) == roundf(get_unmapy(case_y) + TILE_SIZE - 1.0))
		data->ray.side = 0;
	if (case_x >= 0 && case_x <= data->map_w && case_y >= 0
		&& case_y <= data->map_h && data->map[case_y][case_x]
		&& data->map[case_y][case_x] == 'D')
	{
		door = get_door(data, ray->midx, ray->midy);
		color = get_color(data, *(door->img.lst), y_wall, obj_h);
	}
	return (color);
}

//draw pixel column's height the right color (in texture file) pixel by pixel
static void	draw_col(t_data *data, float pixstart, float height, float top)
{
	int	i;
	int	color;

	if (set_color(data, &(data->ray),
			data->ray.obj_h, pixstart) == (int)0xFF000000)
	{	
		data->ray.obj = 0;
		return ;
	}
	if (height < 1)
		height = 0;
	if (height > SC_H)
		height = SC_H;
	if (data->wine.line.img)
		mlx_destroy_image(data->mlx.ptr, data->wine.line.img);
	data->wine.line = load_img(data, data->wine.line, 1, height);
	i = 0;
	while (i < height)
	{
		color = set_color(data, &(data->ray), data->ray.obj_h, pixstart++);
		put_pixel(data->wine.line, 0, i++, color);
	}
	if (data->wine.line.img)
		put_img_to_img(data->bg, data->wine.line, data->ray.nb, top);
}

void	draw_door(t_data *data)
{
	float	dis;
	float	top;

	if (data->ray.midx == -1 || data->ray.midy == -1)
		return ;
	dis = dist(data->player.x, data->player.y, data->ray.midx, data->ray.midy);
	dis *= cos(data->ray.a - data->player.a);
	if (dis <= 0)
		return ;
	data->ray.obj_h = ((float)SC_H / dis) * ((float)TILE_SIZE + 15.0);
	top = ((float)SC_H / 2.0) - (data->ray.obj_h / (2.0 * data->crouch))
		+ data->mouse.h;
	if (top < 0)
		draw_col(data, fabsf(top), data->ray.obj_h - fabsf(top), 0);
	else
		draw_col(data, 0, data->ray.obj_h, top);
}
