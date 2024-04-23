/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:46:56 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/11 18:14:36 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//moves left and right
void	moves_leftright(t_data *data)
{
	float	turn_a;

	turn_a = 0;
	if (data->left)
	{
		turn_a = data->player.a - (90 * DEG);
		if (turn_a < 0)
			turn_a += 2 * PI;
		data->player.x += cosf(turn_a) * (PLAY_SPEED * 0.6);
		data->player.y += sinf(turn_a) * (PLAY_SPEED * 0.6);
		draw_bg(data);
	}
	if (data->right)
	{
		turn_a = data->player.a - (90 * DEG);
		if (turn_a < 0)
			turn_a += 2 * PI;
		data->player.x -= cosf(turn_a) * (PLAY_SPEED * 0.6);
		data->player.y -= sinf(turn_a) * (PLAY_SPEED * 0.6);
		draw_bg(data);
	}
}

//moves forward and backward
void	moves_forback(t_data *data)
{
	if (data->forward)
	{
		data->player.x += data->player.dirx * PLAY_SPEED;
		data->player.y += data->player.diry * PLAY_SPEED;
		draw_bg(data);
	}
	if (data->backward)
	{
		data->player.x -= data->player.dirx * PLAY_SPEED;
		data->player.y -= data->player.diry * PLAY_SPEED;
		draw_bg(data);
	}
}

//player's rotation
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
