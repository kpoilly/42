/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:14:33 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/22 09:00:31 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

void	draw_walldoor(t_data *data)
{
	data->ray.midx = data->ray.x;
	data->ray.midy = data->ray.y;
	draw_door(data);
}

void	draw_obj(t_data *data)
{
	int		case_x;
	int		case_y;

	case_x = get_mapx(data->ray.midx);
	case_y = get_mapy(data->ray.midy);
	if (data->ray.midx == -1 || data->ray.midy == -1)
		return ;
	if (case_x >= 0 && case_x <= data->map_w && case_y >= 0
		&& case_y <= data->map_h && data->map[case_y][case_x]
		&& data->map[case_y][case_x] == 'D')
		draw_door(data);
}
