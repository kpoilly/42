/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:33:20 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/28 14:18:41 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

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
			(void)destroy(0, global));
	global->ennemy.front.addr = mlx_get_data_addr(global->ennemy.front.img,
			&(global->ennemy.front.bits_per_pixel),
			&(global->ennemy.front.line_length),
			&(global->ennemy.front.endian));
	global->ennemy.front.w = w;
	global->ennemy.front.h = h;
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
		y = rand() % nb_line;
		x = rand() % nb_col;
	}
	global->map[y][x] = 'G';
}
