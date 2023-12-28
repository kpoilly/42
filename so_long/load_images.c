/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:01:06 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/28 19:33:26 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Charge les xpm murs dans les buffers
int	load_walls(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->wallin.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.wallin, &w, &h);
	if (!global->wallin.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->wallin.addr = mlx_get_data_addr(global->wallin.img,
			&(global->wallin.bits_per_pixel), &(global->wallin.line_len),
			&(global->wallin.endian));
	global->wallin.w = w;
	global->wallin.h = h;
	global->wallout.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.wallout, &w, &h);
	if (!global->wallout.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->wallout.addr = mlx_get_data_addr(global->wallout.img,
			&(global->wallout.bits_per_pixel), &(global->wallout.line_len),
			&(global->wallout.endian));
	global->wallout.w = w;
	global->wallout.h = h;
	return (1);
}

//Charge le xpm de la sortie dans un buffers + creer le background
int	load_things(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->bg.img = mlx_new_image(global->mlx.ptr,
			global->mlx.width, global->mlx.height);
	if (!global->bg.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->bg.addr = mlx_get_data_addr(global->bg.img,
			&(global->bg.bits_per_pixel), &(global->bg.line_len),
			&(global->bg.endian));
	global->bg.w = global->mlx.width;
	global->bg.h = global->mlx.height;
	global->exit.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.exit, &w, &h);
	if (!global->exit.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->exit.addr = mlx_get_data_addr(global->exit.img,
			&(global->exit.bits_per_pixel), &(global->exit.line_len),
			&(global->exit.endian));
	global->exit.w = w;
	global->exit.h = h;
	return (1);
}

//Charge les xpm sol et collectibles dans les buffers
int	load_things2(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->ground.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.ground, &w, &h);
	if (!global->ground.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->ground.addr = mlx_get_data_addr(global->ground.img,
			&(global->ground.bits_per_pixel), &(global->ground.line_len),
			&(global->ground.endian));
	global->ground.w = w;
	global->ground.h = h;
	global->collec.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.collectible, &w, &h);
	if (!global->collec.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->collec.addr = mlx_get_data_addr(global->collec.img,
			&(global->collec.bits_per_pixel),
			&(global->collec.line_len),
			&(global->collec.endian));
	global->collec.w = w;
	global->collec.h = h;
	return (1);
}

//Charge les xpm du personnage (face et dos) dans les buffers
int	load_character1(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->player.front.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.player_front, &w, &h);
	if (!global->player.front.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->player.front.addr = mlx_get_data_addr(global->player.front.img,
			&(global->player.front.bits_per_pixel),
			&(global->player.front.line_len),
			&(global->player.front.endian));
	global->player.front.w = w;
	global->player.front.h = 70;
	global->player.back.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.player_back, &w, &h);
	if (!global->player.back.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->player.back.addr = mlx_get_data_addr(global->player.back.img,
			&(global->player.back.bits_per_pixel),
			&(global->player.back.line_len), &(global->player.back.endian));
	global->player.back.w = w;
	global->player.back.h = 60;
	return (1);
}

//Charge les xpm du personnage (profils) dans les buffers
int	load_character2(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->player.right.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.player_right, &w, &h);
	if (!global->player.right.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->player.right.addr = mlx_get_data_addr(global->player.right.img,
			&(global->player.right.bits_per_pixel),
			&(global->player.right.line_len), &(global->player.right.endian));
	global->player.right.w = w;
	global->player.right.h = 70;
	global->player.left.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.player_left, &w, &h);
	if (!global->player.left.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->player.left.addr = mlx_get_data_addr(global->player.left.img,
			&(global->player.left.bits_per_pixel),
			&(global->player.left.line_len), &(global->player.left.endian));
	global->player.left.w = w;
	global->player.left.h = 70;
	return (1);
}
