/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:53:32 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/01 10:07:24 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

void	event_speed(t_data *data, int keycode)
{
	if (keycode == KEY_C)
	{
		data->crouch = 0.7;
		data->speed = 0.55;
	}
	else if (keycode == KEY_SH)
		data->speed = 1.5;
}

//can the player go on the case he's leading into
static int	can_move(t_data *data, float dir, float a, float coef)
{
	int	x;
	int	y;
	int	curx;
	int	cury;

	x = get_mapx(data->player.x + (dir * (cosf(a) * (PLAY_SPEED * 5 * coef))));
	y = get_mapy(data->player.y + (dir * (sinf(a) * (PLAY_SPEED * 5 * coef))));
	curx = get_mapx(data->player.x);
	cury = get_mapy(data->player.y);
	if (curx && cury && data->map[cury][curx] == 'D')
	{
		if (y > cury || x > curx)
			return (0);
		return (x && y && x < data->map_w && y < data->map_h
			&& (data->map[y][x] == '0' || data->map[y][x] == 'D'));
	}
	if (x && y && data->map[y][x] == 'D')
	{
		if (cury > y || curx > x)
			return (0);
		return (1);
	}
	return (x && y && x < data->map_w && y < data->map_h
		&& data->map[y][x] == '0');
}

//moves left and right
void	moves_leftright(t_data *data)
{
	float	turn_a;

	turn_a = 0;
	if (data->left && can_move(data, 1, data->player.a - (90 * DEG), 0.3))
	{
		turn_a = data->player.a - (90 * DEG);
		if (turn_a < 0)
			turn_a += 2 * PI;
		data->player.x += cosf(turn_a) * ((PLAY_SPEED * 0.6) * data->speed);
		data->player.y += sinf(turn_a) * ((PLAY_SPEED * 0.6) * data->speed);
		draw_bg(data);
	}
	if (data->right && can_move(data, -1, data->player.a - (90 * DEG), 0.3))
	{
		turn_a = data->player.a - (90 * DEG);
		if (turn_a < 0)
			turn_a += 2 * PI;
		data->player.x -= cosf(turn_a) * ((PLAY_SPEED * 0.6) * data->speed);
		data->player.y -= sinf(turn_a) * ((PLAY_SPEED * 0.6) * data->speed);
		draw_bg(data);
	}
}

//moves forward and backward
void	moves_forback(t_data *data)
{
	if (data->forward && can_move(data, 1, data->player.a, 1))
	{
		data->player.x += data->player.dirx * (PLAY_SPEED * data->speed);
		data->player.y += data->player.diry * (PLAY_SPEED * data->speed);
		draw_bg(data);
	}
	if (data->backward && can_move(data, -1, data->player.a, 1))
	{
		data->player.x -= data->player.dirx * (PLAY_SPEED * data->speed);
		data->player.y -= data->player.diry * (PLAY_SPEED * data->speed);
		draw_bg(data);
	}
}

//player's rotation
void	rotate(t_data *data)
{
	if (data->r_left || data->mr_left)
	{
		data->player.a -= 1 * DEG * ROT_SPEED * data->mouse.sen;
		if (data->player.a < 0)
			data->player.a += 2 * PI;
		data->player.dirx = cosf(data->player.a);
		data->player.diry = sinf(data->player.a);
		draw_bg(data);
	}
	if (data->r_right || data->mr_right)
	{
		data->player.a += 1 * DEG * ROT_SPEED * data->mouse.sen;
		if (data->player.a > 2 * PI)
			data->player.a -= 2 * PI;
		data->player.dirx = cosf(data->player.a);
		data->player.diry = sinf(data->player.a);
		draw_bg(data);
	}
}
