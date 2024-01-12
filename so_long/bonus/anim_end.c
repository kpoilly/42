/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:38:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/12 19:19:17 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

void	load_end_img(t_global *global)
{
	int	w;
	int	h;

	w = 137;
	h = 250;
	//mlx_destroy_image(global->mlx.ptr, global->wallin.front2.img); utilises par
	//mlx_destroy_image(global->mlx.ptr, global->wallin.back2.img); anim open exit
	global->wallin.front2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/end_anim1.xpm", &w, &h);
	global->wallin.back2.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/end_anim2.xpm", &w, &h);
	if (!global->wallin.front2.img || !global->wallin.back2.img)
		return (destroy(global), (void)0);
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

void	load_end_bg(t_global *global)
{
	mlx_destroy_image(global->mlx.ptr, global->bg.img);
	global->bg.img = mlx_new_image(global->mlx.ptr, global->mlx.width,
			global->mlx.height);
	if (!global->bg.img)
		return (destroy(global), (void)0);
	global->bg.addr = mlx_get_data_addr(global->bg.img,
			&global->bg.bits_per_pixel, &global->bg.line_len,
			&global->bg.endian);
	global->bg.h = 1080;
	global->bg.w = 1920;
}

void	end_anim(t_global *global)
{
	int		next;
	int		timer;

	load_end_img(global);
	next = 0;
	while (next < 15)
	{
		load_end_bg(global);
		timer = ((long double)(clock() - global->anim) / CLOCKS_PER_SEC) * 1000;
		if (timer >= 200 && !(next % 2))
		{
			global->anim = clock();
			put_img_to_img(global->bg, global->wallin.front2,
				(global->mlx.width /2) -50, (global->mlx.height /2) -130);
			mlx_put_image_to_window(global->mlx.ptr, global->mlx.win, global->bg.img, 0, 0);
			next++;
		}
		else if (timer >= 200 && (next % 2))
		{
			global->anim = clock();
			put_img_to_img(global->bg, global->wallin.back2,
				(global->mlx.width /2) -50, (global->mlx.height /2) -130);
			mlx_put_image_to_window(global->mlx.ptr, global->mlx.win, global->bg.img, 0, 0);
			next++;
		}
	}
}