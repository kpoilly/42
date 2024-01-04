/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:27:31 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 17:33:44 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//charge les textures de l'ennemi
int	load_anim(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 70;
	global->player.front2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/perso_face2.xpm", &w, &h);
	if (!global->player.front2.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->player.front2.addr = mlx_get_data_addr(global->player.front2.img,
			&(global->player.front2.bits_per_pixel),
			&(global->player.front2.line_len),
			&(global->player.front2.endian));
	global->player.front2.w = w;
	global->player.front2.h = h;
	return (1);
}
