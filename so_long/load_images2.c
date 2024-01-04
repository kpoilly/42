/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:26:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 11:39:28 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

int	load_others(t_global *global)
{
	int	w;
	int	h;

	w = 50;
	h = 85;
	global->wallout_l.img = mlx_xpm_file_to_image(global->mlx.ptr,
			global->set_of_files.wallout_l, &w, &h);
	if (!global->wallout_l.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->wallout_l.addr = mlx_get_data_addr(global->wallout_l.img,
			&(global->wallout_l.bits_per_pixel), &(global->wallout_l.line_len),
			&(global->wallout_l.endian));
	global->wallout_l.w = w;
	global->wallout_l.h = h;
	return (1);
}
