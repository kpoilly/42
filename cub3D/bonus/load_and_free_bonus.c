/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_and_free_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:33:17 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/11 09:45:29 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

t_img	load_img(t_data *data, t_img toload, int width, int height)
{
	toload.img = mlx_new_image(data->mlx.ptr, width,
			height);
	if (!toload.img)
		return (ft_printf(2, "Error.\n(load_img)\n"), toload);
	toload.w = width;
	toload.h = height;
	toload.addr = mlx_get_data_addr(toload.img,
			&toload.bits_per_pixel, &toload.line_len,
			&toload.endian);
	return (toload);
}

int	load_texture(t_data *data, t_img *img, char *path)
{
	img->w = TILE_SIZE;
	img->h = TILE_SIZE;
	img->img = mlx_xpm_file_to_image(data->mlx.ptr, path, &img->w, &img->h);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_len,
			&img->endian);
	return (1);
}

void	free_paths(t_data *data)
{
	if (data->no_text)
		free(data->no_text);
	if (data->so_text)
		free(data->so_text);
	if (data->we_text)
		free(data->we_text);
	if (data->ea_text)
		free(data->ea_text);
}

// void	free_anim(t_data *data, t_anim *texture)
// {
// 	int	i;

// 	i = 0;
// 	while (i < texture->size)
// 	{
// 		if (texture->tex->img)
// 			mlx_destroy_image(data->mlx.ptr, texture->tex->img);
// 		if (texture->tex->next)
// 			texture->tex = texture->tex->next;
// 	}
// }

int	free_textures(t_data *data)
{
	//free_anim(data, &data->no);
	//free_anim(data, &data->so);
	//free_anim(data, &data->we);
	//free_anim(data, &data->ea);
	if (data->no.img)
		mlx_destroy_image(data->mlx.ptr, data->no.img);
	if (data->so.img)
		mlx_destroy_image(data->mlx.ptr, data->so.img);
	if (data->we.img)
		mlx_destroy_image(data->mlx.ptr, data->we.img);
	if (data->ea.img)
		mlx_destroy_image(data->mlx.ptr, data->ea.img);
	if (data->bg.img)
		mlx_destroy_image(data->mlx.ptr, data->bg.img);
	if (data->mini.map.img)
		mlx_destroy_image(data->mlx.ptr, data->mini.map.img);
	if (data->mini.player.img)
		mlx_destroy_image(data->mlx.ptr, data->mini.player.img);
	if (data->wine.line.img)
		mlx_destroy_image(data->mlx.ptr, data->wine.line.img);
	if (data->micro.map.img)
		mlx_destroy_image(data->mlx.ptr, data->micro.map.img);
	if (data->micro.hand.img)
		mlx_destroy_image(data->mlx.ptr, data->micro.hand.img);
	if (data->micro.thumb.img)
		mlx_destroy_image(data->mlx.ptr, data->micro.thumb.img);
	return (1);
}
