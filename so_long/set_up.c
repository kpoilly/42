/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:25:00 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 11:10:48 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//setup des chemins vers les fichiers xpm
static int	set_paths(t_set *set_of_files)
{
	set_of_files->wallin = "./data/textures/testwallin.xpm";
	set_of_files->wallout_l = "./data/textures/testwallout_l.xpm";
	set_of_files->wallout = "./data/textures/testwallout.xpm";
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
	mlx_destroy_image(global->mlx.ptr, global->bg.img);
	mlx_destroy_image(global->mlx.ptr, global->collec.img);
	mlx_destroy_image(global->mlx.ptr, global->ground.img);
	mlx_destroy_image(global->mlx.ptr, global->exit.img);
	mlx_destroy_image(global->mlx.ptr, global->wallin.img);
	mlx_destroy_image(global->mlx.ptr, global->wallout.img);
	mlx_destroy_image(global->mlx.ptr, global->player.front.img);
	mlx_destroy_image(global->mlx.ptr, global->player.back.img);
	mlx_destroy_image(global->mlx.ptr, global->player.right.img);
	mlx_destroy_image(global->mlx.ptr, global->player.left.img);
	mlx_destroy_image(global->mlx.ptr, global->ennemy.front.img);
	return (0);
}

//setup de la struct qui contient toutes les data
int	set_global(t_global *global, int nb_col, int nb_line)
{
	global->last = clock();
	global->mlx.ptr = mlx_init();
	if (!global->mlx.ptr)
		return (0);
	global->mlx.width = nb_col * 50;
	global->mlx.height = nb_line * 50;
	global->mlx.win = mlx_new_window(global->mlx.ptr, global->mlx.width,
			global->mlx.height, "The Grenouille Collector");
	if (!global->mlx.win)
		return (0);
	global->moves = 0;
	global->player.chara = 'P';
	set_paths(&(global->set_of_files));
	if (!load_walls(global)
		|| !load_things(global)
		|| !load_things2(global)
		|| !load_character1(global)
		|| !load_character2(global)
		|| !load_others(global))
		return (0);
	global->player.front.next = &global->player.back;
	global->player.back.next = &global->player.front;
	return (1);
}
