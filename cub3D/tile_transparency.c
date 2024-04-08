/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_transparency.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:19:21 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/05 11:35:35 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//get the pixel to copy
unsigned int	get_pixel(t_img img, int x, int y)
{
	return (*(unsigned int *)(
		(img.addr + (y * img.line_len) + (x * img.bits_per_pixel / 8))));
}

//copy the pixel on an img, ignore transparency
void	put_pixel(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

//copy an img on another
void	put_img_to_img(t_img dst, t_img src, int x, int y)
{
	int	j;
	int	i;

	i = 0;
	while (i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			put_pixel(dst, x + i, y + j, get_pixel(src, i, j));
			j++;
		}
		i++;
	}
}
