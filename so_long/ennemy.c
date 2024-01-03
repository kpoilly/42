/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:33:20 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/03 15:28:35 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//charge les textures de l'ennemi
void	load_ennemy(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	global->ennemy.front.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/ennemy.xpm", &w, &h);
	if (!global->ennemy.front.img)
		return (ft_printf("Error.\nMissing Texture files.\n"),
			(void)destroy(global));
	global->ennemy.front.addr = mlx_get_data_addr(global->ennemy.front.img,
			&(global->ennemy.front.bits_per_pixel),
			&(global->ennemy.front.line_len),
			&(global->ennemy.front.endian));
	global->ennemy.front.w = w;
	global->ennemy.front.h = h;
	global->ennemy.chara = 'G';
}

//Fait apparaitre l'ennemi aleatoirement sur la map
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
		y = rand() % nb_line;
		x = rand() % nb_col;
	}
	global->map[y][x] = 'G';
}
