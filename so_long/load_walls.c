/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:07:08 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/10 19:41:38 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

int	load_walls_updown(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->wallout.front.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.wallout_up, &w, &h);
	global->wallout.back.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.wallout_down, &w, &h);
	if (!global->wallout.front.img || !global->wallout.back.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->wallout.front.addr = mlx_get_data_addr(global->wallout.front.img,
			&(global->wallout.front.bits_per_pixel),
			&(global->wallout.front.line_len), &(global->wallout.front.endian));
	global->wallout.front.w = w;
	global->wallout.front.h = h;
	global->wallout.back.addr = mlx_get_data_addr(global->wallout.back.img,
			&(global->wallout.back.bits_per_pixel),
			&(global->wallout.back.line_len), &(global->wallout.back.endian));
	global->wallout.back.w = w;
	global->wallout.back.h = h;
	return (1);
}

int	load_walls_leftright(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 85;
	global->wallout.left.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.wallout_left, &w, &h);
	global->wallout.right.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.wallout_right, &w, &h);
	if (!global->wallout.left.img || !global->wallout.right.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->wallout.left.addr = mlx_get_data_addr(global->wallout.left.img,
			&(global->wallout.left.bits_per_pixel),
			&(global->wallout.left.line_len), &(global->wallout.left.endian));
	global->wallout.left.w = w;
	global->wallout.left.h = h;
	global->wallout.right.addr = mlx_get_data_addr(global->wallout.right.img,
			&(global->wallout.right.bits_per_pixel),
			&(global->wallout.right.line_len), &(global->wallout.right.endian));
	global->wallout.right.w = w;
	global->wallout.right.h = h;
	return (1);
}

//Charge les xpm murs dans les buffers
int	load_wallin(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->wallin.front.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/wallin.xpm", &w, &h);
	global->wallin.back.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/wallin2.xpm", &w, &h);
	if (!global->wallin.front.img || !global->wallin.back.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->wallin.front.addr = mlx_get_data_addr(global->wallin.front.img,
			&(global->wallin.front.bits_per_pixel),
			&(global->wallin.front.line_len),
			&(global->wallin.front.endian));
	global->wallin.front.w = w;
	global->wallin.front.h = h;
	global->wallin.back.addr = mlx_get_data_addr(global->wallin.back.img,
			&(global->wallin.back.bits_per_pixel),
			&(global->wallin.back.line_len),
			&(global->wallin.back.endian));
	global->wallin.back.w = w;
	global->wallin.back.h = h;
	return (1);
}

//Charge les xpm murs dans les buffers
int	load_wallin2(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->wallin.left.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/wallin3.xpm", &w, &h);
	if (!global->wallin.left.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->wallin.left.addr = mlx_get_data_addr(global->wallin.left.img,
			&(global->wallin.left.bits_per_pixel),
			&(global->wallin.left.line_len),
			&(global->wallin.left.endian));
	global->wallin.left.w = w;
	global->wallin.left.h = h;
	return (1);
}
