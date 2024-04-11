/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:40:08 by lleciak           #+#    #+#             */
/*   Updated: 2024/04/11 10:36:18 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

void	switch_anim(t_data *data)
{
	int	timer;

	timer = ((long double)(clock() - data->time_no) / CLOCKS_PER_SEC) * 1000;
	if (timer >= 400)
	{
		data->time_no = clock();
		data->anim_no = data->anim_no->next;
		data->anim_we = data->anim_we->next;
	}
	timer = ((long double)(clock() - data->time_so) / CLOCKS_PER_SEC) * 1000;
	if (timer >= 50)
	{
		data->time_so = clock();
		data->anim_so = data->anim_so->next;
	}
}

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
		else if (data->open_mmap == 0)
			data->open_mmap = 1;
	}
}
