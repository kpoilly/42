/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:25:00 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 17:20:12 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//setup des chemins vers les fichiers xpm
static int	set_paths(t_set *set_of_files)
{
	set_of_files->wallin = "./data/textures/testwallin.xpm";
	set_of_files->wallout_up = "./data/textures/wallout.xpm";
	set_of_files->wallout_down = "./data/textures/wallout.xpm";
	set_of_files->wallout_left = "./data/textures/testwallout_l.xpm";
	set_of_files->wallout_right = "./data/textures/testwallout.xpm";
	set_of_files->ground = "./data/textures/ground2.xpm";
	set_of_files->exit = "./data/textures/exit.xpm";
	set_of_files->collectible = "./data/textures/frog.xpm";
	set_of_files->player_front = "./data/textures/perso_face.xpm";
	set_of_files->player_back = "./data/textures/perso_dos.xpm";
	set_of_files->player_right = "./data/textures/perso_droit.xpm";
	set_of_files->player_left = "./data/textures/perso_gauche.xpm";
	return (1);
}

int	free_images(t_global *global)
{
	if (global->bg.img)
		mlx_destroy_image(global->mlx.ptr, global->bg.img);
	if (global->collec.img)
		mlx_destroy_image(global->mlx.ptr, global->collec.img);
	if (global->ground.img)
		mlx_destroy_image(global->mlx.ptr, global->ground.img);
	if (global->exit.img)
		mlx_destroy_image(global->mlx.ptr, global->exit.img);
	if (global->wallin.img)
		mlx_destroy_image(global->mlx.ptr, global->wallin.img);
	if (global->wallout.front.img)
		mlx_destroy_image(global->mlx.ptr, global->wallout.front.img);
	if (global->wallout.back.img)
		mlx_destroy_image(global->mlx.ptr, global->wallout.back.img);
	if (global->wallout.right.img)
		mlx_destroy_image(global->mlx.ptr, global->wallout.right.img);
	if (global->wallout.left.img)
		mlx_destroy_image(global->mlx.ptr, global->wallout.left.img);
	if (global->player.front.img)
		mlx_destroy_image(global->mlx.ptr, global->player.front.img);
	if (global->player.back.img)
		mlx_destroy_image(global->mlx.ptr, global->player.back.img);
	if (global->player.right.img)
		mlx_destroy_image(global->mlx.ptr, global->player.right.img);
	if (global->player.left.img)
		mlx_destroy_image(global->mlx.ptr, global->player.left.img);
	return (0);
}

//setup de la struct qui contient toutes les data
int	set_global(t_global *global, int nb_col, int nb_line)
{
	global->last = clock();
	global->anim = clock();
	global->mlx.ptr = mlx_init();
	if (!global->mlx.ptr)
		return (ft_printf("Error.\n(mlx init)\n"), 0);
	global->mlx.width = nb_col * 50;
	global->mlx.height = nb_line * 50;
	global->mlx.win = mlx_new_window(global->mlx.ptr, global->mlx.width,
			global->mlx.height, "The Grenouille Collector");
	if (!global->mlx.win)
		return (ft_printf("Error.\n(mlx win setup)\n"), 0);
	global->moves = 0;
	global->player.chara = 'P';
	global->last_gobdir = 'W';
	set_paths(&(global->set_of_files));
	if (!load_walls(global)
		|| !load_things(global)
		|| !load_things2(global)
		|| !load_character1(global)
		|| !load_character2(global)
		|| !load_walls_updown(global)
		|| !load_walls_leftright(global))
		return (0);
	set_next(global);
	return (1);
}
