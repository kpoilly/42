/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:25:00 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/28 21:06:47 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//setup des chemins vers les fichiers xpm
static int	set_paths(t_set *set_of_files)
{
	set_of_files->wallin = "./data/textures/wallin.xpm";
	set_of_files->wallout = "./data/textures/wallout.xpm";
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
	free(global->bg.img);
	free(global->collec.img);
	free(global->ground.img);
	free(global->exit.img);
	free(global->wallin.img);
	free(global->wallout.img);
	free(global->player.front.img);
	free(global->player.back.img);
	free(global->player.right.img);
	free(global->player.left.img);
	free(global->ennemy.front.img);
	return (0);
}

//setup de la struct qui contient toutes les data
int	set_global(t_global *global, int nb_col, int nb_line)
{
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
	set_paths(&(global->set_of_files));
	if (!load_walls(global)
		|| !load_things(global)
		|| !load_things2(global)
		|| !load_character1(global)
		|| !load_character2(global))
		return (0);
	return (1);
}
