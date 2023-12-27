/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:33:20 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/27 12:57:12 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

void	load_ennemy(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->ennemy.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/ennemy.xpm", &w, &h);
	global->ennemy.addr = mlx_get_data_addr(global->ennemy.img,
			&(global->ennemy.bits_per_pixel),
			&(global->ennemy.line_length),
			&(global->ennemy.endian));
	global->ennemy.w = w;
	global->ennemy.h = h;
}

void	spawn_ennemy(t_global *global, int nb_line, int nb_col)
{
	int		x;
	int		y;

	load_ennemy(global);
	srand(time(NULL));
	x = 0;
	y = 0;
	while (global->map[y][x] != '0')
	{
		y = rand() % nb_line + 1;
		x = rand() % nb_col + 1;
	}
	global->map[y][x] = 'G';
}
