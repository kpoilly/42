/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:01:06 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/14 17:26:53 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//charge les xpm murs dans les buffers
void	load_walls(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->wallin.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.wallin, &w, &h);
	global->wallin.addr = mlx_get_data_addr(global->wallin.img,
			&(global->wallin.bits_per_pixel), &(global->wallin.line_length),
			&(global->wallin.endian));
	global->wallin.w = w;
	global->wallin.h = h;
	global->wallout.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.wallout, &w, &h);
	global->wallout.addr = mlx_get_data_addr(global->wallout.img,
			&(global->wallout.bits_per_pixel), &(global->wallout.line_length),
			&(global->wallout.endian));
	global->wallout.w = w;
	global->wallout.h = h;
}

//charge le xpm de la sortie dans un buffers + creer le background
void	load_things(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->bg.img = mlx_new_image(global->mlx.ptr,
			global->mlx.width, global->mlx.height);
	global->bg.addr = mlx_get_data_addr(global->bg.img,
			&(global->bg.bits_per_pixel),
			&(global->bg.line_length),
			&(global->bg.endian));
	global->bg.w = global->mlx.width;
	global->bg.h = global->mlx.height;
	global->exit.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.exit, &w, &h);
	global->exit.addr = mlx_get_data_addr(global->exit.img,
			&(global->exit.bits_per_pixel),
			&(global->exit.line_length),
			&(global->exit.endian));
	global->exit.w = w;
	global->exit.h = h;
}

//charge les xpm sol et collectibles dans les buffers
void	load_things2(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->ground.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.ground, &w, &h);
	global->ground.addr = mlx_get_data_addr(global->ground.img,
			&(global->ground.bits_per_pixel), &(global->ground.line_length),
			&(global->ground.endian));
	global->ground.w = w;
	global->ground.h = h;
	global->collec.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.collectible, &w, &h);
	global->collec.addr = mlx_get_data_addr(global->collec.img,
			&(global->collec.bits_per_pixel),
			&(global->collec.line_length),
			&(global->collec.endian));
	global->collec.w = w;
	global->collec.h = h;
}

//charge les xpm du personnage (face et dos) dans les buffers
void	load_character1(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->player_face.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.player_face, &w, &h);
	global->player_face.addr = mlx_get_data_addr(global->player_face.img,
			&(global->player_face.bits_per_pixel),
			&(global->player_face.line_length),
			&(global->player_face.endian));
	global->player_face.w = w;
	global->player_face.h = 70;
	global->player_dos.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.player_dos, &w, &h);
	global->player_dos.addr = mlx_get_data_addr(global->player_dos.img,
			&(global->player_dos.bits_per_pixel),
			&(global->player_dos.line_length),
			&(global->player_dos.endian));
	global->player_dos.w = w;
	global->player_dos.h = 60;
}

//charge les xpm du personnage (profils) dans les buffers
void	load_character2(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->player_droit.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.player_droit, &w, &h);
	global->player_droit.addr = mlx_get_data_addr(global->player_droit.img,
			&(global->player_droit.bits_per_pixel),
			&(global->player_droit.line_length),
			&(global->player_droit.endian));
	global->player_droit.w = w;
	global->player_droit.h = 70;
	global->player_gauche.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.player_gauche, &w, &h);
	global->player_gauche.addr = mlx_get_data_addr(global->player_gauche.img,
			&(global->player_gauche.bits_per_pixel),
			&(global->player_gauche.line_length),
			&(global->player_gauche.endian));
	global->player_gauche.w = w;
	global->player_gauche.h = 70;
}
