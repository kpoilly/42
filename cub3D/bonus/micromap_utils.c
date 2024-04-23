/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micromap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:21:46 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/16 11:04:06 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

void	draw_microthing(t_data *data, int mapx, int mapy, float y)
{
	if (data->map[mapy][mapx] == '1')
		draw_microwall(data, data->micro.objx * data->micro.sq_size,
			y * data->micro.sq_size, data->mini.w_color);
	else if (data->map[mapy][mapx] == '0')
		draw_microwall(data, data->micro.objx * data->micro.sq_size,
			y * data->micro.sq_size, data->mini.g_color);
	else if (data->map[mapy][mapx] == 'D')
		draw_microwall(data, data->micro.objx * data->micro.sq_size,
			y * data->micro.sq_size, 0xcfa85f);
	if (mapy == get_mapy(data->player.y)
		&& mapx == get_mapx(data->player.x))
		draw_microplayer(data, data->micro.objx * data->micro.sq_size,
			y * data->micro.sq_size, data->mini.p_color);
}
