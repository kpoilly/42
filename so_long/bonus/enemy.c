/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:33:20 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 12:26:36 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//charge les textures de l'ennemi
void	load_enemy(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->enemy.front.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/enemy_face.xpm", &w, &h);
	if (!global->enemy.front.img)
		return (ft_printf("Error.\nMissing Texture files.\n"),
			(void)destroy(global));
	global->enemy.front.addr = mlx_get_data_addr(global->enemy.front.img,
			&(global->enemy.front.bits_per_pixel),
			&(global->enemy.front.line_len),
			&(global->enemy.front.endian));
	global->enemy.front.w = w;
	global->enemy.front.h = h;
	global->enemy.chara = 'G';
}

//Fait apparaitre l'ennemi aleatoirement sur la map
void	spawn_enemy(t_global *global, int nb_line, int nb_col)
{
	int		x;
	int		y;

	load_enemy(global);
	srand(time(NULL));
	x = 0;
	y = 0;
	while (global->map[y][x] != '0')
	{
		y = rand() % nb_line;
		x = rand() % nb_col;
	}
	global->map[y][x] = global->enemy.chara;
}
