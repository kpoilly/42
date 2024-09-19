/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:10:28 by kpoilly           #+#    #+#             */
/*   Updated: 2024/09/17 19:15:31 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

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
	{
		data->r_left = 1;
		data->mouse.sen = 1;
	}
	else if (keycode == KEY_RIGHT)
	{
		data->r_right = 1;
		data->mouse.sen = 1;
	}
	else if (keycode == KEY_E)
		data->open_door = 1;
	event_speed(data, keycode);
	show_maps(data, keycode);
	return (0);
}

//wich key is released
int	keyrelease(int keycode, t_data *data)
{
	if (keycode == KEY_W)
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
	else if (keycode == KEY_E)
		data->open_door = 0;
	else if (keycode == KEY_E)
		data->open_door = 1;
	else if (keycode == KEY_C)
	{
		data->crouch = 1;
		data->speed = 1;
	}
	else if (keycode == KEY_SH)
		data->speed = 1;
	return (0);
}

//idle events
int	no_event(t_data *data)
{
	mouse(data);
	moves_forback(data);
	moves_leftright(data);
	rotate(data);
	draw_bg(data);
	raycasting(data);
	open_doors(data);
	doors(data);
	switch_anim(data);
	if (data->mouse.h < -700)
		put_img_to_img(data->bg, data->crocs, SC_W / 2 - (data->crocs.w / 2),
			SC_H + (data->mouse.h + 700));
	if (data->open_map)
		draw_minimap(data);
	if (data->open_mmap)
		draw_micromap(data);
	if (data->open_lol)
		draw_lol(data);
	data->mr_right = 0;
	data->mr_left = 0;
	data->mouse.sen = 1;
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
	free(data->doors);
	free_paths(data);
	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	ft_printf(2, "[1]    2218342 segmentation fault (core dumped)\
		\nnon jdec mdr :]\n");
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
