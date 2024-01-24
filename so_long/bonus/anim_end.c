/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:38:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/24 11:32:04 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

void	load_end_img(t_global *global)
{
	int	w;
	int	h;

	w = 598;
	h = 450;
	global->wallin.front2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/end_anim1.xpm", &w, &h);
	global->wallin.back2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/end_anim2.xpm", &w, &h);
	if (!global->wallin.front2.img || !global->wallin.back2.img)
		return (ft_printf("Error.\nMissing texture files.\n"),
			destroy(global), (void)0);
	global->wallin.front2.addr = mlx_get_data_addr(global->wallin.front2.img,
			&global->wallin.front2.bits_per_pixel,
			&global->wallin.front2.line_len, &global->wallin.front2.endian);
	global->wallin.back2.addr = mlx_get_data_addr(global->wallin.back2.img,
			&global->wallin.back2.bits_per_pixel,
			&global->wallin.back2.line_len, &global->wallin.back2.endian);
	global->wallin.front2.h = h;
	global->wallin.front2.w = w;
	global->wallin.back2.h = h;
	global->wallin.back2.w = w;
}

void	load_blackscreen(t_global *global)
{
	mlx_destroy_image(global->mlx.ptr, global->bg.img);
	global->bg.img = mlx_new_image(global->mlx.ptr, global->mlx.width,
			global->mlx.height);
	if (!global->bg.img)
		return (free_anim(global), destroy(global), (void)0);
	global->bg.addr = mlx_get_data_addr(global->bg.img,
			&global->bg.bits_per_pixel, &global->bg.line_len,
			&global->bg.endian);
	global->bg.h = 1080;
	global->bg.w = 1920;
}

int	end_anim(t_global *global)
{
	int		next;
	int		timer;

	next = 0;
	load_end_img(global);
	while (next < 15)
	{
		load_blackscreen(global);
		timer = ((long double)(clock() - global->anim) / CLOCKS_PER_SEC) * 1000;
		if (timer >= 200 && !(next % 2))
		{
			global->anim = clock();
			putimg_blackscreen(global, global->wallin.front2);
			next++;
		}
		else if (timer >= 200 && (next % 2))
		{
			global->anim = clock();
			putimg_blackscreen(global, global->wallin.back2);
			next++;
		}
	}
	return (1);
}
