/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:10:28 by kpoilly           #+#    #+#             */
/*   Updated: 2024/09/17 16:28:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//wich key is pressed
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
	else if (keycode == KEY_INT)
	{
		if (data->open_mmap == 1)
		{
			data->open_mmap = 0;
			draw_bg(data);
		}
		else if (data->open_mmap == 0)
			data->open_mmap = 1;
	}
	return (0);
}

//wich key is released
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

//idle events
int	no_event(t_data *data)
{
	moves_forback(data);
	moves_leftright(data);
	rotate(data);
	raycasting(data);
	if (data->open_mmap)
		draw_micromap(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->bg.img, 0, 0);
	return (0);
}

//close the window properly
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

//kill the program properly
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
