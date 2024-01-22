/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:25:00 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/22 11:44:24 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//genere un nombre aleatoire (plus ou moins)
int	ft_random(long seed)
{
	int	res;

	seed *= seed;
	seed /= 10;
	res = seed % 10;
	seed /= 10;
	res += (seed % 10) * 10;
	if (res < 0)
		res *= -1;
	if ((res % 4) != 0)
		return (res % 4);
	if (res < 10)
		res += 10;
	if (!res)
		res = 42;
	if (res == 60)
		return (3);
	return (ft_random(res));
}

//rajoute de l'aleatoire dans les murs interieurs
void	wallin_random(t_global *global)
{
	int		y;
	int		x;
	long	seed;
	int		add_seed;

	seed = (long)&x;
	add_seed = 0;
	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (x && y && global->map[y + 1] && global->map[y][x + 1])
				if (global->map[y][x] == '1')
					global->map[y][x] = ft_random(seed + add_seed) + '0';
			x++;
			add_seed++;
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
	set_of_files->exit = "./data/textures/exit09.xpm";
	set_of_files->collectible = "./data/textures/frog.xpm";
	set_of_files->player_front = "./data/textures/perso_face.xpm";
	set_of_files->player_back = "./data/textures/perso_dos.xpm";
	set_of_files->player_right = "./data/textures/perso_droit.xpm";
	set_of_files->player_left = "./data/textures/perso_gauche.xpm";
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
	if (global->mlx.height > 1080 || global->mlx.width > 1920)
		return (ft_printf("Error.\nMap is too big.\n"), 0);
	global->mlx.win = mlx_new_window(global->mlx.ptr, global->mlx.width,
			global->mlx.height, "The Grenouille Collector");
	if (!global->mlx.win)
		return (ft_printf("Error.\n(mlx win setup)\n"), 0);
	global->moves = 0;
	global->player.chara = 'P';
	set_paths(&(global->set_of_files));
	if ((load_wallin(global) + load_wallin2(global)
			+ load_things(global)
			+ load_things2(global) + load_character1(global)
			+ load_character2(global) + load_walls_updown(global)
			+ load_walls_leftright(global)) != 8)
		return (0);
	return (1);
}
