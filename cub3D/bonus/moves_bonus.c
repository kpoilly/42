/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:53:32 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/11 11:11:54 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

static int	can_move(t_data *data, int dir, float a, float coef)
{
	int	x;
	int	y;

	x = data->player.x + (dir * (cosf(a) * (PLAY_SPEED * 5 * coef)));
	x = get_mapx(x);
	y = data->player.y + (dir * (sinf(a) * (PLAY_SPEED * 5 * coef)));
	y = get_mapy(y);
	return (x && y && x < data->map_w && y < data->map_h
		&& data->map[y][x] != '1' && data->map[y][x] != 'D');
}

void	moves_leftright(t_data *data)
{
	float	turn_a;

	turn_a = 0;
	if (data->left && can_move(data, 1, data->player.a - (90 * DEG), 0.3))
	{
		turn_a = data->player.a - (90 * DEG);
		if (turn_a < 0)
			turn_a += 2 * PI;
		data->player.x += cosf(turn_a) * (PLAY_SPEED * 0.6);
		data->player.y += sinf(turn_a) * (PLAY_SPEED * 0.6);
		draw_bg(data);
	}
	if (data->right && can_move(data, -1, data->player.a - (90 * DEG), 0.3))
	{
		turn_a = data->player.a - (90 * DEG);
		if (turn_a < 0)
			turn_a += 2 * PI;
		data->player.x -= cosf(turn_a) * (PLAY_SPEED * 0.6);
		data->player.y -= sinf(turn_a) * (PLAY_SPEED * 0.6);
		draw_bg(data);
	}
}

void	moves_forback(t_data *data)
{
	if (data->forward && can_move(data, 1, data->player.a, 1))
	{
		data->player.x += data->player.dirx * PLAY_SPEED;
		data->player.y += data->player.diry * PLAY_SPEED;
		draw_bg(data);
	}
	if (data->backward && can_move(data, -1, data->player.a, 1))
	{
		data->player.x -= data->player.dirx * PLAY_SPEED;
		data->player.y -= data->player.diry * PLAY_SPEED;
		draw_bg(data);
	}
}

void	rotate(t_data *data)
{
	if (data->r_left)
	{
		data->player.a -= 1 * DEG * ROT_SPEED;
		if (data->player.a < 0)
			data->player.a += 2 * PI;
		data->player.dirx = cosf(data->player.a);
		data->player.diry = sinf(data->player.a);
		draw_bg(data);
	}
	if (data->r_right)
	{
		data->player.a += 1 * DEG * ROT_SPEED;
		if (data->player.a > 2 * PI)
			data->player.a -= 2 * PI;
		data->player.dirx = cosf(data->player.a);
		data->player.diry = sinf(data->player.a);
		draw_bg(data);
	}
}
