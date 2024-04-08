/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:10:28 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/08 08:22:56 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

int	keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy(data);
	else if (keycode == KEY_W)
		data->forward = 1;
	else if (keycode == KEY_S)
		data->backward = 1;
	else if (keycode == KEY_D)
		data->right = 1;
	else if (keycode == KEY_A)
		data->left = 1;
	else if (keycode == KEY_LEFT)
		data->r_left = 1;
	else if (keycode == KEY_RIGHT)
		data->r_right = 1;
	else if (keycode == KEY_M)
	{
		if (data->open_map == 1)
		{
			data->open_map = 0;
			draw_bg(data);
		}
		else if (data->open_map == 0)
			data->open_map = 1;
	}
	return (0);
}

int	keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy(data);
	else if (keycode == KEY_W)
		data->forward = 0;
	else if (keycode == KEY_S)
		data->backward = 0;
	else if (keycode == KEY_D)
		data->right = 0;
	else if (keycode == KEY_A)
		data->left = 0;
	else if (keycode == KEY_LEFT)
		data->r_left = 0;
	else if (keycode == KEY_RIGHT)
		data->r_right = 0;
	return (0);
}

int	no_event(t_data *data)
{
	raycasting(data);
	if (data->open_map)
		draw_minimap(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->bg.img, 0, 0);
	moves_forback(data);
	moves_leftright(data);
	rotate(data);
	return (0);
}

//Ferme la window de façon propre
int	destroy(t_data *data)
{
	free_textures(data);
	free_tab(data->map);
	free(data->ceiling_colors);
	free(data->floor_colors);
	free_paths(data);
	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	exit(0);
	return (0);
}

int	fire_exit(t_data *data, char **map)
{
	free_textures(data);
	free_tab(map);
	free(data->ceiling_colors);
	free(data->floor_colors);
	free_paths(data);
	mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	exit(1);
	return (0);
}
