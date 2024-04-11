/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:02:18 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/09 10:44:14 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

int	get_mapx(float x)
{
	return ((floorf(x)) / TILE_SIZE);
}

int	get_mapy(float y)
{
	return ((floorf(y) / TILE_SIZE));
}

float	get_unmapx(int x)
{
	return ((float)(x * TILE_SIZE));
}

float	get_unmapy(int y)
{
	return ((float)(y * TILE_SIZE));
}
