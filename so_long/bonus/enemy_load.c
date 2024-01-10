/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:41:59 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/10 11:23:24 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

int	load_enemy_front(t_global *global)
{
	int	w;
	int	h;

	global->enemy.chara = 'G';
	w = 65;
	h = 90;
	global->enemy.front.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/enemy_face.xpm", &w, &h);
	global->enemy.front2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/enemy_face2.xpm", &w, &h);
	if (!global->enemy.front.img || !global->enemy.front2.img)
		return (ft_printf("Error.\nMissing Texture files.\n"),
			destroy(global), 0);
	global->enemy.front.addr = mlx_get_data_addr(global->enemy.front.img,
			&(global->enemy.front.bits_per_pixel),
			&(global->enemy.front.line_len), &(global->enemy.front.endian));
	global->enemy.front.w = w;
	global->enemy.front.h = h;
	global->enemy.front2.addr = mlx_get_data_addr(global->enemy.front2.img,
			&(global->enemy.front2.bits_per_pixel),
			&(global->enemy.front2.line_len), &(global->enemy.front2.endian));
	global->enemy.front2.w = w;
	global->enemy.front2.h = h;
	return (1);
}

int	load_enemy_back(t_global *global)
{
	int	w;
	int	h;

	global->enemy.chara = 'G';
	w = 65;
	h = 90;
	global->enemy.back.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/enemy_back.xpm", &w, &h);
	global->enemy.back2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/enemy_back2.xpm", &w, &h);
	if (!global->enemy.back.img || !global->enemy.back2.img)
		return (ft_printf("Error.\nMissing Texture files.\n"),
			destroy(global), 0);
	global->enemy.back.addr = mlx_get_data_addr(global->enemy.back.img,
			&(global->enemy.back.bits_per_pixel),
			&(global->enemy.back.line_len), &(global->enemy.back.endian));
	global->enemy.back.w = w;
	global->enemy.back.h = h;
	global->enemy.back2.addr = mlx_get_data_addr(global->enemy.back2.img,
			&(global->enemy.back2.bits_per_pixel),
			&(global->enemy.back2.line_len), &(global->enemy.back2.endian));
	global->enemy.back2.w = w;
	global->enemy.back2.h = h;
	return (1);
}

int	load_enemy_left(t_global *global)
{
	int	w;
	int	h;

	global->enemy.chara = 'G';
	w = 65;
	h = 90;
	global->enemy.left.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/enemy_left.xpm", &w, &h);
	global->enemy.left2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/enemy_left2.xpm", &w, &h);
	if (!global->enemy.left.img || !global->enemy.left2.img)
		return (ft_printf("Error.\nMissing Texture files.\n"),
			destroy(global), 0);
	global->enemy.left.addr = mlx_get_data_addr(global->enemy.left.img,
			&(global->enemy.left.bits_per_pixel),
			&(global->enemy.left.line_len), &(global->enemy.left.endian));
	global->enemy.left.w = w;
	global->enemy.left.h = h;
	global->enemy.left2.addr = mlx_get_data_addr(global->enemy.left2.img,
			&(global->enemy.left2.bits_per_pixel),
			&(global->enemy.left2.line_len), &(global->enemy.left2.endian));
	global->enemy.left2.w = w;
	global->enemy.left2.h = h;
	return (1);
}

int	load_enemy_right(t_global *global)
{
	int	w;
	int	h;

	global->enemy.chara = 'G';
	w = 65;
	h = 90;
	global->enemy.right.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/enemy_right.xpm", &w, &h);
	global->enemy.right2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/enemy_right2.xpm", &w, &h);
	if (!global->enemy.right.img || !global->enemy.right2.img)
		return (ft_printf("Error.\nMissing Texture files.\n"),
			destroy(global), 0);
	global->enemy.right.addr = mlx_get_data_addr(global->enemy.right.img,
			&(global->enemy.right.bits_per_pixel),
			&(global->enemy.right.line_len), &(global->enemy.right.endian));
	global->enemy.right.w = w;
	global->enemy.right.h = h;
	global->enemy.right2.addr = mlx_get_data_addr(global->enemy.right2.img,
			&(global->enemy.right2.bits_per_pixel),
			&(global->enemy.right2.line_len), &(global->enemy.right2.endian));
	global->enemy.right2.w = w;
	global->enemy.right2.h = h;
	return (1);
}

//charge les textures de l'ennemi
int	load_enemy(t_global *global)
{
	int	check;

	check = 0;
	check += load_enemy_front(global);
	check += load_enemy_back(global);
	check += load_enemy_left(global);
	check += load_enemy_right(global);
	return (check == 4);
}
