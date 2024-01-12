/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:38:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/12 18:54:45 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

void	end_anim(t_global *global)
{
	t_img	bg;
	t_img	img1;
	t_img	img2;
	int		next;
	int		timer;

	int h = 250; int w = 137;
	img1.img = mlx_xpm_file_to_image(global->mlx.ptr, "./data/textures/end_anim1.xpm", &w, &h);
	img2.img = mlx_xpm_file_to_image(global->mlx.ptr, "./data/textures/end_anim2.xpm", &w, &h);
	img1.addr = mlx_get_data_addr(img1.img, &img1.bits_per_pixel, &img1.line_len, &img1.endian);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_len, &img2.endian);
	img1.h = 250;img1.w = 137;img2.h = 250;img2.w = 137;

	next = 0;
	while (next < 15)
	{
		timer = ((long double)(clock() - global->anim) / CLOCKS_PER_SEC) * 1000;
		bg.img = mlx_new_image(global->mlx.ptr, global->mlx.width, global->mlx.height);
		bg.addr = mlx_get_data_addr(bg.img, &bg.bits_per_pixel, &bg.line_len, &bg.endian);
		bg.h = 1080;bg.w = 1920;
		if (timer >= 200 && !(next % 2))
		{
			global->anim = clock();
			put_img_to_img(bg, img1, (global->mlx.width /2) -50, (global->mlx.height /2) -130);
			mlx_put_image_to_window(global->mlx.ptr, global->mlx.win, bg.img, 0, 0);
			next++;
		}
		else if (timer >= 200 && (next % 2))
		{
			global->anim = clock();
			put_img_to_img(bg, img2, (global->mlx.width /2) -50, (global->mlx.height /2) -130);
			mlx_put_image_to_window(global->mlx.ptr, global->mlx.win, bg.img, 0, 0);
			next++;
		}
		mlx_destroy_image(global->mlx.ptr, bg.img);
	}
}
