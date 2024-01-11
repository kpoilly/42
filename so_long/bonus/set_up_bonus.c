/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:25:00 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/11 17:41:12 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

void	wallin_random(t_global *global)
{
	int	y;
	int	x;
	int	new;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (x && y && global->map[y + 1] && global->map[y][x + 1])
			{
				if (global->map[y][x] == '1')
				{
					new = 0;
					while (!new)
						new = (rand() % 4);
					global->map[y][x] = new + '0';
				}
			}
			x++;
		}
		y++;
	}
}

//setup des chemins vers les fichiers xpm
static int	set_paths(t_set *set_of_files)
{
	set_of_files->wallout_up = "./data/textures/wallout_updemisol.xpm";
	set_of_files->wallout_down = "./data/textures/wallout_demisol.xpm";
	set_of_files->wallout_left = "./data/textures/wallout_leftdemisol.xpm";
	set_of_files->wallout_right = "./data/textures/wallout_rightdemisol.xpm";
	set_of_files->ground = "./data/textures/ground.xpm";
	set_of_files->exit = "./data/textures/exit.xpm";
	set_of_files->collectible = "./data/textures/frog.xpm";
	set_of_files->player_front = "./data/textures/perso_face_old.xpm";
	set_of_files->player_back = "./data/textures/perso_dos.xpm";
	set_of_files->player_right = "./data/textures/perso_droit.xpm";
	set_of_files->player_left = "./data/textures/perso_gauche.xpm";
	return (1);
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
	set_paths(&(global->set_of_files));
	if ((load_wallin(global) + load_wallin2(global)
			+ load_things(global) + load_things2(global)
			+ load_character1(global) + load_character2(global)
			+ load_walls_updown(global) + load_walls_leftright(global)
			+ load_anim(global) + load_enemy(global)) != 10)
		return (0);
	set_next(global);
	return (1);
}
