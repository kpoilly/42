/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:02:18 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/11 18:15:34 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//calculate the distance between 2 points
float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

//get an x coord in the map from a coord in pixels
int	get_mapx(float x)
{
	return ((floorf(x)) / TILE_SIZE);
}

//get an y coord in the map from a coord in pixels
int	get_mapy(float y)
{
	return ((floorf(y) / TILE_SIZE));
}

//get an x coord in pixels from a coord in the map
float	get_unmapx(int x)
{
	return ((float)(x * TILE_SIZE));
}

//get an y coord in pixels from a coord in the map
float	get_unmapy(int y)
{
	return ((float)(y * TILE_SIZE));
}
