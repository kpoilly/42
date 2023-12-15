/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:25:00 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/15 10:31:28 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//setup des chemins vers les fichiers xpm
static int	set_paths(t_set *set_of_files)
{
	set_of_files->wallin = "./data/textures/wallin.xpm";
	set_of_files->wallout = "./data/textures/wallout.xpm";
	set_of_files->ground = "./data/textures/ground.xpm";
	set_of_files->exit = "./data/textures/exit.xpm";
	set_of_files->collectible = "./data/textures/frog.xpm";
	set_of_files->player_face = "./data/textures/perso_face.xpm";
	set_of_files->player_dos = "./data/textures/perso_dos.xpm";
	set_of_files->player_droit = "./data/textures/perso_droit.xpm";
	set_of_files->player_gauche = "./data/textures/perso_gauche.xpm";
	return (1);
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
			global->mlx.height, "Catch the Frogs !");
	set_paths(&(global->set_of_files));
	load_walls(global);
	load_things(global);
	load_things2(global);
	load_character1(global);
	load_character2(global);
	return (1);
}
