/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:45:44 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/23 07:55:47 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

// char	*rgb_to_hex(int rgb[3], char *base)
// {
// 	char	*hex;
// 	char	*tmp;
// 	float	res;
// 	int		sub;
// 	int		i;

// 	hex = "0x";
// 	i = 0;
// 	while (i < 3)
// 	{
// 		res = (float)rgb[i] / 16;
// 		sub = (int)res;
// 		res = (res - sub) * 16;
// 		tmp = ft_strjoin_char(hex, base[sub], base[(int)res]);
// 		if (i)
// 			free(hex);
// 		if (!tmp)
// 			return (NULL);
// 		hex = ft_strdup(tmp);
// 		free(tmp);
// 		i++;
// 	}
// 	return (hex);
// }

void	draw_floor(t_data *data)
{
	int		x;
	int		y;
	int		color_hex;

	color_hex = rgb_to_hex(data->floor_colors);
	y = (SC_H / 2) + data->mouse.h;
	while (y < SC_H)
	{
		x = 0;
		while (x < SC_W)
			put_pixel(data->bg, x++, y, color_hex);
		y++;
	}
}

void	draw_ceiling(t_data *data)
{
	int		x;
	int		y;
	int		color_hex;

	color_hex = rgb_to_hex(data->ceiling_colors);
	y = 0;
	while (y < (SC_H / 2) + data->mouse.h)
	{
		x = 0;
		while (x < SC_W)
			put_pixel(data->bg, x++, y, color_hex);
		y++;
	}
}

void	draw_bg(t_data *data)
{
	if (data->bg.img)
		mlx_destroy_image(data->mlx.ptr, data->bg.img);
	data->bg = load_img(data, data->bg, SC_W, SC_H);
	draw_ceiling(data);
	draw_floor(data);
}
