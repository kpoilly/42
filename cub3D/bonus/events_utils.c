/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:40:08 by lleciak           #+#    #+#             */
/*   Updated: 2024/04/23 09:12:25 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

void	mouse(t_data *data)
{
	mlx_mouse_get_pos(data->mlx.ptr, data->mlx.win,
		&data->mouse.x, &data->mouse.y);
	if (data->mouse.x >= (SC_W / 2) + 10)
		data->mr_right = 1;
	if (data->mouse.x <= (SC_W / 2) - 10)
		data->mr_left = 1;
	if (data->mr_left || data->mr_right)
		data->mouse.sen = abs(data->mouse.x - (SC_W / 2)) * 0.01;
	if (data->mouse.y >= (SC_H / 2) + 5 && data->mouse.h > -1000)
		data->mouse.h -= abs(data->mouse.y - (SC_H / 2)) * 0.5;
	if (data->mouse.y <= (SC_H / 2) - 5 && data->mouse.h < 800)
		data->mouse.h += abs(data->mouse.y - (SC_H / 2)) * 0.5;
	if (data->mouse.h < -1000)
		data->mouse.h = -1000;
	mlx_mouse_move(data->mlx.ptr, data->mlx.win, SC_W / 2, SC_H / 2);
}

void	draw_lol(t_data *data)
{
	put_img_to_img(data->bg, data->lol, (SC_W / 2) - 300,
		SC_H - 535);
}

//switch to the next frame of texture
void	switch_anim(t_data *data)
{
	int	timer;

	timer = ((long double)(clock() - data->anim_no.timer)
			/ CLOCKS_PER_SEC) * 1000;
	if (timer >= 400)
	{
		data->anim_no.timer = clock();
		data->anim_no.lst = data->anim_no.lst->next;
		data->anim_we.lst = data->anim_we.lst->next;
	}
	timer = ((long double)(clock() - data->anim_so.timer)
			/ CLOCKS_PER_SEC) * 1000;
	if (timer >= 50)
	{
		data->anim_so.timer = clock();
		data->anim_so.lst = data->anim_so.lst->next;
	}
	timer = ((long double)(clock() - data->anim_ea.timer)
			/ CLOCKS_PER_SEC) * 1000;
	if (timer >= 135)
	{
		data->anim_ea.timer = clock();
		data->anim_ea.lst = data->anim_ea.lst->next;
	}
}

//show easter eggs when key is pressed
static void	show_easter(t_data *data, int keycode)
{
	if (keycode == KEY_F)
	{
		if (data->open_lol == 1)
		{
			data->open_lol = 0;
			draw_bg(data);
		}
		else if (data->open_lol == 0 && data->open_mmap == 0)
			data->open_lol = 1;
	}
}

//show mini or micro map when the key is pressed
void	show_maps(t_data *data, int keycode)
{
	if (keycode == KEY_M)
	{
		if (data->open_map == 1)
		{
			data->open_map = 0;
			draw_bg(data);
		}
		else if (data->open_map == 0)
			data->open_map = 1;
	}
	else if (keycode == KEY_INT)
	{
		if (data->open_mmap == 1)
		{
			data->open_mmap = 0;
			draw_bg(data);
		}
		else if (data->open_mmap == 0 && data->open_lol == 0)
			data->open_mmap = 1;
	}
	show_easter(data, keycode);
}
