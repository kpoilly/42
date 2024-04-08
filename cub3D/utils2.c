/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:02:18 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/08 08:08:17 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

int	get_mapx(t_data *data, float x)
{
	return ((floorf(x) - data->mini.x) / TILE_SIZE);
}

int	get_mapy(t_data *data, float y)
{
	return ((floorf(y) - data->mini.y) / TILE_SIZE);
}

float	get_unmapx(t_data *data, int x)
{
	return ((float)(x * TILE_SIZE) + data->mini.x);
}

float	get_unmapy(t_data *data, int y)
{
	return ((float)(y * TILE_SIZE) + data->mini.y);
}
