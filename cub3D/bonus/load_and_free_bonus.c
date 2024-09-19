/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_and_free_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:33:17 by kpoilly           #+#    #+#             */
/*   Updated: 2024/09/17 19:32:04 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

//load a new mlx image (not a texture)
t_img	load_img(t_data *data, t_img toload, int width, int height)
{
	if (height <= 0)
		return (toload.img = NULL, toload);
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

//load a texture into an mlx image
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

//free the paths char *
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

//free every frame of animations (not complete yet, need to free the t_img)
void	free_anim(t_data *data, t_anim *texture, int loop)
{
	int		i;
	t_img	*current;
	t_img	*next;

	if (!texture->lst->img)
		return (free(texture->lst), (void) NULL);
	if (!loop)
		while (texture->lst->prev)
			texture->lst = texture->lst->prev;
	i = 0;
	current = texture->lst;
	while (i < texture->size && current)
	{
		if (current->img)
			mlx_destroy_image(data->mlx.ptr, current->img);
		if (current->next)
			next = current->next;
		else
			next = NULL;
		free(current);
		current = next;
		i++;
	}
}

//free every textures
int	free_textures(t_data *data)
{
	if (data->anim_no.lst)
		free_anim(data, &data->anim_no, 1);
	if (data->anim_no.lst)
		free_anim(data, &data->anim_so, 1);
	if (data->anim_no.lst)
		free_anim(data, &data->anim_we, 1);
	if (data->anim_no.lst)
		free_anim(data, &data->anim_ea, 1);
	if (data->anim_no.lst)
		free_anim(data, &data->door_tex, 0);
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
	free_text_extra(data);
	return (1);
}
