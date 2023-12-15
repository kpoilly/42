/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:18:07 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/15 15:23:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//check quelle image il doit afficher
static void	check_item(t_global *global, t_img state, int x, int y)
{
	if (!(!y || !x || !global->map[y + 1] || !global->map[y][x + 1]))
		put_img_to_img(global->bg, global->ground, x * 50, y * 50);
	if (global->map[y][x] == '1')
	{			
		if (!y || !x || !global->map[y + 1] || !global->map[y][x + 1])
			put_img_to_img(global->bg, global->wallout, x * 50, y * 50);
		else
			put_img_to_img(global->bg, global->wallin, x * 50 - 10,
				y * 50 - 10);
	}
	else if (global->map[y][x] == 'P')
		put_img_to_img(global->bg, state, x * 50, (y * 50) - 20);
	else if (global->map[y][x] == 'C')
		put_img_to_img(global->bg, global->collec, x * 50, y * 50);
	else if (global->map[y][x] == 'E')
		put_img_to_img(global->bg, global->exit, x * 50, y * 50);
}

//Parcours la char**map et affiche les images aux bons endroits
void	render_map(t_global *global, t_img state)
{
	int	x;
	int	y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			check_item(global, state, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
		global->bg.img, 0, 0);
	ft_printf("Mouvements : %d\n", global->moves);
	mlx_string_put(global->mlx.ptr, global->mlx.win, global->mlx.width - 150,
		global->mlx.height - 22, (int)0x00CCFFFF, "Mouvements : ");
	mlx_string_put(global->mlx.ptr, global->mlx.win, global->mlx.width - 70,
		global->mlx.height - 22, (int)0x00CCFFFF, ft_itoa(global->moves));
}
