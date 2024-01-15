/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:27:31 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/15 09:33:54 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//charge les textures des anim face et back
int	load_faceback(t_global *global, t_ent *entity)
{
	int	w;
	int	h;

	w = 50;
	h = 70;
	entity->front2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			entity->paths.front2, &w, &h);
	entity->back2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			entity->paths.back2, &w, &h);
	if (!entity->front2.img || !entity->back2.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	entity->front2.addr = mlx_get_data_addr(entity->front2.img,
			&(entity->front2.bits_per_pixel),
			&(entity->front2.line_len),
			&(entity->front2.endian));
	entity->front2.w = w;
	entity->front2.h = h;
	entity->back2.addr = mlx_get_data_addr(entity->back2.img,
			&(entity->back2.bits_per_pixel),
			&(entity->back2.line_len), &(entity->back2.endian));
	entity->back2.w = w;
	entity->back2.h = h;
	return (1);
}

//charge les textures de l'anim right et left
int	load_rightleft(t_global *global, t_ent *entity)
{
	int	w;
	int	h;

	w = 50;
	h = 70;
	entity->right2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			entity->paths.right2, &w, &h);
	entity->left2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			entity->paths.left2, &w, &h);
	if (!entity->right2.img || !entity->left2.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	entity->right2.addr = mlx_get_data_addr(entity->right2.img,
			&(entity->right2.bits_per_pixel),
			&(entity->right2.line_len),
			&(entity->right2.endian));
	entity->right2.w = w;
	entity->right2.h = h;
	entity->left2.addr = mlx_get_data_addr(entity->left2.img,
			&(entity->left2.bits_per_pixel),
			&(entity->left2.line_len), &(entity->left2.endian));
	entity->left2.w = w;
	entity->left2.h = h;
	return (1);
}

int	load_anim(t_global *global)
{
	set_paths_anim(global);
	if (load_faceback(global, &global->player)
		+ load_rightleft(global, &global->player) != 2)
		return (0);
	return (1);
}
